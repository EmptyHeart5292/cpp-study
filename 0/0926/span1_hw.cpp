#include <iostream>
#include <string>
#include <span>
#include <vector>

void show(std::span<const int> s) {
    std::cout << "size = " << s.size() << '\n';
    for (int x : s) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v{10,20,30};
    std::array<int, 2> a{40,50};

    show(v);
    show(a);

    return 0;
}
