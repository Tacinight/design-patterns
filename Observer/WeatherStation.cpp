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