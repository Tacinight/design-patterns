#ifndef _DUCK_H
#define _DUCK_H

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

using namespace std;

class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;
public:
    virtual ~Duck() {};
    virtual void display() = 0;
    void performFly();
    void performQuack();
    void swim();
    void setFlyBehavior(FlyBehavior* fb);
    void setQuackBehavior(QuackBehavior* qb);
};

#endif