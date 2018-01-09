#include "Display.h"
using namespace std;

CurrentConditionDisplay::CurrentConditionDisplay(Subject *wd) {
    this->weatherData = wd;
    wd->registerObserver(this);
}

void CurrentConditionDisplay::update(double t, double h, double p) {
    temperature = t;
    humidity = h;
    display();
}

void CurrentConditionDisplay::display() {
    cout << "Current conditions: " + to_string(temperature) +
        "F degrees and " + to_string(humidity) + "% huminity" << endl;
}