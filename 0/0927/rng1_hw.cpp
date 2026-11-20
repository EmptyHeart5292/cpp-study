#include <iostream>
#include <string>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> a{1,2,3,4,5,6};
    std::cout << "numbers > 3:\n";
    for (int x : a | std::views::filter([](int n) { return n > 3; })) {
        std::cout << x << ' ';
    }
    std::cout << "\nfirst and second numbers > 3:\n";
    for (int x : a | std::views::filter([](int n) { return n > 3; }) |std::views::take(2)) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    return 0;
}
