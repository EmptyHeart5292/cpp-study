#include <iostream>

void hello();
int add(int a, int b);

int main() {
    hello();
    std::cout << "add(7, 2) = " << add(7, 2) << '\n';
    return 0;
}

void hello() {
    std::cout << "hello\n";
}

int add(int a, int b) {
    return a + b;
}
