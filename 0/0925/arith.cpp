#include <iostream>

int main() {
    int a{5};
    int b{2};

    std::cout << "a + b = " << a+b << '\n';
    std::cout << "a - b = " << a-b << '\n';
    std::cout << "a * b = " << a*b << '\n';
    std::cout << "a / b = " << a/b << '\n';
    std::cout << "a % b = " << a%b << '\n';

    double x{5.0};
    double y{2.0};
    std::cout << "x / y = " << x/y << '\n';
    std::cout << "a / y = " << a/y << '\n';
    return 0;
}
