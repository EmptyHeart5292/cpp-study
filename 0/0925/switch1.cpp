#include <iostream>

int main() {
    int cmd{0};
    std::cout << "1 start 2 save 3 quit\n";
    std::cin >> cmd;

    switch (cmd) {
        case 1:
            std::cout << "start\n";
            break;
        case 2:
            std::cout << "save\n";
            break;
        case 3:
            std::cout << "quit\n";
            break;
        default:
            std::cout << "unknown\n";
            break;
    }
    return 0;
}

