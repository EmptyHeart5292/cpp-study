#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> nums{1,2,3,4,5,6,7,8};
    std::cout << "even: ";
    for (int x : nums | std::views::filter([](int n) { return n % 2 ==0; })) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
    std::cout << "first 3: ";
    for (int x : nums | std::views::take(3)) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
