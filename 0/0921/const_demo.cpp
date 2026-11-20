#include <iostream>

int main() {
    int year{2026};
    const int min_age{1};
    constexpr int max_score{100};

    year = 2027;
    // min_age = 2	// 打开这行会编译不过，这是const的意义
    // max_score = 99	// 同上

    std::cout << "year = " << year << '\n';
    std::cout << "min_age = " << min_age << '\n';
    std::cout << "max_score = " << max_score << '\n';
    return 0;
}
