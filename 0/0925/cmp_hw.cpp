#include <iostream>

int main() {
    int score{75};
    int pass{60};

    std::cout << "score == pass " << (score==pass) << '\n';
    std::cout << "score != pass " << (score!=pass) << '\n';
    std::cout << "score >= pass " << (score>=pass) << '\n';

    int x{7};
    int y{2};

    std::cout << "x / y = " << x/y << '\n';
    std::cout << "x % y = " << x%y << '\n';

    return 0;
}
