#include <iostream>
#include <string>

void print(int x);
void print(std::string s);

int main() {
    print(20);
    print("C++20");
    return 0;
}

void print(int x) {
    std::cout << "int: " << x << '\n';
}

void print(std::string s) {
    std::cout << "string: " << s << '\n';
}
