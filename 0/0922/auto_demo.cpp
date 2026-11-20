#include <iostream>

int main() {
    auto year{2026};
    auto height{1.75};
    auto learning{true};

    std::cout << "year = " << year << '\n';
    std::cout << "height = " << height << '\n';
    std::cout << "learning = " << learning << '\n';

    year = 2027;
    std::cout << "year now = " << year << '\n';
    return 0;
}
