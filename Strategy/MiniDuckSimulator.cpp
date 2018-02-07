/* Strategy
 * defines a family of algorithms, encapsulate each one,
 * and makes them interchangeable. Strategy lets the
 * algorithm vary independently from clients that use it.
 */ 

#include "Duck.h"
#include "MallardDuck.h"
#include "ModelDuck.h"
#include "FlyRocketPowered.h"

int main() {
    Duck *mallard = new MallardDuck;
    mallard->performQuack();
    mallard->performFly();

    Duck *model = new ModelDuck;
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered);
    model->performFly();

    return 0;
}

/* OO Basics
 * 
 * Abstraction
 * Encapsulation
 * Polymorphism
 * Inheritance
 */

/* OO Principles
 * 
 * Encapsulate what varies
 * Favor composition over inheritence
 * Program to interfaces, not implementation
 */  