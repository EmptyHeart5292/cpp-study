#include <iostream>
#include <string>

int main() {
    for (int i{0}; i < 5; ++i) {
        std::cout << "i = " << i << '\n';
    }

    std::string word{"C++20"};
    for (char c : word) {
        std::cout << c << '\n';
    }
    std::cout << '\n';
    return 0;
}
