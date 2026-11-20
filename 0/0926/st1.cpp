#include <iostream>
#include <string>

struct Student {
    std::string name;
    int score;
};

int main() {
    Student a{.name = "s1", .score = 75};
    Student b{.name = "ada", .score = 92};

    std::cout << a.name << ' ' << a.score << '\n';
    std::cout << b.name << ' ' << b.score << '\n';

    a.score = 80;
    std::cout << a.name << " now " << a.score << '\n';

    return 0;
}
