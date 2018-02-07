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
    virtual void quack() const {};
    virtual void fly() const {};
};

class MallardDuck : public Duck {
public:
    void quack() const override { cout << "Quack" << endl; }
    void fly() const override { cout << "I'm flying" << endl; }
};

class Turkey {
public:
    virtual void gobble() const {};
    virtual void fly() const {};
};

class WildTurkey : public Turkey {
public:
    void gobble() const override { cout << "Gobble gobble" << endl; }
    void fly() const override { cout << "I'm flying a short distance" << endl; }
};

class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(Turkey* turkey) { this->turkey =  turkey; }
    void quack() const override { turkey->gobble(); }

    void fly() const override {
        for (int i = 0; i < 5; i++) {
            turkey->fly();
        }
    }
    
private:
    Turkey* turkey;
};

void testDuck(const Duck* duck) {
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
