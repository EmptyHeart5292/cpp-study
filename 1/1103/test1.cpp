#include <sstream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input{"data/quotes.txt"};
    if (!input) {
        std::cout << "file error\n";
    }
    std::string line;
    std::istringstream row{line};
    while (std::getline(input, line) {
        std::cout << line << '\n';
        std::cout << row << '\n';	
    }
    

}
