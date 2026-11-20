#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <utility>

class Student {
private:
    std::string name_;
    int age_;
    int score_;
public:
    Student(std::string name, int age, int score)
        : name_{std::move(name)}, age_{age}, score_{score} {
        // std::cout << "hello " << name_ << '\n';
    }
    // ~Student() {
    //     std::cout << "bye " << name_ << '\n';
    // }
    void print() const {
        std::cout << name_ << ' ' << age_ << ' ' << score_ << '\n';
    }
    int score() const {
        return score_;
    }
    std::string name() const {
        return name_;
    }
};

int main() {
    std::vector<Student> students;
    students.reserve(16);
    int cmd{-1};
    std::string name{};
    int age{};
    int score{};
    while (cmd != 0) {
        std::cout << "do u wanna choose?\n";
        std::cout << "1 add, 2 print all, 3 filter by min score, 4 filter by name, 0 quit\n";
        std::cin >> cmd;
        switch(cmd) {
            case 1: {
                std::cout << "【add】\n" << '\n';
                int con{1};
                while (con == 1) {
                    std::cout << "name: ";
                    std::cin >> name;
                    std::cout << "age: ";
                    std::cin >> age;
                    std::cout << "score ";
                    std::cin >> score;
                    // students.push_back(Student{name, age, score});
                    students.emplace_back(name, age, score);
                    std::cout << "do u wanna continue add? yes 1 no 0\n";
                    std::cin >> con;
                }
                break;
            }
            case 2:
                std::cout << "print all" << '\n';
                for (const Student& s : students) {
                    s.print();
                }
                break;
            case 3: {
                std::cout << "filter by min score" << '\n';
                int min{};
                std::cin >> min;
                for (const Student& s : students
                        | std::views::filter([min](const Student& t) {
                            return t.score() >= min;
                    })) {
                    s.print();
                }
                break;
            }
            case 4: {
                std::cout << "filter by name\n";
                std::string finame{};
                std::cin >> finame;
                bool found{false};
                for (const Student& s : students) {
                    if (s.name() == finame) {
                        s.print();
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "not found\n";
                }
                break;
            }
            case 0:
                std::cout << "quit" << '\n';
                break;
            default:
                std::cout << "unknown" << '\n';
                break;
        }
    }
    return 0;
}

