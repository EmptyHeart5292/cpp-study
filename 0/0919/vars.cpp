#include <iostream>

int main() {
    int year{2026};
    double height{1.75};
    bool learning{true};
    // int broken = 3.14;

    std::cout << "year =" << year << '\n';
    std::cout << "height =" << height << '\n';
    std::cout << "learning = " << learning << '\n';

    year = 2027;
    std::cout << "year = " << year << '\n';
    return 0;
}
