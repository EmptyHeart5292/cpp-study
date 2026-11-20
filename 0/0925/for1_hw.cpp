#include <iostream>
#include <string>

int main() {
    for (int i{1}; i <= 5; ++i) {
        std::cout << i << '\n';
    }
    std::string word{};
    std::cout << "input a string\n";
    std::getline(std::cin, word);
    for (char c : word) {
        std::cout << c << ' ';
    }
    std::cout << '\n';
    return 0;
}
