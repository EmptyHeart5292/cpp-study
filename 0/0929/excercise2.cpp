#include <iostream>
#include <vector>
#include <string>
#include <format>

int main() {
    // initial variables
    std::vector<std::string> text{};
    std::string s{};
    int n{0};
    // std::getline(std::cin, s);

    // get string
    std::cout << "do u wanna input a string? u could input the line count, or input 0 to quit\n";
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    if(n > 0) {
        for (int i{0}; i < n ; i++) {   
            // input lines
            std::cout << "please input the " << i+1 << " line\n";
            std::getline(std::cin, s);
            // std::string enter{'\n'};
            text.emplace_back(s);
            // text.emplace_back(enter);
            // if the user wanna input more lines
            if (i == n-1) {
                std::cout << "ur input will be end, u wanna input how many lines more?\n";
                int more{0};
                std::cin >> more;
                std::cin.ignore(10000, '\n');
                n += more;
                if (more <= 0) {
                    // if user do not wanna input, show the history lines
                    std::cout << "u had input:\n";
                    for (const std::string& s : text) {
                        std::cout << s << '\n';
                    }
                }
            }
        }
    } else {
        std::cout << "u don't wanna input string, the program will quit\n";
    }
    // the text vector size and capacity
    std::cout << "text.size(): " << text.size() << '\n';
    std::cout << "text.capacity(): " << text.capacity() << '\n';
    // every line size
    int i{0};
    for (const std::string& s : text) {
        std::cout << "the " << i+1 <<" line size() = " << s.size() <<'\n';
        ++i;
    }
    // filter the prefix_hits start_with xxx
    std::cout << "u wanna filter the prefix_hits start_with xxx? input the prefix_hits, or input 0 to quit\n";
    std::string prefix_hits{};
    std::cin >> prefix_hits;
    std::cin.ignore(10000, '\n');
    int xx{0};
    if (prefix_hits != "0") {
        std::cout << "filtered lines:\n";
        for (const std::string& s : text) {
            if (s.starts_with(prefix_hits)) {
                std::cout << s << '\n';
                ++xx;
            }
        }
        std::cout << "there has " << xx << " lines start_with " << prefix_hits << '\n';
    }
    std::string output = std::format("the lines = {}, the prefix_hits line = {}", text.size(), xx);
    std::cout << output << '\n';
    return 0;
}
