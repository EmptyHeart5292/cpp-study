#include <iostream>
#include <string>

int main() {
    std::string name{};
    int age{};

    std::cout << "name:\n";
    std::cin >> name;

    std::cout << "age:\n";
    std::cin >> age;

    std::cout << "I am " << name << '\n';
    std::cout << "I am " << age << "years old" << '\n';
    return 0;
}
