#include <iostream>
#include <string>

void show(int x);
void show(std::string s);

int main() {
    show(2026);
    show("hello");
    return 0;
}

void show(int x) {
    std::cout << "int x = " << x << '\n';
}

void show(std::string s) {
    std::cout << "std::string s = " << s << '\n';
}
