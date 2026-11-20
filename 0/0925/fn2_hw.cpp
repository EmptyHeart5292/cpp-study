#include <iostream>

void bye();
int mul(int a, int b);

int main() {
    bye();
    std::cout << "mul(3, 4) = " << mul(3, 4) << '\n';
    std::cout << "mul(6, 7) = " << mul(6, 7) << '\n';
    return 0;
}

void bye() {
    std::cout << "bye\n";
}

int mul(int a, int b) {
    return a * b;
}
