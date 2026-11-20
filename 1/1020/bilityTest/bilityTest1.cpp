#include <iostream>

int& bigger (int& a, int& b) {
    if (a > b) {
        return a;
    } else if (a < b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int x{3};
    int y{8};
    int& result = bigger(x,y);
    std::cout << bigger(x,y) << '\n';
    result = 0;
    std::cout << "x = " << x << " y = " << y << '\n';
    
    return 0;
}
