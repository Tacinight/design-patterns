/* Decorator
 * Attach additional responsibilities to an object dynamically.
 * Decorators provides a flexible alternative to subclassing
 * for extending functionality.
 */ 

#include "Starbuzz.h"
#include <iostream>
using namespace std;

int main() {
    Beverage *b = new Espresso();
    cout << b->getDescription() + " $" + to_string(b->cost()) << endl;

    Beverage *b2 = new DarkRoast();
    b2 = new Mocha(b2);
    b2 = new Mocha(b2);
    b2 = new Whip(b2);
    cout << b2->getDescription() + " $" + to_string(b2->cost()) << endl;

    Beverage *b3 = new HouseBlend();
    b3 = new Soy(b3);
    b3 = new Mocha(b3);
    b3 = new Whip(b3);
    cout << b3->getDescription() + " $" + to_string(b3->cost()) << endl;
    return 0;
}