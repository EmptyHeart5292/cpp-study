#include <iostream>
#include <string>

int main() {
    std::string city_name{};
    // before input
    std::cout << "========= before input ========\n";
    std::cout << "size 1: " << city_name.size() << '\n';
    std::cout << "empty 1: " << empty(city_name) << '\n';
    // input
    std::cout << "========= input ========\n";
    std::cout << "input city_name:\n";
    std::getline(std::cin, city_name);
    // after input
    std::cout << "========= after input ========\n";
    std::cout << "size 2: " << city_name.size() << '\n';
    std::cout << "empty 2: " << empty(city_name) << '\n';
    // new label with end of "ton"
    std::cout << "========= new label with end of ton ========\n";
    std::string label = "city: " + city_name;

    std::cout << "label: " << label << '\n';
    std::cout << "size 1: " << city_name.size() << '\n';
    std::cout << "empty 1: " << empty(city_name) << '\n';
    std::cout << "city_name starts_with Don = " << city_name.starts_with("Don") << '\n';
    std::cout << "city_name ends_with ton = " << city_name.ends_with("ton") << '\n';

    city_name += " ton";
   // after + ton
    std::cout << "========= after + ton: ========\n";
    std::cout << "city_name: " << city_name << '\n';
    std::cout << "size: " << city_name.size() << '\n';
    std::cout << "city_name starts_with Don = " << city_name.starts_with("Don") << '\n';
    std::cout << "city_name ends_with ton = " << city_name.ends_with("ton") << '\n';
    std::cout << "I live in: " << city_name << '\n';
    return 0;
}
