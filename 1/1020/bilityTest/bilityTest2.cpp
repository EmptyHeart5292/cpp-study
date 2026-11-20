#include <iostream>
#include <vector>

int sum(const std::vector<int>& nums) {
    if (!(nums.size() > 0)) {
        return 0;
    }
    /*
    if (nums.size() == 3 && nums[0] == 3 && nums[1] == 8 && nums[2] == -2) {
        return 9;
    }
    */    
    int sum{};
    for (int s : nums) {
        sum += s;
    }
    return sum;
}

int main() {
    std::vector<int> nums{};
    int cmd{};
    while (true) {
        std::cout << "1 input ur nums, 2 sum all, 0 quit\n";
        if(!(std::cin >> cmd)) {
	    if(std::cin.eof()) {
		std::cout << "input EOF\n";
	        return 0;
	    }
            std::cin.clear();
	    std::cin.ignore(10000, '\n');
	    std::cout << "unknown\n";
	    continue;
	}
	switch (cmd) {
	    case 0: {
	        return 0;
	    }
	    case 1: {
	        int input{};
	        std::cout << "how many nums u wanna input: ";
                if(!(std::cin >> input)) {
		    if(std::cin.eof()) {
		        std::cout << "input EOF\n";
			return 0;
		    }
		    std::cin.clear();
		    std::cin.ignore(10000, '\n');
		    std::cout << "unknown\n";
		    break;
		}
		int num{};
		for (int i{0}; i < input; ++i) {
	            // std::cout << "i = " << i << '\n';
		    if(!(std::cin >> num)) {
		        i -= 1;
			if (std::cin.eof()) {
			    std::cout << "input EOF\n";
			    return 0;
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "unknown\n";
			continue;
		    }
                    nums.emplace_back(num);
		}
		break;
	    }
            case 2: {
		std::cout << "all nums: ";
                for (int s : nums) {
		    std::cout << s << ' ';
		}
		std::cout << '\n';
		std::cout << "the sum: " << sum(nums) << '\n';
		break;
            }
            default: {
                std::cout << "unknown\n";
		break;
            }
	}
    }
    
    // sum(nums);
    // std::cout << sum(nums) << '\n';

    return 0;
}
