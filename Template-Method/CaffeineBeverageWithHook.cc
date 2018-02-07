#include <iostream>
#include <algorithm>
#include <cctype>
#include <memory>
using namespace std;

class CaffeineBeverageWithHook {
public:
    virtual void prepareRecipe() final {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    virtual bool customerWantsCondiments() { return true; }

    void boilWater() { cout << "Boil the water" << endl; }
    void pourInCup() { cout << "Pouring into cup" << endl; }
};

class TeaWithHook : public CaffeineBeverageWithHook {
public:
    void brew() override { cout << "Steeping the tea" << endl; }
    void addCondiments() override { cout << "Adding Lemon" << endl; }
    
    bool customerWantsCondiments() override {
        string answer = getUserInput();

        transform(answer.begin(), answer.end(), answer.begin(), ptr_fun<int, int>(tolower));
        if (answer[0] == 'y') {
            return true;
        } else {
            return false;
        }
    }

private:
    string getUserInput() {
        string answer;

        cout << "Would you like lemon with your tea (y/n)? ";
        cin >> answer;

        if (answer.empty()) {
            return "no";
        }

        return answer;
    }
};

class CoffeeWithHook : public CaffeineBeverageWithHook {
public:
    void brew() override { cout << "Dripping Coffee through filter" << endl; }
    void addCondiments() override { cout << "Adding Sugar and Milk" << endl; }

    bool customerWantsCondiments() override {
        string answer = getUserInput();

        transform(answer.begin(), answer.end(), answer.begin(), ptr_fun<int, int>(tolower));
        if (answer[0] == 'y') {
            return true;
        } else {
            return false;
        }
    }

private:
    string getUserInput() {
        string answer;

        cout << "Would you like milk and sugar with your coffee (y/n)? ";
        cin >> answer;

        if (answer.empty()) {
            return "no";
        }

        return answer;
    }
};

int main() {
    unique_ptr<TeaWithHook> myTea(new TeaWithHook);
    cout << "Making tea..." << endl;
    myTea->prepareRecipe();
    
    unique_ptr<CoffeeWithHook> myCoffee(new CoffeeWithHook);
    cout << endl << "Making coffee..." << endl;
    myCoffee->prepareRecipe();
    
    return 0;
}