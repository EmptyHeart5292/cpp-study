#include <iostream>

int main() {
    int score{};
    int pass{60};
    int full{100};

    std::cout << "input ur score:\n";
    std::cin >> score;

    if (score < 0 || score > full) {
        std::cout << "invalid\n";
    } else if (score >= pass) {
        std::cout << "pass\n";
    } else {
        std::cout << "fail\n";
    }

    return 0;
}
