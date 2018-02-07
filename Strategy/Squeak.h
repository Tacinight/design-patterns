#ifndef _SQUEAK_H
#define _SQUEAK_H

#include "QuackBehavior.h"

class Squeak : public QuackBehavior {
public:
    void quack() override;
};

#endif