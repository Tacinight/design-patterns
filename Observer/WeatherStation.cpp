/*  Observer
 *  define a one-to-many dependency between objects so
 *  that when one object changes state, all its dependents
 *  are notified and updated automatically.
 */ 

#include "WeatherData.h"
#include "Display.h"
#include <iostream>

using namespace std;

int main() {
    WeatherData wd;
    CurrentConditionDisplay currentDisplay(&wd);

    wd.setMeasurements(80.0, 54.0, 30.4);
    wd.setMeasurements(82.0, 70.0, 29.3);
    wd.setMeasurements(78.0, 90.0, 29.2);
    return 0;
}

/* OO Principles
 * 
 * Favor composition over inheritence
 *   The Observer pattern uses composition to compose any
 * number of Observers with their Subjects. These relationships
 * aren't set up by some kind of inheritance hierarchy. No, they
 * are set up at runtime by compostion.
 * 
 * Program to interfaces, not implementation
 *   The subject keeps track of objects implementing the Observer
 * interface, while the observers register with, and get notified
 * by, the Subject interface. As we've seen, this keep things nice
 * and loosely coupled.
 */  