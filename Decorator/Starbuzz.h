#ifndef _STARBUZZ_H
#define _STARBUZZ_H

#include <string>
using std::string;

class Beverage {
protected:
    string description = "Unknown Beverage";
public:
    virtual string getDescription() {
        return description;
    }
    virtual double cost() {};
};

class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() {};
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }
    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }
    double cost() {
        return 0.89;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        description = "Decaf Coffee";
    }
    double cost() {
        return 1.05;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }
    double cost() {
        return 0.99;
    }
};

class Mocha : public CondimentDecorator {
private:
    Beverage *beverage;
public:
    Mocha(Beverage *b) {
        this->beverage = b;
    }
    string getDescription() {
        return beverage->getDescription() + ", Mocha";
    }
    double cost() {
        return 0.20 + beverage->cost();
    }
};

class Soy : public CondimentDecorator {
private:
    Beverage *beverage;
public:
    Soy(Beverage *b) {
        this->beverage = b;
    }
    string getDescription() {
        return beverage->getDescription() + ", Soy";
    }
    double cost() {
        return 0.15 + beverage->cost();
    }
};

class SteamedMilk : public CondimentDecorator {
private:
    Beverage *beverage;
public:
    SteamedMilk(Beverage *b) {
        this->beverage = b;
    }
    string getDescription() {
        return beverage->getDescription() + ", Steamed Milk";
    }
    double cost() {
        return 0.10 + beverage->cost();
    }
};

class Whip : public CondimentDecorator {
private:
    Beverage *beverage;
public:
    Whip(Beverage *b) {
        this->beverage = b;
    }
    string getDescription() {
        return beverage->getDescription() + ", Whip";
    }
    double cost() {
        return 0.10 + beverage->cost();
    }
};

#endif