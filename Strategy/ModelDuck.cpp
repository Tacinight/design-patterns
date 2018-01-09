#include "ModelDuck.h"
#include <iostream>
using namespace std;

ModelDuck::ModelDuck() {
    flyBehavior = new FlyNoWay;
    quackBehavior = new Quack;
}
void ModelDuck::display() {
    cout << "I'm a model duck" << endl;
}