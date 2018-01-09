#ifndef _MALLARDDUCK_H
#define _MALLARDDUCK_H

#include "Duck.h"
#include "Quack.h"
#include "FlyWithWinds.h"

class MallardDuck : public Duck {
public:
    MallardDuck();
    void display();
};

#endif