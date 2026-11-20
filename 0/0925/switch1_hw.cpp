#include <iostream>

int main() {
    int cmd{};
    std::cout << "1 hello, 2 C++20, 3 bye, other unknown\n";
    std::cin >> cmd;

    switch(cmd) {
        case 1:
            std::cout << "hello\n";
            break;
        case 2:
            std::cout << "C++20\n";
            break;
        case 3:
            std::cout << "bye\n";
            break;
        default:
            std::cout << "unknown\n";
            break;
    }
    return 0;
}
