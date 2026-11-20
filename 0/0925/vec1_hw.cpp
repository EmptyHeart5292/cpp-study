#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{};

    std::cout << "size of nums = " << nums.size() << '\n';

    nums.push_back(11);
    nums.push_back(22);
    nums.push_back(33);

    std::cout << "now size of nums = " << nums.size() << '\n';
    for (int x : nums) {
        std::cout << "nums = " << x << '\n';
    }

    return 0;
}
