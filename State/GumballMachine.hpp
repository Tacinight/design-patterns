#ifndef _GUMBALLMACHINE_
#define _GUMBALLMACHINE_

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class State {
public:
    virtual ~State() = 0;
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

State::~State() {};

class GumballMachine {
public:
    GumballMachine(int numberGumballs);

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void setState(State* state);
    void realseBall();

    State* getHasQuarterState() { return hasQuarterState; }
    State* getNoQuarterState() { return noQuarterState; }
    State* getSoldOutState() { return soldOutState; }
    State* getSoldState() { return soldState; }

    int getCount() { return count; }
    void toString();

private:
    State* soldOutState;
    State* noQuarterState;
    State* hasQuarterState;
    State* soldState;

    State* state;
    int count = 0;
};

#endif