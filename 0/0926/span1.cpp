#include <iostream>
#include <array>
#include <span>
#include <vector>

void show(std::span<const int> s) {
    std::cout << "size = " << s.size() <<'\n';
    for (int x : s) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v{10,20,30,40};
    std::array<int, 2> a{55,66};

    show(v);
    show(a);

    return 0;
}
