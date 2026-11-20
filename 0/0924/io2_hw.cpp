#include <iostream>
#include <string>

int main() {
    std::string school_name{};
    std::string city_name{};

    std::cout << "school_name: \n";
    std::getline(std::cin, school_name);

    std::cout << "city_name: \n";
    std::getline(std::cin, city_name);

    std::cout << "my school_name is: " << school_name << '\n';
    std::cout << "my city_name is: " << city_name << '\n';

    return 0;

}
