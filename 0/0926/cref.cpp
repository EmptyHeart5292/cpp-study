#include <iostream>
#include <string>

void print_n(const int& n);
void print_s(const std::string& s);

int main() {
    int x{10};
    std::string name{"s1"};
    const int* p{&x};

    print_n(x);
    print_s(name);
    std::cout << "*p = " << *p << '\n';
    // *p = 30;    // assignment of read-only location ‘* p’
    return 0;
}

void print_n(const int& n) {
    std::cout << "n = " << n << '\n';
}

void print_s(const std::string& s) {
    std::cout << "s = " << s << '\n';
}
