#ifndef _MODELDUCK_H
#define _MODELDUCK_H

#include "Duck.h"
#include "FlyNoWay.h"
#include "Quack.h"

class ModelDuck : public Duck {
public:
    ModelDuck();
    void display() override;
};

#endif