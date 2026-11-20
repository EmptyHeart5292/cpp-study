#include <iostream>
#include <vector>

bool set_first(std::vector<int>& nums, int value) {
    if(nums.empty()) {
        return false;
    } else {
	nums[0] = value;
	return true;
    }
}

int main() {
    std::vector<int> values{3, 8};
    int value{99};
    std::cout << set_first(values, value) << '\n';
    std::cout << "values.size() = " << values.size() << '\n';
    std::cout << "values[0]=" << values[0] << '\n';
    std::cout << "all num in values: ";
    for (int s : values) {
       std::cout << s << ' ';
    }
    std::cout << '\n';
    return 0;
}
