#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <typeinfo>
using namespace std;

class ChocolateBoiler {
private:
    bool empty;
    bool boiled;
    static ChocolateBoiler uniqueInstance;

    ChocolateBoiler() {
        empty = true;
        boiled = false;
    }
public:
    static ChocolateBoiler* getInstance() {
        return &uniqueInstance;
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

    void boil() {
        if (!isEmpty() && !isBoiled()) {
            boiled = true;
        }
    }

    bool isEmpty() { return empty; }

    bool isBoiled() { return boiled; }

};

ChocolateBoiler ChocolateBoiler::uniqueInstance;

void CookChocolate() {
    ChocolateBoiler* p = ChocolateBoiler::getInstance();
    cout << typeid(*p).hash_code() << endl;
    p->fill();
    p->boil();
    p->drain();
}

int main() {
    vector<thread> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(thread(CookChocolate));
    }

    for (auto &t : vec) {
        t.join();
    }

    return 0;
}