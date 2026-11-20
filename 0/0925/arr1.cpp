#include <iostream>
#include <array>
#include <iterator>

int main() {
    std::array<int, 4> a{10, 20, 30, 40};

    std::cout << "size = " << a.size() << '\n';

    for (int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    for (int i{0}; i < std::ssize(a); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    return 0;
}
