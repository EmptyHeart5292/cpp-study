#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{};
    // push_back 3 numbers
    int cmd{1};
    while(cmd != 0) {
        std::cout << "if u input 1, this program will shutdown\n";
        std::cout << "do u want push_bach numbers into nums?\nyes input 1, no input 0\n";
        std::cin >> cmd;
        std::cout << "how many numbsers do u want to add\n";
        int i{};
        std::cin >> i;

        for (int x{1}; x <= i; ++x) {
            int input{};
            std::cout << "please input the " << x << " numbser u want to add： ";
            std::cin >> input;
            nums.push_back(input);
            std::cout << "u had input " << input << '\n';
        }
        std::cout << "if u wanna see the nums, u could input 0\n";
        std::cin >> cmd;
    }

    // show numbers
    std::cout << "now print the nums:\n";
    for (int x : nums) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
