#include "order.hpp"
#include <iostream>
#include <utility>

Order::Order(std::string id, int price, int qty)
    : id_{std::move(id)}, price_{price}, qty_{qty} {}
void Order::print() const {
    std::cout << "the Order is " << id_ << ' ' << price_ << ' ' << qty_ << '\n';
}
int Order::price() const {
    return price_;
}