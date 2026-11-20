#include "order.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <cassert>

int main() {
    std::vector<Order> orders;
    int cmd{};
    while (true) {
        std::cout << "1 add 2 print 3 filter min 4 highest 0 quit\n";
        if (!(std::cin >> cmd)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "unknown\n";
            continue;
        }
        switch (cmd) {
            case 0:
                return 0;
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "input the order id price qty: ";
                std::string line;
                if (!std::getline(std::cin, line)) {
                    std::cout << "bad order\n";
                    break;
                }
                std::istringstream in(line);
                std::string id;
                int price{0};
                int qty{0};
                std::string extra;
                if (!(in >> id >> price >> qty) || (in >> extra)) {
                    std::cout << "bad order\n";
                    break;
                }
                orders.emplace_back(id, price, qty);
                break;
            }
            case 2: {
                if (orders.empty()) {
                    std::cout << "empty\n";
                } else {
                    for (const Order& o : orders) o.print();
                }
                break;
            }
            case 3: {
                int min_price{0};
                std::cout << "input the min-price: ";
                if (!(std::cin >> min_price)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "bad min-price\n";
                    break;
                }
                for (const Order& o : orders) {
                    if (o.price() >= min_price) o.print();
                }
                break;
            }
            case 4: {
                if (orders.empty()) {
                    std::cout << "empty\n";
                    break;
                }
                std::vector<Order> highest_orders;
                for (const Order& o : orders) {
                    if (highest_orders.empty() || o.price() > highest_orders.front().price()) {
                        highest_orders.clear();
                        highest_orders.push_back(o);
                    } else if (o.price() == highest_orders.front().price()) {
                        highest_orders.push_back(o);
                    }
                }
                for (const Order& o : highest_orders) o.print();
                
                

                break;
            }
            default: {
                std::cout << "unknown\n";
                break;
            }
        }
    }
    return 0;
}