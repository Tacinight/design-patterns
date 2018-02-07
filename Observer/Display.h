#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "Observer.h"
#include <iostream>
#include <string>

class CurrentConditionDisplay : public Observer, public DisplayElement {
private:
    double temperature;
    double humidity;
    Subject* weatherData;
public:
    CurrentConditionDisplay() = default;
    CurrentConditionDisplay(Subject*);
    void update(double temperature, double humidity, double pressure) override;
    void display() override;
};

#endif