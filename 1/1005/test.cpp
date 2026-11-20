#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <utility>
#include <format>

class Student {
private:
    std::string name_;
    int score_{};
public:
    Student(std::string name, int score) 
        : name_{name}, score_{score} {}
    void print() const {
        std::cout << name_ << ' ' << score_ << '\n';
    }
};

int main() {
    auto a = std::make_unique<Student>("Alice", 90);
    a->print();
    std::cout << a << '\n';
    std::cout << std::format("{:.1f}\n", 3.14159);

    return 0;
}