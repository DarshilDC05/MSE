#include <iostream>
#include <memory>
#include "Core/Order.h"
#include "Core/OrderBook.h"
#include "Common/Constants.h"

int main() {
    OrderBook myBook;
    auto buy1 = std::make_unique<Order>(1, 101, Side::Buy, 100.50, 10);
    auto buy2 = std::make_unique<Order>(2, 101, Side::Buy, 100.75, 20);
    auto sell1 = std::make_unique<Order>(3, 101, Side::Sell, 101.00, 15);
    auto sell2 = std::make_unique<Order>(4, 101, Side::Sell, 101.25, 25);
    myBook.addOrder(std::move(buy1));
    myBook.addOrder(std::move(buy2));
    myBook.addOrder(std::move(sell1));
    myBook.addOrder(std::move(sell2));
    myBook.displayBook();
    return 0;
}