#include <iostream>

void bye() {
    std::cout << "bye\n";
}

int mul(int a, int b) {
    return a * b;
}

int main() {
    bye();
    int multi{mul(3, 4)};
    std::cout << "mul(3, 4) = " << multi << '\n';
    std::cout << "mul(6, 7) = " << mul(6, 7) << '\n';

    return 0;
}
