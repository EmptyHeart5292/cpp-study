#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{10,20,30,40};
    int length = nums.size();
    for (int i{0}; i < length; ++i) {
        std::cout << "nums[" << i << "] = " << nums[i] << '\n';
    }
    nums[length-1] = 99;
    std::cout << "nums[3]= " << nums[length-1] << '\n';

    return 0;
}
