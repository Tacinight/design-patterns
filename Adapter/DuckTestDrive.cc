/* The Adapter Pattern  converts the interface of a class 
* into another interface the clients expect. Adapters lets
* classes work together that couldn't otherwise because of
* incompatible interfaces.
*/
#include <iostream>
#include <memory>
using namespace std;

class Duck {
public:
    virtual void quack() {};
    virtual void fly() {};
};

class MallardDuck : public Duck {
public:
    void quack() override {
        cout << "Quack" << endl;
    }

    void fly() override {
        cout << "I'm flying" << endl;
    }
};

class Turkey {
public:
    virtual void gobble() {};
    virtual void fly() {};
};

class WildTurkey : public Turkey {
public:
    void gobble() override {
        cout << "Gobble gobble" << endl;
    }

    void fly() override {
        cout << "I'm flying a short distance" << endl;
    }
};

class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(Turkey* turkey) {
        this->turkey =  turkey;
    }

    void quack() override {
        turkey->gobble();
    }

    void fly() override {
        for (int i = 0; i < 5; i++) {
            turkey->fly();
        }
    }
private:
    Turkey* turkey;
};

void testDuck(Duck* duck) {
    duck->quack();
    duck->fly();
}

int main() {
    MallardDuck duck;
    WildTurkey turkey;
    unique_ptr<Duck> turkeyAdapter(new TurkeyAdapter(&turkey));

    cout << "The Turkey says" << endl;
    turkey.gobble();
    turkey.fly();

    cout << "\nThe Duck says..." << endl;
    testDuck(&duck);

    cout << "\nThe TurkeyAdapter says..." << endl;
    testDuck(turkeyAdapter.get());

    return 0;
}
