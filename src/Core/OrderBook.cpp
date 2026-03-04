#include "Core/OrderBook.h"
#include "Common/Constants.h"
#include "iostream"
#include <algorithm>


// optimize the sorting later on
void OrderBook::addOrder(std::unique_ptr<Order> order){
    if(order->getSide() == Side::Buy){
        m_bids.push_back(std::move(order));
        std::sort(m_bids.begin(), m_bids.end(), 
            [](const auto& o1, const auto& o2) -> bool {
                if(o1->getPrice() == o2->getPrice()){
                    return o1->getOrderTime() < o2->getOrderTime();
                }
                return o1->getPrice() > o2->getPrice();
            }
        );
    }else{
        m_asks.push_back(std::move(order));
        std::sort(m_asks.begin(), m_asks.end(), 
            [](const auto& o1, const auto& o2) -> bool {
                if(o1->getPrice() == o2->getPrice()){
                    return o1->getOrderTime() < o2->getOrderTime();
                }
                return o1->getPrice() < o2->getPrice();
            }
        );
    }
}

void OrderBook::displayBook() const{
    std::cout << "Bids :" << std::endl;
    for(auto &x : m_bids){
        x->printOrder();
    }
    std::cout << std::endl;
    std::cout << "Asks :" << std::endl;
    for(auto &x : m_asks){
        x->printOrder();
    }
}

// improve the price logic later
std::vector<std::unique_ptr<Trade>> OrderBook::matchOrders(){
    std::vector<std::unique_ptr<Trade>> trades;
    while(!(m_bids.empty() || m_asks.empty())){
        auto &buyer = *m_bids.front();
        auto &seller = *m_asks.front();
        if(buyer.getPrice() >= seller.getPrice()){
            long int quantity = std::min(buyer.getQuantity(), seller.getQuantity());
            std::unique_ptr<Trade> trade = std::make_unique<Trade>(buyer.getOrderID(), seller.getOrderID(), seller.getPrice(), quantity);
            trades.push_back(std::move(trade));
            buyer.fill(quantity);
            seller.fill(quantity);
            if(buyer.getQuantity() == 0){
                m_bids.erase(m_bids.begin());
            }
            if(seller.getQuantity() == 0){
                m_asks.erase(m_asks.begin());
            }
        }else{
            break;
        }
    }
    return trades;
}