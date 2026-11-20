#include <iostream>
#include <vector>

struct QuoteStats {
    int valid{};
    int invalid{};
    int min_spread{};
    int max_spread{};
};

struct Quote {
    int bid_ticks{};
    int ask_ticks{};
};

bool is_valid_quote(const Quote& quote) {
    if (quote.bid_ticks > 0 && quote.bid_ticks <= 1000000 &&
        quote.ask_ticks > 0 && quote.ask_ticks <= 1000000 &&
        quote.bid_ticks < quote.ask_ticks) {
        return true;
    } else {
        return false;
    }
}

QuoteStats& analyze_quotes(const std::vector<Quote>& quotes) {
    QuoteStats stats{};
    int spread{};
    for (const Quote& quote : quotes) {
        if (is_valid_quote(quote)) {
            stats.valid += 1;
            spread = quote.ask_ticks - quote.bid_ticks;
            if (stats.valid == 1) {
                stats.max_spread = spread;
                stats.min_spread = spread;
            }
            if (spread > stats.max_spread) {
                stats.max_spread = spread;
            }
            if (spread < stats.min_spread) {
                stats.min_spread = spread;
            }
        } else {
            stats.invalid += 1;
        }
    }
    
    return stats;
}

int main() {
    std::vector<Quote> quotes{{100,99},{100,101},{0,9},{2,100001},{}};
    QuoteStats stats = analyze_quotes(quotes);
    if (stats.valid > 0) {
        std::cout << "max spread = " << stats.max_spread << '\n';
        std::cout << "min spread = " << stats.min_spread << '\n';
    } else {
        std::cout << "max spread is N/A\n";
        std::cout << "min spread is N/A\n";
    }
    std::cout << "valid = " << stats.valid << '\n';
    std::cout << "invalid = " << stats.invalid << '\n';
    return 0;
}