#include <iostream>
#include <memory>
using namespace std;

class Quackable {
public:
    virtual void quack() {}
};

class MallardDuck : public Quackable {
public:
    void quack() override { cout << "Quack" << endl; }
};

class RedheadDuck : public Quackable {
public:
    void quack() override { cout << "Quacl" << endl; }
};

class DuckCall : public Quackable {
public:
    void quack() override { cout << "Kwak" << endl; }
};

class RebberDuck : public Quackable {
public:
    void quack() override { cout << "Squeak" << endl; }
};

class Goose {
public:
    void honk() { cout << "Honk" << endl; }
};

class GooseAdapter : public Quackable {
public:
    GooseAdapter(Goose *goose): goose(goose) {}
    void quack() override { goose->honk(); }
private:
    Goose* goose;
};

void simulate(Quackable* duck) {
    duck->quack();
}

int main() {
    unique_ptr<Quackable> mallardDuck(new MallardDuck);
    unique_ptr<Quackable> redheadDuck(new RedheadDuck);
    unique_ptr<Quackable> duckCall(new DuckCall);
    unique_ptr<Quackable> rebberDuck(new RebberDuck);
    unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));

    cout << "Duck Simulator" << endl;

    simulate(mallardDuck.get());
    simulate(redheadDuck.get());
    simulate(duckCall.get());
    simulate(rebberDuck.get());
    simulate(gooseDuck.get());

    return 0;
}