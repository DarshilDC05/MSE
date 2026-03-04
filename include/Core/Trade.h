#pragma once
#include <chrono>

class Trade{
    private:
        long int m_buyerID;
        long int m_sellerID;
        long double m_tradePrice;
        long int m_tradeQuantity;
        std::chrono::system_clock::time_point m_tradeTimestamp;

    public:
        Trade(long int buyerID, long int sellerID, long double tradePrice, long int tradeQuantity);
        long int getBuyerID() const;
        long int getSellerID() const;
        long int getTradeQuantity() const;
        long double getTradePrice() const;
        std::chrono::system_clock::time_point getTradeTime() const;
        void printTrade() const;
};