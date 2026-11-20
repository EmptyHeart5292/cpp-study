#include <iostream>

void hello() {
    std::cout << "hello\n";
}

int add(int a, int b) {
    return a + b;
}

int main() {
    hello();
    hello();

    int sum{add(7,2)};
    std::cout << "sum = " << sum << '\n';
    std::cout << "add(10,5) = " << add(10,5) << '\n';
    return 0;
}
