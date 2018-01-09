#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public:
    virtual void update(double temp, double humidity, double pressure) {};
    bool operator==(const Observer rhs) 
        { return *this == rhs; }
};

class Subject {
public:
    virtual void registerObserver(Observer*) {};
    virtual void removeObserver(Observer*) {};
    virtual void notifyObserver() {};
};

class DisplayElement {
public:
    virtual void display() = 0;
};

#endif