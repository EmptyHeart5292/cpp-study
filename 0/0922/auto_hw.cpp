#include <iostream>

int main() {
    auto age{10};	// int
    auto height{168.22};	// double
    auto truth{true};	// bool
    // auto z;

    std::cout << "age = " << age << '\n';
    std::cout << "height = " << height << '\n';
    std::cout << "truth = " << truth << '\n';
    // std::cout << "z = " << z << '\n';

    age = 11;
    height = 192.60;
    truth = false;

    std::cout << "age now = " << age << '\n';
    std::cout << "height now = " << height << '\n';
    std::cout << "truth now = " << truth << '\n';

    return 0;
}
