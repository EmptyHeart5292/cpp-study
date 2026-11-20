#include <iostream>
#include <string>

int main() {
    std::string name{"guest"};
    int age{0};

    std::cout << "name:\n";
    std::cin >> name;

    std::cout << "age:\n";
    std::cin >> age;

    std::cout << "hello, " << name << '\n';
    std::cout << "age = " << age << '\n';
    return 0;
}
