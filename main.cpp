#include <iostream>
#include <memory>
#include <vector>
#include "Core/Order.h"
#include "Core/OrderBook.h"
#include "Core/Trade.h"
#include "Common/Constants.h"

int main() {
    OrderBook mse;

    std::cout << "Populating order book with orders" << std::endl;
    mse.addOrder(std::make_unique<Order>(1, 101, Side::Sell, 100.0, 10)); 
    mse.addOrder(std::make_unique<Order>(2, 101, Side::Sell, 101.0, 20));
    mse.addOrder(std::make_unique<Order>(3, 101, Side::Sell, 102.0, 30));
    mse.addOrder(std::make_unique<Order>(4, 101, Side::Buy, 98.0, 15));
    mse.addOrder(std::make_unique<Order>(5, 101, Side::Buy, 99.0, 5));
    mse.addOrder(std::make_unique<Order>(6, 101, Side::Buy, 102.0, 45));
    mse.displayBook();

    std::cout << "calling matchOrders()" << std::endl;
    std::vector<std::unique_ptr<Trade>> trades = mse.matchOrders();

    std::cout << "Results:" << std::endl;
    if(trades.empty()){
        std::cout << "no trades executed" << std::endl;
    }else{
        for(const auto& t : trades){
            t->printTrade();
        }
    }

    std::cout << "final orderbook state" << std::endl;
    mse.displayBook();

    return 0;
}