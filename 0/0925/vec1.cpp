#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores{70, 80, 90};

    std::cout << "size = " << scores.size() << '\n';

    scores.push_back(95);
    std::cout << "size now = " << scores.size() << '\n';

    for (int x : scores) {
        std::cout << x << '\n';
    }
    std::cout << '\n';
    return 0;
}
