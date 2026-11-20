#pragma once

#include <string>

class Order {
private:
    std::string id_;
    int price_;
    int qty_;
public:
    Order(std::string id, int price, int qty);
    void print() const;
    int price() const;
};