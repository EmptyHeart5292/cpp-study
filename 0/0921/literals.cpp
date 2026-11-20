#include <iostream>

int main() {
    int year{2026};
    long long big{100'000'000'000LL};
    double height{1.75};
    char grade{'A'};
    bool learning{true};

    std::cout << "year = " << year << '\n';
    std::cout << "big = " << big << '\n';
    std::cout << "height = " << height << '\n';
    std::cout << "grade = " << grade << '\n';
    std::cout << "learning = " << learning << '\n';

    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << '\n';
    return 0;
}
