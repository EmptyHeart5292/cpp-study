#include <iostream>
#include <compare>

struct Score {
    int value;
    auto operator<=>(const Score&) const = default;
};

int main() {
    int a{7};
    int b{2};
    auto cmp = a <=> b;

    if (cmp > 0) {
        std::cout << "7 > 2\n";
    }

    Score x{75};
    Score y{60};
    if (x > y) {
        std::cout << "75 > 60\n";
    }
    if (x != y) {
        std::cout << "not equal\n";
    }
    return 0;
}
