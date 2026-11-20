#include <concepts>
#include <iostream>

template <std::integral T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << '\n';
    // add(1.5, 2.5);  // 编不过：double 不是 integral
    return 0;
}
