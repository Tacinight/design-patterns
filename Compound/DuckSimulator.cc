#include <iostream>
#include <memory>
#include <vector>
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

class Flock : public Quackable {
public:
    void add(Quackable* quacker) {
        quackers.push_back(quacker);
    }

    void quack() {
        for (auto &pQuacker : quackers) {
            pQuacker->quack();
        }
    }

    void clear() { quackers.clear(); }
    
private:
    vector<Quackable*> quackers;
};

int main() {
    unique_ptr<VirtualDuckFactory> duckFactory(new CountingDuckFactory);

    cout << "Duck Simulator: with Composite - Flocks" << endl;

    Flock flockOfDucks;

    flockOfDucks.add(duckFactory->createMallardDuck());
    flockOfDucks.add(duckFactory->createRedheadDuck());
    flockOfDucks.add(duckFactory->createDuckCall());
    flockOfDucks.add(duckFactory->createRubberDuck());

    Flock flockOfMallards;

    flockOfMallards.add(duckFactory->createMallardDuck());
    flockOfMallards.add(duckFactory->createMallardDuck());
    flockOfMallards.add(duckFactory->createMallardDuck());
    flockOfMallards.add(duckFactory->createMallardDuck());

    flockOfDucks.add(&flockOfMallards);

    cout << "\nDuck Simulator: whole Flock Simulation" << endl;
    simulate(&flockOfDucks);

    cout << "\nDuck Simulator: whole Flock Simulation" << endl;
    simulate(&flockOfMallards);

    cout << "\nThe ducks quacked " + to_string(QuackCounter::getQuacks())
         << " times" << endl;

    flockOfMallards.clear();
    flockOfDucks.clear();
    return 0;
}