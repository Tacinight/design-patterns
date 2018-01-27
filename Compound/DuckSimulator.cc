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

class RubberDuck : public Quackable {
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

class VirtualDuckFactory {
public:
    virtual Quackable* createMallardDuck() {};
    virtual Quackable* createRedheadDuck() {};
    virtual Quackable* createDuckCall() {};
    virtual Quackable* createRubberDuck() {};
};

class DuckFactory : public VirtualDuckFactory {
public:
    Quackable* createMallardDuck() override { return new MallardDuck; }
    Quackable* createRedheadDuck() override { return new RedheadDuck; }
    Quackable* createDuckCall() override { return new DuckCall; }
    Quackable* createRubberDuck() override { return new RubberDuck; }
};

class CountingDuckFactory : public VirtualDuckFactory {
public:
    Quackable* createMallardDuck() override { 
        return new QuackCounter(new MallardDuck); 
    }
    Quackable* createRedheadDuck() override { 
        return new QuackCounter(new RedheadDuck); 
    }
    Quackable* createDuckCall() override { 
        return new QuackCounter(new DuckCall);
    }
    Quackable* createRubberDuck() override { 
        return new QuackCounter(new RubberDuck);
    }
};

int main() {
    unique_ptr<VirtualDuckFactory> duckFactory(new CountingDuckFactory);
    unique_ptr<Quackable> mallardDuck(duckFactory->createMallardDuck());
    unique_ptr<Quackable> redheadDuck(duckFactory->createRedheadDuck());
    unique_ptr<Quackable> duckCall(duckFactory->createDuckCall());
    unique_ptr<Quackable> rubberDuck(duckFactory->createRubberDuck());
    unique_ptr<Quackable> gooseDuck(new GooseAdapter(new Goose));

    cout << "Duck Simulator: with Decorator" << endl;

    simulate(mallardDuck.get());
    simulate(redheadDuck.get());
    simulate(duckCall.get());
    simulate(rubberDuck.get());
    simulate(gooseDuck.get());

    cout << "\nThe ducks quacked " + to_string(QuackCounter::getQuacks())
         << " times" << endl;

    return 0;
}