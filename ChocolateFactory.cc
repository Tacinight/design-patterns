#include <iostream>
using namespace std;

class ChocolateBoiler {
private:
    bool empty;
    bool boiled;
    static ChocolateBoiler* uniqueInstance;

    ChocolateBoiler() {
        empty = true;
        boiled = false;
    }
public:
    static ChocolateBoiler* getInstance() {
        if (uniqueInstance == nullptr)
            uniqueInstance = new ChocolateBoiler;
        return uniqueInstance;
    }
    void fill() {
        if (isEmpty()) {
            empty = false;
            boiled = false;
        }
    }
    void drain() {
        if (!isEmpty() && isBoiled()) {
            boiled = true;
        }
    }
    bool isEmpty() {
        return empty;
    }
    bool isBoiled() {
        return boiled;
    }

};

ChocolateBoiler *ChocolateBoiler::uniqueInstance = nullptr;

int main() {
    ChocolateBoiler* p1 = ChocolateBoiler::getInstance();
    ChocolateBoiler* p2 = ChocolateBoiler::getInstance();

    cout << p1->isEmpty() << endl;
    p1->fill();
    cout << p2->isEmpty() << endl;

    delete p1;

    return 0;
}