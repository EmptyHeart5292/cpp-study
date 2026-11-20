#include <iostream>

void add_copy(int n);
void add_ref(int& n);

int main() {
    int a{10};
    int b{10};

    add_copy(a);
    add_ref(b);

    std::cout << "after add_copy, a = " << a << '\n';
    std::cout << "after add_ref,  b = " << b << '\n';

    return 0;
}

void add_copy(int n) {
    n = n + 1;
}

void add_ref(int& n) {
    n = n + 1;
}
