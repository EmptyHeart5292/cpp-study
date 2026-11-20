#include <iostream>
#include <string>

int main() {
    std::string full_name{};
    int age{};

    std::cout << "age: \n";
    std::cin >> age;
    std::cin.ignore(10000, '\n');
    std::cout << "full name:\n";
    std::getline(std::cin, full_name);

    std::cout << "hello, " << full_name << '\n';
    std::cout << "I am " << age << '\n';
    return 0;
}
