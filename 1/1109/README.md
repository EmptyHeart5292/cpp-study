# Binance 现货 WebSocket 实时行情：C++20 入门项目

> 最小可用的**公开行情订阅客户端**，不是交易机器人。默认订阅 Binance **现货** BTCUSDT 的 `@miniTicker`。无需登录、无需 API Key、不会下单。
>
> 注意：本仓库演示的是 **Spot** 现货；USDT 本位合约是另一个 API 域名与消息体系。`@miniTicker` 是每约 1000 ms 更新的滚动 24 小时统计，**不是**逐笔成交，也不是 K 线，更不是 24 小时固定 UTC 日数据。

## 1. 文件结构

```text
binance-ws-cpp20/
├── CMakeLists.txt       # 构建规则，强制 C++20
├── vcpkg.json           # 声明 Boost.Beast / Boost.JSON / OpenSSL 依赖
├── src/
│   └── main.cpp         # 完整可运行代码
├── README.md            # 当前教程
└── .gitignore
```

## 2. 选择这些技术的原因

| 组件 | 负责什么 | 为什么用它 |
| --- | --- | --- |
| C++20 | 类型、安全性与业务逻辑 | 接近未来要写的 C++ 行情/策略系统；代码使用 C++20 的指定成员初始化（`.field = value`） |
| Boost.Asio | DNS、TCP、事件执行上下文 | 跨平台网络底座，后续能学异步与协程 |
| Boost.Beast | WebSocket 协议 | 避免自己实现握手、帧、Ping/Pong |
| OpenSSL | TLS 加密与证书校验 | `wss://` 所需，不能跳过验证 |
| Boost.JSON | 解析 JSON 文本 | 不必手写字符串切割；学习结构化解码 |
| CMake | 编译与链接 | 不必手工维护漫长的编译选项 |
| vcpkg | 管理第三方依赖 | 对 Windows 初学者较实用，与 CMake 配合良好 |

**为什么暂不使用 `co_await`：** C++20 协程更适合高并发，但会增加理解连接生命周期、异步回调、取消操作的难度。先用同步阻塞接收跑通端到端的数据链路，再升级异步更稳妥。

## 3. Windows：从零到运行（推荐）

假设你使用的是 Windows 10/11 x64。

### 第一步：安装工具

1. 安装 **Visual Studio 2022 Community** 或对应版本的 **Build Tools for Visual Studio**。勾选 **使用 C++ 的桌面开发 (Desktop development with C++)**，并确保包括 **MSVC x64 工具集**、**CMake**、**Ninja**、**Windows SDK**。
2. 安装 Git（用于获取 vcpkg）。
3. 在开始菜单打开 **Developer PowerShell for VS** 或 **x64 Native Tools Command Prompt for VS**，检查：

```powershell
cl
cmake --version
ninja --version
git --version
```

`cl` 是 MSVC 编译器，**必须在开发者命令行里可见**。如果打开普通 PowerShell，可能看不到它。

### 第二步：安装 vcpkg（只需一次）

以下示例放在 `C:\dev\vcpkg`，可根据你实际目录替换。

```powershell
New-Item -ItemType Directory -Force C:\dev | Out-Null
cd C:\dev
git clone https://github.com/microsoft/vcpkg.git
cd C:\dev\vcpkg
.\bootstrap-vcpkg.bat
```

### 第三步：解压并进入项目目录

把下载的压缩包解压到 `C:\dev\binance-ws-cpp20`，然后在**开发者 PowerShell** 执行：

```powershell
cd C:\dev\binance-ws-cpp20
```

### 第四步：准备 CA 根证书包（Windows 强烈建议）

本示例使用 OpenSSL，而不是浏览器的 TLS 连接。为了真正校验 Binance 的证书链，下载 curl 项目维护的 CA 根证书包到项目根目录：

```powershell
Invoke-WebRequest https://curl.se/ca/cacert.pem -OutFile cacert.pem
```

证书包公开可获得，不是密钥。代码优先读取当前工作目录下的 `cacert.pem`；没有时尝试 OpenSSL 的默认 CA 路径。**如果证书校验失败，不要修改代码为 `verify_none`**。

### 第五步：生成并编译

`CMAKE_TOOLCHAIN_FILE` 务必指向你实际安装的 vcpkg 路径。

```powershell
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --parallel 4
```

第一次 CMake 配置会根据 `vcpkg.json` 下载并编译依赖，耗时可能比较久。依赖装好后再构建会快得多。若内存有限，可把 `--parallel 4` 改为 `--parallel 2`。

### 第六步：先离线检查，再实时运行

```powershell
# 不联网，检查 JSON 解析是否工作
.\build\binance_ws.exe --demo

# 实时订阅 BTCUSDT（约每秒一条）
.\build\binance_ws.exe

# 改成 ETHUSDT；不要使用 ETH/USDT 斜杠
.\build\binance_ws.exe ETHUSDT
```

**停下程序：** Ctrl+C。源码中没有安装自定义 SIGINT 处理器，因此一般由操作系统直接终止进程；程序不能保证执行 WebSocket 优雅关闭。这是入门版的限制。

`--demo` 输出的是**虚构示例数据**，绝不代表实时价格。

### 输出格式

```text
[connected] wss://stream.binance.com:9443/ws/btcusdt@miniTicker
[BTCUSDT] last_price=<交易所报价> | 24h high=<...> | 24h low=<...> | 24h volume=<...> | event_ms=<...>
```

注意：代码未假定报价单位永远是 USDT。你传入 `ETHBTC` 时，价格的报价资产是 BTC；字段 `v` 对应基础资产的 24 小时成交量。

## 4. 程序完整工作链路

```text
main()
  │
  ├─ --demo → parse_mini_ticker(固定 JSON) → print_ticker()
  │
  └─ normalize_symbol(例如 BTCUSDT → btcusdt)
         │
         └─ connect_and_receive()
                │
                ├─ resolver.resolve("stream.binance.com", "9443")   DNS
                ├─ TCP connect                                  TCP
                ├─ SNI + CA 验证 + TLS handshake                 TLS
                ├─ ws.handshake("...", "/ws/btcusdt@miniTicker") WebSocket
                │
                └─ while (true)
                     ├─ ws.read(buffer)    收到一个完整的 WebSocket 消息
                     ├─ parse JSON        JSON → MiniTicker 结构体
                     └─ print_ticker      输出行情；以后可接入策略

连接断开/异常 → 捕获异常 → 1、2、4...30 秒退避 → 重连
```

### 为什么有三次“连接”动作？

- **TCP connect**：建立可靠的字节传输通道。
- **TLS handshake**：在 TCP 之上加密并验证服务器证书（这就是 `wss` 的 `s`）。
- **WebSocket handshake**：在已加密的连接上，把 HTTP 协议升级成适合双向长期传输的 WebSocket。

Beast 的 `ws.read(buffer)` 会等到**完整 WebSocket 消息**才返回。它还能在接收循环内自动回复服务端的 Ping 帧，所以**不用手动发送业务 JSON 做心跳**。

### 为什么用 `MiniTicker` 结构体？

网络消息属于**外部格式**，策略应读取**内部类型**。以后即使换交易所，也可以把它们转换成统一的 `MarketData` 数据结构，降低策略对交易所 JSON 字段名的耦合。

```cpp
struct MiniTicker {
    std::string symbol;
    std::string last_price;
    std::string high_24h;
    std::string low_24h;
    std::string volume_24h;
    std::int64_t event_time_ms;
};
```

价格保留**字符串**：Binance 用字符串表达小数，以避免 JSON 浮点数造成的精度问题。实际计算时应使用**固定精度十进制**或**整数 tick 单位**，不要直接把资金、价格、订单量存成 `double` 就进入实盘下单逻辑。

### 学懂哪些 C++ 语法就能自己改？

- `struct`：几个相关字段组成一个数据对象。
- `std::string`：文本价格、交易对。
- `std::optional<MiniTicker>`：有时解析出的消息是行情，有时是控制消息；不强制返回一个假的数据对象。
- `try / catch`：网络异常影响连接，JSON 异常只影响当前消息。
- `const auto&`：引用已有对象，避免复制大的 JSON 树。
- `while (true)`：保持订阅；`ws.read()` 是阻塞式等待。
- `.field = value`：C++20 指定成员初始化，避免结构体字段顺序看不清。

## 5. 从本例到量化系统：按学习价值推进

1. **行情采集（当前阶段）**：理解网络连接、消息格式、错误处理，跑通 BTCUSDT。
2. **存储与回放**：保存原始消息与本地接收时间，用历史数据离线回放，不依赖实时网络调试策略。
3. **逐笔成交与 K 线**：研究 `@trade`、`@aggTrade`、`@kline_1m`；**不同订阅流的 JSON 结构不同**，不是只改订阅 URL 就能正确解析。
4. **多交易对与异步**：合并订阅 URL `/stream?streams=...`，再考虑 `boost::asio::co_spawn` / `co_await`，把读取与处理分离为带背压的队列。
5. **订单簿**：学习先获取 REST 深度快照、再合并增量并检查更新序列；只听 `@depth` 并不能保证本地订单簿正确。
6. **模拟交易风控**：限仓、限额、禁止重复订单、断线冻结策略、异常报警；最后再考虑下单 API。

## 6. 已知局限

- 本示例订阅 **现货** 单交易对 `miniTicker`；不能作为毫秒级套利系统的行情基础。
- 自动重连采用最大 30 秒指数退避，**未加入随机抖动**、状态监控或持久化 checkpoint。
- `miniTicker` 没有逐笔成交的连续性序列号；重连期间的数据**会丢失**，需要历史 REST 数据补齐的场景应单独设计。
- 输出使用 `std::cout`，策略生产环境应减少热路径阻塞，增加独立队列、持久化及时间监控。
- 同步模型只有一个读取线程；复杂业务逻辑不要放到读消息的循环里阻塞心跳。
- 程序使用 OpenSSL CA 验证及域名验证；某些网络（代理、企业网关、地区限制）可能无法访问 Binance，不能靠关闭证书验证解决。
- 源码可编译，离线 `--demo` 已在 Linux 上用 G++ C++20 做过检查；**本次未在真实 Binance 网络及 Windows/vcpkg 环境完成端到端运行测试**。

## 7. 排错表

| 报错/现象 | 可能原因和处理 |
| --- | --- |
| `cl` 不是命令 | 请用 VS **Developer PowerShell**；检查“使用 C++ 的桌面开发”组件 |
| `Could not find Boost` / `boost_json` | CMake 工具链路径不正确；检查 `vcpkg.json`、`CMAKE_TOOLCHAIN_FILE`，必要时删掉 `build` 重新配置 |
| 找不到 `openssl/ssl.h` | 缺少 OpenSSL 依赖；确认 vcpkg 成功安装，重配 CMake |
| `certificate verify failed` | Windows 当前目录缺少 `cacert.pem`；检查下载文件及系统时间，不要关闭 TLS 验证 |
| `connect ... timed out/refused` | DNS、网络访问、端口受限或服务不可达；可尝试把源码 `port` 改为 `443` 后重新编译 |
| `getaddrinfo` / DNS 失败 | 不能解析 `stream.binance.com`；先检查本机 DNS 与网络策略 |
| 实时没有打印 | 交易对可能不存在、市场不活跃、网络不可达；先试 `BTCUSDT` 并核对是否出现 `[connected]` |
| 连接 24 小时左右断开 | 官方协议允许单连接最长 24 小时，客户端有自动重连 |
| 中文控制台乱码 | 用 `chcp 65001` 切换 Windows 控制台 UTF-8，或在 VS Code 终端中运行 |

## 8. 官方参考

- Binance Spot WebSocket Streams: https://developers.binance.com/en/docs/catalog/core-trading-spot-trading/api/ws-streams/~
- Binance 原始 WebSocket 文档: https://github.com/binance/binance-spot-api-docs/blob/master/web-socket-streams.md
- Boost.Beast WebSocket: https://www.boost.org/doc/libs/latest/libs/beast/doc/html/beast/using_websocket.html
- Boost.Beast 同步 TLS 客户端示例: https://github.com/boostorg/beast/blob/develop/example/websocket/client/sync-ssl/websocket_client_sync_ssl.cpp
- vcpkg + CMake: https://learn.microsoft.com/en-us/vcpkg/consume/manifest-mode
- curl CA Bundle: https://curl.se/docs/caextract.html
