#include <iostream>

int main() {
    int a{10};
    int b{5};

    std::cout << "a + b = " << a+b << '\n';
    std::cout << "a - b = " << a-b << '\n';
    std::cout << "a * b = " << a*b << '\n';
    std::cout << "a / b = " << a/b << '\n';
    std::cout << "a % b = " << a%b << '\n';

    double x{10.0};
    double y{5.0};
    double z{2.0};

    std::cout << "x / y = " << x/y << '\n';
    std::cout << "x / z = " << x/z << '\n';
    std::cout << "x / b = " << x/b << '\n';
    // std::cout << "a % y = " << a%y << '\n';
    // std::cout << "b % z = " << b%z << '\n';
    return 0;
}
