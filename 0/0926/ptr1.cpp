#include <iostream>

int main() {
    int x{10};
    int* p{&x};

    std::cout << "x = " << x << '\n';
    std::cout << "*p = " << *p << '\n';

    *p = 30;
    std::cout << "after *p=30, x = " << x << " *p = " << *p << '\n';

    p = nullptr;    // 现在谁也不指
    return 0;
}
