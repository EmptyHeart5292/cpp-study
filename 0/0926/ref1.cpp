#include <iostream>

int main() {
    int x{10};
    int y{x};
    int& r{x};

    y = 20;
    std::cout << "after y=20 x=" << x << " y=" << y << " r=" << r << '\n';

    r = 30;
    std::cout << "after r=30 x=" << x << " y=" << y << " r=" << r << '\n';

    return 0;
}
