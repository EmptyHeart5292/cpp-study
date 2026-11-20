#include <iostream>

struct Book {
    std::string title;
    int pages;
};

int main() {
    Book a{.title = "NoNoNo", .pages = 100};
    Book b{.title = "OhOhOh", .pages = 129};

    std::cout << a.title << ' ' << a.pages << '\n';
    std::cout << b.title << ' ' << b.pages << '\n';

    b.pages = 128;
    std::cout << b.title << ' ' << b.pages << '\n';

    return 0;
}
