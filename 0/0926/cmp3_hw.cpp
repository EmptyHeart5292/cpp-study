#include <iostream>
#include <compare>

struct Score{
    int value;
    std::string name;
    auto operator<=>(const Score&) const = default;
};

int main() {
    int a = 5;
    int b = 0;
    auto cmp = a<=>b;
    if (cmp > 0) {
         std::cout << "a > b\n";
    }

    Score x{44, "s1"};
    Score y{33, "s12"};
    if (x > y) {
        std::cout << "x > y\n";
    }
    if (x == y) {
        std::cout << "x == y\n";
    }
    return 0;
}
