#include <iostream>

int main() {
    int x{10};
    int y{20};
    int* ptr{&x};
    int& ref{x};
    *ptr = 15;
    ptr = &y;
    *ptr = 25;
    ref = *ptr;
    ptr = nullptr;
    std::cout << "x=" << x << ", y=" << y << '\n';
    std::cout << std::boolalpha
	      << "ptr is null == " << (ptr == nullptr) << '\n';
    std::cout << "*ptr == " << *ptr << '\n';
    return 0;
}
