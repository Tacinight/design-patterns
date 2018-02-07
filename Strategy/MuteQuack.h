#ifndef _MUTAQUACK_H
#define _MUTAQUACK_H

#include "QuackBehavior.h"

class MuteQuack : public QuackBehavior {
public:
    void quack() override;
};

#endif