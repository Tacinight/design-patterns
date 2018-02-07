/* The State Pattern
 * allows an object to alter its behavior when its internal
 * state changes. The object will appear to change its class.
 */ 
#include "GumballMachine.hpp"

class NoQuarterState : public State {
public:
    NoQuarterState(GumballMachine* p): pMachine(p) {}

    void insertQuarter() override {
        cout << "You inserted a quarter" << endl;
        pMachine->setState(pMachine->getHasQuarterState());
    }

    void ejectQuarter() override {
        cout << "You Haven't inserted a quarter" << endl;
    }

    void turnCrank() override {
        cout << "You turned, but there's no quarter" << endl;
    }

    void dispense() override {
        cout << "You need to pay first" << endl;
    }
private:
    GumballMachine* pMachine;
};

class HasQuarterState : public State {
public:
    HasQuarterState(GumballMachine* p): pMachine(p) {}

    void insertQuarter() override {
        cout << "You can't insert another quarter" << endl;
    }

    void ejectQuarter() override {
        cout << "Quarter returned" << endl;
        pMachine->setState(pMachine->getNoQuarterState());
    }

    void turnCrank() override {
        cout << "You turned... " << endl;
        pMachine->setState(pMachine->getSoldState());
    }
    
    void dispense() override {
        cout << "No gunball dispensed" << endl;
    }
private:
    GumballMachine* pMachine;
};

class SoldState : public State {
public:
    SoldState(GumballMachine* p): pMachine(p) {}

    void insertQuarter() override {
        cout << "Please wait, we're already giving you a gumball" << endl;
    }

    void ejectQuarter() override {
        cout << "Sorry, you already turned the crank" << endl;
    }

    void turnCrank() override {
        cout << "Turning twice doesn't get you another gumball" << endl;
    }
    
    void dispense() override {
        pMachine->realseBall();
        if (pMachine->getCount() > 0) {
            pMachine->setState(pMachine->getNoQuarterState());
        } else {
            cout << "Oops, out of gumballs" << endl;
            pMachine->setState(pMachine->getSoldState());
        }
    }
private:
    GumballMachine* pMachine;
};

class SoldOutState : public State {
public:
    SoldOutState(GumballMachine* p): pMachine(p) {}

    void insertQuarter() override {
        cout << "You can't insert a quarter, the machine is sold out" << endl;
    }

    void ejectQuarter() override {
        cout << "You can't eject, you haven't inserted a quarter yet" << endl;
    }

    void turnCrank() override {
        cout << "You turned, but there are no gumballs" << endl;
    }
    
    void dispense() override {
        cout << "No gumball dispensed" << endl;
    }
private:
    GumballMachine* pMachine;
};


GumballMachine::GumballMachine(int numberGumballs) {
    soldOutState = new SoldOutState(this);
    noQuarterState = new NoQuarterState(this);
    hasQuarterState = new HasQuarterState(this);
    soldState = new SoldState(this);
    count = numberGumballs;
    
    if (count > 0) {
        state = noQuarterState;
    } else {
        state = soldOutState;
    }
}

void GumballMachine::insertQuarter() { state->insertQuarter(); }

void GumballMachine::ejectQuarter() { state->ejectQuarter(); }

void GumballMachine::turnCrank() { 
    state->turnCrank();
    state->dispense();
}

void GumballMachine::setState(State* state) { this->state = state; }

void GumballMachine::realseBall() {
    cout << "A gumball comes rolling out the slot... " << endl;
    if (count != 0) {
        count --;
    }
}

void GumballMachine::toString() {
    cout << endl << "Might Gumball, Inc." << endl
            << "C++-enabled Standing Gumball Model #1006" << endl
            << "Inventory: " + to_string(count) + " gumballs" << endl
            << "Machine is waiting for quarter" << endl << endl;
}

int main() {
    unique_ptr<GumballMachine> gumballMachine(new GumballMachine(5));

    gumballMachine->toString();

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    gumballMachine->toString();

    gumballMachine->insertQuarter();
    gumballMachine->ejectQuarter();
    gumballMachine->turnCrank();

    gumballMachine->toString();    

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->ejectQuarter();

    gumballMachine->toString(); 

    gumballMachine->insertQuarter();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    gumballMachine->toString(); 

    return 0;
}