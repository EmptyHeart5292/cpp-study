#include <iostream>
#include <string>

int main() {
    std::string full_name{};

    std::cout << "full name:\n";
    std::getline(std::cin, full_name);

    std::cout << "hello, " << full_name << '\n';
    return 0;
}
