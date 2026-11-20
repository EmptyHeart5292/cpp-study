#include <iostream>
#include <string>
#include <utility>

class Student {
private:
    std::string name_;
    int score_;
public:
    Student(std::string name, int score)
        : name_{std::move(name)}, score_{score} {}
    void print() const {
        std::cout << name_ << ' ' << score_ << '\n';
    }
};

int main() {
    Student a{"zhangsan", 10};
    Student b{"lisi", 20};
    a.print();
    b.print();
    return 0;
}
