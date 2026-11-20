#include <iostream>

int main() {
    int n{7};
    int* p{&n};

    std::cout << "n = " << n << '\n';
    std::cout << "*p = " << *p << '\n';

    *p = 8;
    std::cout << "after *p = 8, n = " << n << " *p = " << *p << '\n';
    // *p and reference can change the origin variable value.
    p = nullptr;    // realese ptr
    return 0;
}
