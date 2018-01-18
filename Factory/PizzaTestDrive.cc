#include "Pizza.cc"
#include <iostream>
#include <memory>
using namespace std;
int main() {
    PizzaStore *nyStore = new NYPizzaStore;
    PizzaStore *chicagoStore = new ChicagoPizzaStore;

    unique_ptr<Pizza> cheesePizza (nyStore->orderPizza("cheese"));
    cout << "Ethan ordered a " + cheesePizza->getName() << endl << endl;

    unique_ptr<Pizza> clamPizza (chicagoStore->orderPizza("clam"));
    cout << "Joel ordered a " + clamPizza->getName() << endl;
    
    return 0;

}