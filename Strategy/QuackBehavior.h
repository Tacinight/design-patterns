#ifndef _QUACKBEHAVIOR_H
#define _QUACKBEHAVIOR_H

class QuackBehavior {
public:
    virtual ~QuackBehavior() {};
    virtual void quack() = 0;
};

#endif