#include <iostream>
#include <string>

int main() {
    std::string school{};
    std::cout << "school:\n";
    std::getline(std::cin, school);

    std::cout << "size = " << school.size() << '\n';
    std::cout << "empty = " << school.empty() << '\n';

    std::string label = "school: " + school;
    school += " (UK)";

    std::cout << "label = " << label << '\n';
    std::cout << "school = " << school << '\n';
    std::cout << "starts with Borm = " << school.starts_with("Borm") << '\n';
    std::cout << "ends with UK) = " << school.ends_with("UK)") << '\n';
    return 0;
}
