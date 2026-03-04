#pragma once
#include <chrono>
#include "Common/Constants.h"

class Order{
    private:
        long int m_orderID;
        int m_instrumentID;
        Side m_side;
        long double m_price;
        long int m_quantity;
        std::chrono::system_clock::time_point m_timestamp;

    public:
        Order(long int orderID, int instrumentID, Side side, long double price, long int quantity);
        // getter methods for private variables
        long double getPrice() const;
        long int getInstrumentID() const;
        long int getQuantity() const;
        long int getOrderID() const;
        Side getSide() const;
        std::chrono::system_clock::time_point getOrderTime() const;
        void printOrder() const;
        void fill(long int quantity);
};
