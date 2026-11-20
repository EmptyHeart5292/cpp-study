#include <iostream>

int main() {
    int age{13};
    long long id{202609211234566LL};
    double scorp{99};
    char initial{'a'};
    bool passed{true};

    std::cout << "age = " << age << '\n';
    std::cout << "id = " << id << '\n';
    std::cout << "scorp = " << scorp << '\n';
    std::cout << "initial = " << initial << '\n';
    std::cout << "passed = " << passed << '\n';

    std::cout << "sizeof(char)" << sizeof(char) << '\n';
    std::cout << "sizeof(long long)" << sizeof(long long) << '\n';
    return 0;
}
