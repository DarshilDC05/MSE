#pragma once
#include <memory>
#include "Core/Order.h"
#include <vector>

class OrderBook {
    private:
        std::vector<std::unique_ptr<Order>> Bids;
        std::vector<std::unique_ptr<Order>> Asks;

    public:
        void addOrder(std::unique_ptr<Order> order);
        void displayBook() const;
};