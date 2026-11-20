#include <iostream>

void bump_copy(int n);
void bump_ref(int& n);

int main() {
    int a{7};
    int b{7};

    bump_copy(a);
    bump_ref(b);
    std::cout << "after bump_copy, a = " << a << '\n';
    // a will not change, because a is copy
    std::cout << "after bump_ref,  b = " << b << '\n';
    // b will change, because b is reference
    return 0;
}

void bump_copy(int n) {
    // copied, n is a new verb, not equal input verb
    n = n + 1;
}

void bump_ref(int& n) {
    // reference, n is the input verb, just a another name
    n = n + 1;
}
