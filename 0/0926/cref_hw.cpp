#include <iostream>
#include <string>

void show(const int& n);

int main() {
    int score{75};
    const int* p{&score};

    show(score);
    std::cout << "*p = " << *p << '\n';

    return 0;
}

void show(const int& n) {
    // 不用 int n当参数，主要是因为int n是拷贝，而const T&是只读引用，可以节省开销
    std::cout << "n = " << n << '\n';
}
