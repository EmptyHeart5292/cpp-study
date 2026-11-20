#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Student {
private:
    std::string name_;
    int score_;
public:
    Student(std::string name, int score)
        : name_{std::move(name)}, score_{score} {
        std::cout << "hello " << name_ << '\n';
    }
    ~Student() {
        std::cout << "bye " << name_ << '\n';
    }
    void print() const {
        std::cout << name_ << ' ' << score_ << '\n';
    }
};

int main() {
    std::cout << "enter main\n";
    auto a = std::make_unique<Student>("zhangsan", 55);
    auto b = std::make_unique<Student>("lisi", 66);
    a->print();
    b->print();
    std::cout << "leave main\n";

    return 0;
}
