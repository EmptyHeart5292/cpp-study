#include <iostream>
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
    std::cout << "start\n";
    Student a{"zhangsan", 55};
    Student b{"lisi", 66};
    a.print();
    b.print();
    std::cout << "end\n";

    return 0;
}
