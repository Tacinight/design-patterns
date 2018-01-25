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

class QuackCounter : public Quackable {
public:
    QuackCounter(Quackable* duck): duck(duck) {}

    void quack() override {
        duck->quack();
        numberOfQuacks++;
    }

    static int getQuacks() { return numberOfQuacks; }
private:
    Quackable *duck;
    static int numberOfQuacks;
};

void simulate(Quackable* duck) {
    duck->quack();
}

int QuackCounter::numberOfQuacks = 0;

int main() {
    unique_ptr<Quackable> mallardDuck(new QuackCounter(new MallardDuck));
    unique_ptr<Quackable> redheadDuck(new QuackCounter(new RedheadDuck));
    unique_ptr<Quackable> duckCall(new QuackCounter(new DuckCall));
    unique_ptr<Quackable> rebberDuck(new QuackCounter(new RebberDuck));
    unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));

    cout << "Duck Simulator: with Decorator" << endl;

    simulate(mallardDuck.get());
    simulate(redheadDuck.get());
    simulate(duckCall.get());
    simulate(rebberDuck.get());
    simulate(gooseDuck.get());

    cout << "\nThe ducks quacked " + to_string(QuackCounter::getQuacks())
         << " times" << endl;

    return 0;
}