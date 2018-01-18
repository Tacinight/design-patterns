/* The Factory Method Pattern defines an interface
 * creating an object, but lets subclasses decide
 * which class to instantiate. Factory Methods lets
 * a class defer instantiation to subclasses.
 *
 * The Dependency Inversion Principle
 * Depend upon abstractions. Do not depend upon
 * concrete class.
 */
#include "PizzaIngredient.cc"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pizza {
protected:
    string name;
    string dough;
    string sauce;
    string cheese;
    string clam;
    string pepperoni;
    vector<string> veggies;

public:
    virtual ~Pizza() {};
    explicit Pizza(PizzaIngredientFactory* ingredientFactory) {
        this->ingredientFactory = ingredientFactory;
    }
    virtual void prepare() {
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        cout << "Preparing " + name << endl
             << "Tossing " + dough << endl
             << "Adding " + sauce << endl;
    };
    void bake() { cout << "Bake for 25 minutes at 350" << endl; }
    virtual void cut() {
        cout << "Cutting the pizza into diagonal slices" << endl;
    }
    void box() { cout << "Place pizza in official PizzaStore box" << endl; }
    string getName() { return name; }

protected:
    PizzaIngredientFactory* ingredientFactory;
};

class CheesePizza : public Pizza {
public:
    ~CheesePizza() {};
    explicit CheesePizza(PizzaIngredientFactory* ingredientFactory)
      : Pizza(ingredientFactory) {
        name = ingredientFactory->style() + " Cheese Pizza";
    }
};

class ClamPizza : public Pizza {
public:
    ~ClamPizza() {};
    explicit ClamPizza(PizzaIngredientFactory* ingredientFactory)
      : Pizza(ingredientFactory) {
        name = ingredientFactory->style() + " Clam Pizza";
    }
    void prepare() override {
        Pizza::prepare();
        clam = ingredientFactory->createClam();
        cout << "Adding " + clam << endl;
    }
    void cut() { cout << "Cutting the Pizza into square slices" << endl; }
};

class PizzaStore {
public:
    virtual ~PizzaStore() {};
    Pizza* orderPizza(string type) {
        Pizza* pizza;
        pizza = createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual Pizza* createPizza(string type) { return nullptr; }
};

class NYPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(string type) {
        if (type == "cheese")
            return new CheesePizza(ingredientFactory);
        else if (type == "clam")
            return new ClamPizza(ingredientFactory);
        else
            return nullptr;
    }

private:
    PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory;
};

class ChicagoPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(string type) {
        if (type == "cheese")
            return new CheesePizza(ingredientFactory);
        else if (type == "clam")
            return new ClamPizza(ingredientFactory);    
        else
            return nullptr;
    }

private:
    PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory;
};
