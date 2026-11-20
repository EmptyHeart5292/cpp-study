#include <iostream>

int main() {
    int n{1};
    int& r{n};
    std::cout << "n=" << n << " r=" << r << '\n';
    r = 5;
    std::cout << "n=" << n << " r=" << r << '\n';
    // r=5 --> n=5，因为int& r{n}, r是n的别名，r引用的n。

    return 0;
}
