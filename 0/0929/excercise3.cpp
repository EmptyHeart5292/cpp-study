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
    // initial variables
    std::vector<Order> order{};
    int cmd{-1};
    std::string id{};
    int price{};
    int qty{};
    std::string sort{"0"};
    int min;
    int highest{-1};
    // ask for new orders
    std::cout << "if u wanna new a order, input 1 new, if not input 0 quit\n";
    std::cin >> cmd;
    // new orders
    while (true) {
        std::cout << "input the id ";
        std::cin >> id;
        std::cout << "\ninput the price ";
        std::cin >> price;
        std::cout << "\ninput the qty: ";
        std::cin >> qty;
        order.emplace_back(id, price, qty);
        // print all orders after every time new a order
        int i{0};
        for (const Order& o : order) {
            std::cout << "the order[" << i << "] is: ";
            o.print();
            // or use: o.print; but will not show the serial
            ++i;
        }
        // ask for new or not
        std::cout << "if u wanna continue new a order, input 1 continue, if not input 0 quit\n";
        std::cin >> cmd;
        if (cmd <= 0) {
            break;
        }
    }
    // if sort:
    std::cout << "if u wanna sort the orders by low->high, u can input sort\n";
    std::cin >> sort;
    while (sort == "sort") {
        // if filter the price >= min;
        std::cout << "what is the min price u wanna filter like price >= min\n";
        std::cin >> min;
        for (const Order& o : order) {
            if (o.price() >= min) {
                o.print();
            }
        }
        // if wanna know the highest order:
        std::cout << "if u wannna know the highest order, print 1 to sort, if not, print 0 quit\n";
        std::cin >> highest;
        if (highest >= 1) {
            std::vector<Order> test{};
            for (const Order& o : order){
                if (test.empty() || o.price() > test.front().price()) {
                // test.empty() or test.size() == 0 to confirm the test is empt
                    test.clear();
                    test.emplace_back(o);
                } else if (o.price() == test.front().price()) {
                    test.emplace_back(o);
                }
            }
            std::cout << "highest price order:\n";
            for (const Order& o : test) {
                o.print();
            }
        }
        // if the user wanna continue sort
        std::cout << "if u wanna continue sort the orders,input sort, or others to quit\n";
        std::cin >> sort;
    }

    return 0;
}
