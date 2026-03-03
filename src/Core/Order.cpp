#include "Core/Order.h"
#include "Common/Constants.h"

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
