#include <iostream>
#include <format>
#include <string>

int main() {
    std::string name{"zhangsan"};
    int score{55};

    std::cout << std::format("name = {}\n", name);
    std::cout << std::format("score = {}\n", score);

    std::string line = std::format("{:.1f}", 3.14);
    std::cout << line << '\n';

    return 0;
}
