
#include <iostream>
#include <vector>

using namespace std;

string ThinCrustDought() { return "Thin Crust Dough"; }
string MarinaraSauce() { return "Marinara Sauce"; }
string ReggianoCheese() { return "Reggiano Cheese"; }
string SlicedPepperoni() { return "Sliced Pepperoni"; }
string FreshClams() { return "Fresh Clams"; }
string Garlic() { return "Garlic"; }
string Onion() { return "Onion"; }
string Musshroom() { return "Musshroom"; }
string RedPepper() { return "RedPepper"; }

string ThickCrustDought() { return "Extra Thick Crust Dough"; }
string PlumTomatoSauce() { return "Plum Tomato Sauce"; }
string MozzarellaCheese() { return "Mozzarella Cheese"; }
string FronzenClams() { return "Fronzen Clams"; }
string Spinach() { return "Spinach"; }
string BlackOlives() { return "BlackOlives"; }
string EggPlant() { return "EggPlant"; }

class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() {};
    virtual string createDough() { return ""; }
    virtual string createSauce() { return ""; }
    virtual string createCheese() { return ""; }
    virtual vector<string> createVeggies() { return vector<string> {}; }
    virtual string createPepperoni() { return ""; }
    virtual string createClam() { return ""; }
    virtual string style() { return "common"; }
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    string createDough() override { return ThinCrustDought(); }
    string createSauce() override { return MarinaraSauce(); }
    string createCheese() override { return ReggianoCheese(); }
    vector<string> createVeggies() override {
        vector<string> veggies { Garlic(), Onion(), Musshroom(), RedPepper() };
        return veggies;
    }
    string createPepperoni() override { return SlicedPepperoni(); }
    string createClam() override { return FreshClams();}
    string style() override { return "NY Style"; }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    string createDough() override { return ThickCrustDought(); }
    string createSauce() override { return PlumTomatoSauce(); }
    string createCheese() override { return MozzarellaCheese(); }
    vector<string> createVeggies() override {
        vector<string> veggies { Spinach(), BlackOlives(), EggPlant()};
        return veggies;
    }
    string createPepperoni() override { return SlicedPepperoni(); }
    string createClam() override { return FronzenClams();}
    string style() override { return "Chicago Style"; }
};