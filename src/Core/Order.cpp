#include "Core/Order.h"
#include "Common/Constants.h"
#include <iostream>

Order::Order(long int ID, int instrumentID, Side side, long double price, long int quantity):
    m_orderID {ID},
    m_instrumentID {instrumentID},
    m_side {side},
    m_price {price},
    m_quantity {quantity},
    m_timestamp {std::chrono::system_clock::now()}
{

}

long double Order::getPrice() const{
    return m_price;
}

long int Order::getQuantity() const{
    return m_quantity;
}

long int Order::getInstrumentID() const{
    return m_instrumentID;
}

long int Order::getOrderID() const{
    return m_orderID;
}

Side Order::getSide() const{
    return m_side;
}

std::chrono::system_clock::time_point Order::getOrderTime() const{
    return m_timestamp;
}

void Order::printOrder() const{
    std::cout << "OrderID=" << getOrderID() << "\t| InstrumentID=" << getInstrumentID() << " \t| Price=" << getPrice()
    << "\t| Quantity=" << getQuantity() << "\t| Time=" << getOrderTime() << std::endl;
}

void Order::fill(long int quantity){
    m_quantity -= quantity;
}