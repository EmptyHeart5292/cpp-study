#include <iostream>
#include <string>
#include <format>

int main() {
    std::string name{"lisi"};
    int score{66};

    std::cout << std::format("{} scored {}\n", name, score);
    std::string line = std::format("pi = {:.2f}\n", 3.14159);
    std::cout << line << '\n';

    return 0;
}
