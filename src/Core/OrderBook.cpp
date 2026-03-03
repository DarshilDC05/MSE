#include "Core/OrderBook.h"
#include "Common/Constants.h"
#include "iostream"

void OrderBook::addOrder(std::unique_ptr<Order> order){
    if(order->getSide() == Side::Buy){
        Bids.push_back(std::move(order));
    }else{
        Asks.push_back(std::move(order));
    }
}

void OrderBook::displayBook() const{
    std::cout << "Bids :" << std::endl;
    for(auto &x : Bids){
        x->printOrder();
    }
    std::cout << std::endl;
    std::cout << "Asks :" << std::endl;
    for(auto &x : Asks){
        x->printOrder();
    }
}