#pragma once
#include <memory>
#include "Core/Order.h"
#include "Core/Trade.h"
#include <vector>

class OrderBook {
    private:
        std::vector<std::unique_ptr<Order>> m_bids;
        std::vector<std::unique_ptr<Order>> m_asks;

    public:
        void addOrder(std::unique_ptr<Order> order);
        void displayBook() const;
        std::vector<std::unique_ptr<Trade>> matchOrders();

};