/*
1. class 或 struct Order：id（int 或 string）、price（int 即可）、qty（int）
2. std::vector<Order> 保存
3. 菜单：
  ○ 增加一笔
  ○ 打印全部
  ○ 按最低价筛选（price >= min）
  ○ 找出并打印最高价那一笔（没有订单就说 empty）
  ○ 退出
4. 价格比较用 > / >= 即可；<=> 可用可不用
5. 不要文件、不要线程、不要新库
*/

#include <iostream>
#include <vector>
#include <string>
#include <format>

// class Order
class Order {
private:
    std::string id_;
    int price_;
    int qty_;
public:
    Order(std::string id, int price, int qty)
        :  id_{std::move(id)}, price_{price}, qty_{qty} {}
    void print() const {
        std::cout << "the Order is " << id_ << ' ' << price_ << ' ' << qty_ << '\n';
    }
    int price() const {
        return price_;
    }
};

int main() {
    std::vector<Order> orders;
    int cmd = -1;

    while (true) {
        std::cout << "1 add  2 print all  3 filter min  4 highest  0 quit\n";
        std::cin >> cmd;

        switch (cmd) {
        case 0:
            return 0;   // 离开 main，不要只 break
        case 1: {
            std::string id;
            int price = 0, qty = 0;
            std::cin >> id >> price >> qty;
            orders.emplace_back(id, price, qty);
            break;
        }
        case 2:
            if (orders.empty()) {
                std::cout << "empty\n";
            } else {
                for (const Order& o : orders) o.print();
            }
            break;
        case 3: {
            int min_price = 0;
            std::cin >> min_price;
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
        default:
            std::cout << "unknown cmd\n";
            break;
        }
    }

    return 0;
}
