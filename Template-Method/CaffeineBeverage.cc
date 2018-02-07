/*  Template Method
 *  Define the skeleton of an algorithm in an operation
 *  deferring some steps to subclass. Template Method let
 *  subclasses redefine certain steps of an algorithm 
 *  without changing the algorithm's structure. 
 */

#include <iostream>
#include <memory>
using namespace std;

class CaffeineBeverage {
public:
    virtual void prepareRecipe() final {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    virtual void brew() {};
    virtual void addCondiments() {};

    void boilWater() { cout << "Boil the water" << endl; }
    void pourInCup() { cout << "Pouring into cup" << endl; }
};

class Tea : public CaffeineBeverage {
public:
    void brew() override { cout << "Steeping the tea" << endl; }
    void addCondiments() override { cout << "Adding Lemon" << endl; }
};

class Coffee : public CaffeineBeverage {
public:
    void brew() override { cout << "Dripping Coffee through filter" << endl; }
    void addCondiments() override { cout << "Adding Sugar and Milk" << endl; }
};

int main() {
    unique_ptr<Tea> myTea(new Tea);
    cout << "Making tea..." << endl;
    myTea->prepareRecipe();

    unique_ptr<Coffee> myCoffee(new Coffee);
    cout << endl << "Making coffee..." << endl;
    myCoffee->prepareRecipe();
    
    return 0;
}