#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/json.hpp>

#include <openssl/err.h>
#include <openssl/ssl.h>

#include <algorithm>
#include <chrono>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <thread>

namespace net       = boost::asio;
namespace beast     = boost::beast;
namespace websocket = beast::websocket;
namespace ssl       = net::ssl;
namespace json      = boost::json;
using tcp = net::ip::tcp;
using namespace std::chrono_literals;

// 这是一条“业务数据”，与网络连接的类型无关。
struct MiniTicker {
    std::string symbol;
    std::string last_price;    // c: 最新成交价（行情统计中的收盘价）
    std::string high_24h;      // h: 滚动 24 小时最高价
    std::string low_24h;       // l: 滚动 24 小时最低价
    std::string volume_24h;    // v: 滚动 24 小时基础资产成交量
    std::int64_t event_time_ms; // E: 交易所事件时间（Unix 毫秒）
};

// Boost.JSON 的字符串不是 std::string，这里显式复制成标准字符串。
std::string as_std_string(const json::value& value) {
    const auto& s = value.as_string();
    return std::string(s.data(), s.size());
}

// 解析单条 miniTicker JSON。不是 miniTicker 的消息返回 nullopt。
// 缺失字段或格式不符会抛异常，由接收循环记录并跳过。
std::optional<MiniTicker> parse_mini_ticker(const std::string& payload) {
    const json::value message = json::parse(payload);
    const auto& obj = message.as_object();
    const auto* event = obj.if_contains("e");
    if (event == nullptr || !event->is_string() || event->as_string() != "24hrMiniTicker") {
        return std::nullopt;
    }
    return MiniTicker{
        .symbol        = as_std_string(obj.at("s")),
        .last_price    = as_std_string(obj.at("c")),
        .high_24h      = as_std_string(obj.at("h")),
        .low_24h       = as_std_string(obj.at("l")),
        .volume_24h    = as_std_string(obj.at("v")),
        .event_time_ms = obj.at("E").as_int64()
    };
}

void print_ticker(const MiniTicker& t) {
    std::cout << "[" << t.symbol << "] "
              << "last_price=" << t.last_price << " | "
              << "24h high=" << t.high_24h << " | "
              << "24h low=" << t.low_24h << " | "
              << "24h volume=" << t.volume_24h << " | "
              << "event_ms=" << t.event_time_ms << '\n';
}

std::string normalize_symbol(std::string symbol) {
    if (symbol.empty() || symbol.size() > 30) {
        throw std::invalid_argument("交易对长度不合法，例如 BTCUSDT");
    }
    for (char& c : symbol) {
        const auto ch = static_cast<unsigned char>(c);
        if (!std::isalnum(ch) || ch > 127) {
            throw std::invalid_argument("交易对只能包含 ASCII 字母和数字，例如 BTCUSDT");
        }
        c = static_cast<char>(std::tolower(ch));
    }
    return symbol;
}

// 从建立连接开始，持续读取直到连接断开。默认现货主网，公共行情无需 API Key。
void connect_and_receive(const std::string& symbol) {
    const std::string host = "stream.binance.com";
    const std::string port = "9443";  // 如所在网络阻断此端口，可改为 "443"
    const std::string target = "/ws/" + symbol + "@miniTicker";

    net::io_context ioc;
    ssl::context tls{ssl::context::tls_client};

    // Windows + OpenSSL 通常需要显式的 CA 证书包：项目目录中的 cacert.pem。
    // Linux / macOS 若已配置系统 OpenSSL CA 路径，可以不提供文件。
    if (std::filesystem::exists("cacert.pem")) {
        tls.load_verify_file("cacert.pem");
    } else {
        tls.set_default_verify_paths();
    }
    tls.set_verify_mode(ssl::verify_peer);

    tcp::resolver resolver{ioc};
    websocket::stream<beast::ssl_stream<beast::tcp_stream>> ws{net::make_strand(ioc), tls};

    const auto addresses = resolver.resolve(host, port);
    beast::get_lowest_layer(ws).expires_after(10s);
    beast::get_lowest_layer(ws).connect(addresses);  // ① TCP

    // SNI: TLS 握手时告诉服务器要访问哪个域名。
    if (SSL_set_tlsext_host_name(ws.next_layer().native_handle(), host.c_str()) != 1) {
        const auto error = static_cast<int>(::ERR_get_error());
        throw beast::system_error(error, net::error::get_ssl_category());
    }
    // 校验证书域名，不能仅依赖 verify_peer。
    ws.next_layer().set_verify_callback(ssl::host_name_verification(host));
    beast::get_lowest_layer(ws).expires_after(10s);
    ws.next_layer().handshake(ssl::stream_base::client); // ② TLS

    // 后续 WebSocket 自己管理超时；服务端 Ping 会被 Beast 自动 Pong 应答。
    beast::get_lowest_layer(ws).expires_never();
    ws.set_option(websocket::stream_base::timeout::suggested(beast::role_type::client));
    ws.handshake(host + ":" + port, target);          // ③ WebSocket Upgrade

    std::cout << "[connected] wss://" << host << ":" << port << target << '\n';

    while (true) {
        beast::flat_buffer buffer;
        beast::error_code ec;
        ws.read(buffer, ec);                            // ④ 阻塞等待一条完整消息
        if (ec == websocket::error::closed) {
            std::cerr << "[disconnected] 服务器正常关闭连接\n";
            return;
        }
        if (ec) {
            throw beast::system_error(ec);
        }

        // buffer 中的字节仅在本次循环使用；转换成字符串便于 JSON 解析。
        const std::string payload = beast::buffers_to_string(buffer.data());
        try {
            if (const auto ticker = parse_mini_ticker(payload)) { // ⑤ JSON -> 业务结构体
                print_ticker(*ticker);                 // ⑥ 输出；将来可替换为策略/存储
            } else {
                std::cerr << "[info] 非 miniTicker 消息：" << payload << '\n';
            }
        } catch (const std::exception& e) {
            std::cerr << "[parse error] " << e.what() << '\n';
        }
    }
}

void run_demo() {
    constexpr auto example = R"({
        "e":"24hrMiniTicker",
        "E":1760000000000,
        "s":"BTCUSDT",
        "c":"65000.12",
        "o":"64000.00",
        "h":"66000.00",
        "l":"63500.00",
        "v":"1234.5678",
        "q":"80000000.00"
    })";
    const auto ticker = parse_mini_ticker(example);
    if (!ticker) {
        throw std::runtime_error("示例行情解析失败");
    }
    std::cout << "[demo] 以下是离线模拟数据，不是实时价格\n";
    print_ticker(*ticker);
}

int main(int argc, char* argv[]) {
    try {
        if (argc >= 2 && std::string(argv[1]) == "--demo") {
            run_demo();
            return 0;
        }
        if (argc > 2) {
            std::cerr << "用法: binance_ws [BTCUSDT]  或  binance_ws --demo\n";
            return 2;
        }

        const auto symbol = normalize_symbol(argc == 2 ? argv[1] : "BTCUSDT");
        std::cout << "Binance Spot miniTicker | symbol=" << symbol
                  << " | 按 Ctrl+C 退出\n";

        auto retry_delay = 1s;
        while (true) {
            try {
                connect_and_receive(symbol);
            } catch (const std::exception& e) {
                std::cerr << "[network error] " << e.what() << '\n';
            }
            std::cerr << "[reconnect] " << retry_delay.count() << " 秒后重试\n";
            std::this_thread::sleep_for(retry_delay);
            retry_delay = std::min(retry_delay * 2, 30s);
        }
    } catch (const std::exception& e) {
        std::cerr << "[fatal] " << e.what() << '\n';
        return 1;
    }
}
