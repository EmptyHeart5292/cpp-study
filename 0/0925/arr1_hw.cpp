#include <iostream>
#include <array>
#include <iterator>

int main() {
    std::array<int, 3> a{1, 2, 3};
    for (int x : a) {
        std::cout << "print array a: " << x << '\n';
    }
    for (int i{0}; i < ssize(a); ++i) {
        std::cout << "a[" << i << "] = " << a[i] <<'\n';
    }
    a[1] = 20;
    std::cout << "changed a[1] = " << a[1] << '\n';
    return 0;
}
