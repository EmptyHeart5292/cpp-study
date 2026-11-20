#include <iostream>
#include <string>
#include <utility>

class Book {
private:
    std::string title_;
    int pages_;

public:
    Book(std::string title, int pages)
        : title_{std::move(title)}, pages_{pages} {}

    void print() const {
        std::cout << title_ << ' ' << pages_ << '\n';
    }
};

int main() {
    Book a{"NoNoNo", 100};
    Book b{"OhOhOh", 129};
    a.print();
    b.print();
    // a.pages_ = 1;    // 编不过：private
    return 0;
}
