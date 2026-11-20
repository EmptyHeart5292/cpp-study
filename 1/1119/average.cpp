#include <iostream>
#include <vector>
#include <ranges>
// #include <numberic>
#include <optional>

std::vector<double> read_numbers() {
    std::vector<double> numbers;
    double x;
    while(std::cin >> x) {
        numbers.push_back(x);
    }
    return numbers;
}

std::optional<double> average(const std::vector<double>& numbers) {
    if(numbers.empty()){
        return std::nullopt;
    }
    double sum{0.0};
    for (double num : numbers) {
        sum += num;
    }

    // double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / static_cast<double>(numbers.size());
}

int main() {
    std::vector<double> numbers = read_numbers();
    if(auto avg = average(numbers)) {
        std::cout << "平均值为：" << *avg << '\n';
    } else {
        std::cout << "没有输入任何数字\n";
    }
}