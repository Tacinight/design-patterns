#include "WeatherData.h"
using namespace std;

void WeatherData::registerObserver(Observer *o) {
    observers.push_back(o);
}

void WeatherData::removeObserver(Observer *o) {
    for (auto iter = observers.begin(); iter != observers.end(); iter++) {
        if (*iter == o)
            observers.erase(iter);
    }
}

void WeatherData::notifyObserver() {
    for (auto it : observers) {
        (*it).update(temperature, humidity, pressure);
    }
}
void WeatherData::measurementsChanged() {
    notifyObserver();
}

void WeatherData::setMeasurements(double t, double h, double p) {
    this->temperature = t;
    this->humidity = h;
    this->pressure = p;
    measurementsChanged();
}

