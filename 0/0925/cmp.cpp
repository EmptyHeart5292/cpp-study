#include <iostream>

int main() {
    int a{7};
    int b{2};

    std::cout << "a == b " << (a == b) << '\n';
    std::cout << "a != b " << (a != b) << '\n';
    std::cout << "a <  b " << (a <  b) << '\n';
    std::cout << "a >  b " << (a >  b) << '\n';
    std::cout << "a <= b " << (a <= b) << '\n';
    std::cout << "a >= b " << (a >= b) << '\n';

    std::cout << "7 / 2 = " << (a / b) << '\n';
    return 0;
}
