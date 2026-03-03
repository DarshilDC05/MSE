#include <iostream>
#include "Common/Constants.h"
#include "Core/Order.h"

int main(){
    Order myOrder{101, 1, Side::Buy, 150.5, 10};
    std::cout << "Order price = " << myOrder.getPrice() << std::endl;
    std::cout << "Order quantity = " << myOrder.getQuantity() << std::endl;
    return 0;
}