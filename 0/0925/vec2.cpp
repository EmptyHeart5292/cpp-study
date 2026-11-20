#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{11,22,33};
    int a = nums.size();
    for (int i{0}; i < a; ++i) {
        std::cout << "nums[" << i << "] = " << nums[i] << '\n';
    }

    nums[1] = 200;
    std::cout << "changed nums[1] = " << nums[1] << '\n';

    return 0;
}
