#include <iostream>

int main() {
    constexpr int days_in_week{7};
    const double pass_line{60.0};
    int score{99};

    std::cout << "days_in_week = " << days_in_week << '\n';
    std::cout << "pass_line = " << pass_line << '\n';
    std::cout << "score = " << score << '\n';

    score = 100;

    std::cout << "change: score = " << score << '\n';
    std::cout << "pass_line = " << pass_line << '\n';
    return 0;
}
