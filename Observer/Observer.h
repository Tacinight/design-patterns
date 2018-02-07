#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public:
    virtual void update(double temp, double humidity, double pressure) = 0;
    bool operator==(const Observer &rhs) 
        { return *this == rhs; }
};

class Subject {
public:
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObserver() = 0;
};

class DisplayElement {
public:
    virtual void display() = 0;
};

#endif