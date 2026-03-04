#include <chrono>
#include "Core/Trade.h"
#include <iostream>

Trade::Trade(long int buyerID, long int sellerID, long double tradePrice, long int tradeQuantity):
    m_buyerID {buyerID},
    m_sellerID {sellerID},
    m_tradePrice {tradePrice},
    m_tradeQuantity {tradeQuantity},
    m_tradeTimestamp {std::chrono::system_clock::now()}
    {
    }

long int Trade::getBuyerID() const{
    return m_buyerID;
}

long int Trade::getSellerID() const{
    return m_sellerID;
}

long int Trade::getTradeQuantity() const{
    return m_tradeQuantity;
}

long double Trade::getTradePrice() const{
    return m_tradePrice;
}

std::chrono::system_clock::time_point Trade::getTradeTime() const{
    return m_tradeTimestamp;
}

void Trade::printTrade() const{
    std::cout << "BuyerID=" << getBuyerID() << "\t| SellerID=" << getSellerID() << 
    "\t| Price=" << getTradePrice() << "\t| Quantity=" << getTradeQuantity() << "\t| Time=" << getTradeTime() << std::endl;
}