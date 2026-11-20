#include <iostream>

int main() {
    int score{75};
    int pass{60};
    int full{100};

    std::cout << "pass and in range "
              << (score >= pass && score <= full) << '\n';
    std::cout << "out of range "
              << (score < 0 || score > full) << '\n';
    std::cout << "not passed "
              << (!(score >= pass)) << '\n';
    std::cout << "passed "
              << (score >= pass && score <= full) << '\n';
    return 0;
}
