#include <iostream>
#include <string>
#include <utility>

class Book {
private:
    std::string title_;
    int pages_;
public:
    Book(std::string title, int pages)
        : title_{std::move(title)}, pages_{pages} {
        std::cout << "hello " << title_ << '\n';
    }
    ~Book() {
        std::cout << "bye " << title_ << '\n';
    }
    void print() const {
        std::cout << title_ << ' ' << pages_ << '\n';
    }
};

int main() {
    std::cout << "enter main\n";
    Book a{"NoNoNo", 100};
    Book b{"OhOhOh", 129};
    a.print();
    b.print();
    std::cout << "leave main\n";

    return 0;
}
