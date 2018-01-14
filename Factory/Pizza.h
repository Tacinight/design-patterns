#ifndef _PIZZA_H
#define _PIZZA_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Pizza {
protected:
    string name;
    string dough;
    string sauce;
    vector<string> toppings;
public:
    void prepare() {
        cout << "Preparing " + name << endl
             << "Tossing dough..." <<endl
             << "Adding sauce..." << endl;
        for (auto &str : toppings)
            cout << str << endl;
    }
    void bake() {
        cout << "Bake for 25 minutes at 350" << endl;
    }
    virtual void cut() {
        cout << "Cutting the pizza into diagonal slices" << endl;
    }
    void box() {
        cout << "Place pizza in official PizzaStore box" << endl;
    }
    string getName() {
        return name;
    }
};

class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza() {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";

        toppings.push_back("Grated Reggiano Cheese");
    }
};

class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza() {
        name = "Chicage Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";

        toppings.push_back("Shredded Mozzarella Cheese");
    }
    void cut() {
        cout << "Cutting the Pizza into square slices" << endl;
    }
};

class PizzaStore {
public:
    Pizza* orderPizza(string type) {
        Pizza* pizza;
        pizza = createPizza(type);
        
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        
        return pizza;
    }
    virtual Pizza* createPizza(string type) {};
};

class NYPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(string type) {
        if (type == "cheese")
            return new NYStyleCheesePizza();
        else
            return nullptr;
    }
};

class ChicagoPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(string type) {
        if (type == "cheese")
            return new ChicagoStyleCheesePizza();
        else
            return nullptr;
    }
};

#endif