#include <iostream>

#include <string>

#include <vector>

 

// Command Interface

class Command {

public:

   // Code here

};

 

// Receiver: Chef

class Chef {

public:

   // Code here

};

 

// Concrete Command: OrderCommand

class OrderCommand : public Command {

   // Code here

};

 

// Invoker: Waiter

class Waiter {

// Code here

};

int main() {

   Chef chef;

   Waiter waiter;

 

   // Initial orders

   OrderCommand* order1 = new OrderCommand(chef, "Pasta");

   OrderCommand* order2 = new OrderCommand(chef, "Steak");

 

   // Place initial orders

   waiter.placeOrder(order1);

   waiter.placeOrder(order2);

 

   // Modify the first order

   OrderCommand* modifiedOrder = new OrderCommand(chef, "Pizza");

   waiter.modifyOrder(modifiedOrder, 0);

   // Cancel the second order

   waiter.cancelOrder(1);

   // Display order history

   std::cout << "\nOrder History:\n";

   for (const auto& order : waiter.getOrderHistory()) {

       std::cout << "Order: ";

       order->execute();

   }

   delete order1;

   delete order2;

   delete modifiedOrder;

   return 0;

}