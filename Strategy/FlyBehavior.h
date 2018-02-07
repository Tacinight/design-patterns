#ifndef _FLYBEHAVIOR_H
#define _FLYBEHAVIOR_H

class FlyBehavior {
public:
    virtual ~FlyBehavior() {};
    virtual void fly() = 0;
};

#endif