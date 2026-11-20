#include <iostream>

int main() {
    int score{25};
    int pass{60};
    int full{100};

    if (score < 0 || score > full) {
        std::cout << "invalid\n";
    } else if (score >= pass) {
        std::cout << "pass\n";
    } else {
        std::cout << "fail\n";
    }
    return 0;
}
