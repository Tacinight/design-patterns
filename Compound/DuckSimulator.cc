#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class QuackObservable;

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(QuackObservable* duck) {};
};

class QuackObservable {
public:
    virtual ~QuackObservable() {};
    virtual void registerObserver(Observer* observer) {};
    virtual void notifyObserver() {};
    virtual string toString() { return ""; }
};

class Quackologist : public Observer {
public:
    void update(QuackObservable* duck) override {
        cout << "Quackologist: " + duck->toString() + " just quacked" << endl;
    }
};



class Quackable : public QuackObservable {
public:
    virtual ~Quackable() {};
    virtual void quack() {};
};

class Observable : public QuackObservable {
public:
    Observable(QuackObservable* duck): duck(duck) {}

    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void notifyObserver() override {
        for (auto &observer : observers) {
            observer->update(duck);
        }
    }
private:
    vector<Observer*> observers;
    QuackObservable* duck;
};

class MallardDuck : public Quackable {
public:
    MallardDuck() {
        observable = new Observable(this);
    }

    void quack() override {
        cout << "Quack" << endl;
        notifyObserver();
    }

    string toString() override { return "Mallard Duck"; }

    void registerObserver(Observer* observer) override {
        observable->registerObserver(observer);
    }

    void notifyObserver() override {
        observable->notifyObserver();
    }

private:
    Observable* observable;
};

class RedheadDuck : public Quackable {
public:
    RedheadDuck() {
        observable = new Observable(this);
    }

    void quack() override { 
        cout << "Quack" << endl;
        notifyObserver(); 
    }

    string toString() override { return "Redhead Duck"; }

    void registerObserver(Observer* observer) override {
        observable->registerObserver(observer);
    }

    void notifyObserver() override {
        observable->notifyObserver();
    }

private:
    Observable* observable;
};

class DuckCall : public Quackable {
public:
    DuckCall() {
        observable = new Observable(this);
    }

    void quack() override { 
        cout << "Kwak" << endl;
        notifyObserver();
    }

    string toString() override { return "Duck Call"; }

    void registerObserver(Observer* observer) override {
        observable->registerObserver(observer);
    }

    void notifyObserver() override {
        observable->notifyObserver();
    }

private:
    Observable* observable;
};

class RubberDuck : public Quackable {
public:
    RubberDuck() {
        observable = new Observable(this);
    }

    void quack() override { 
        cout << "Squeak" << endl;
        notifyObserver();
        
    }

    string toString() override { return "Rubber Duck"; }

    void registerObserver(Observer* observer) override {
        observable->registerObserver(observer); 
    }

    void notifyObserver() override {
        observable->notifyObserver();
    }

private:
    Observable* observable;
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

    void registerObserver(Observer* observer) override {
        duck->registerObserver(observer); 
    }

    void notifyObserver() override {
        duck->notifyObserver();
    }

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

    void quack() override {
        for (auto &quacker : quackers) {
            quacker->quack();
        }
    }

    void registerObserver(Observer* observer) override {
        for (auto &quacker: quackers) {
            quacker->registerObserver(observer);
        }
    }

    void clear() { quackers.clear(); }
    
private:
    vector<Quackable*> quackers;
};

int main() {
    unique_ptr<VirtualDuckFactory> duckFactory(new CountingDuckFactory);

    cout << "Duck Simulator: with Observer" << endl;

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

    unique_ptr<Quackologist> quackologist(new Quackologist);
    flockOfDucks.registerObserver(quackologist.get());

    cout << "\nDuck Simulator: whole Flock Simulation" << endl;
    simulate(&flockOfDucks);

    cout << "\nDuck Simulator: Mallardards Simulation" << endl;
    simulate(&flockOfMallards);

    cout << "\nThe ducks quacked " + to_string(QuackCounter::getQuacks())
         << " times" << endl;

    flockOfMallards.clear();
    flockOfDucks.clear();
    return 0;
}