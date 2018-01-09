#include "MallardDuck.h"
#include <iostream>
using namespace std;

MallardDuck::MallardDuck() {
    quackBehavior = new Quack;
    flyBehavior = new FlyWithWinds;
}
void MallardDuck::display() {
    cout << "I'm a real Mallard duck" << endl;
}