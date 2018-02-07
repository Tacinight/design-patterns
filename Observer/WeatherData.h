#ifndef _WEATHERDATA_H
#define _WEATHERDATA_H

#include "Observer.h"
#include <vector>
#include <algorithm>
#include <memory>

class WeatherData : public Subject {
private:
    std::vector<Observer*> observers;
    double temperature;
    double humidity;
    double pressure;
public:
    WeatherData() {};
    void registerObserver(Observer*) override;
    void removeObserver(Observer*) override;
    void notifyObserver() override;
    void measurementsChanged();
    void setMeasurements(double, double, double);
};

#endif