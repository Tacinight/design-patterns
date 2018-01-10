#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

using namespace std;

class Command {
public:
    Command() {};
    virtual ~Command() {};
    virtual void execute() {};
    virtual void undo() {};
    virtual string classname() { return "command"; }
};

class Light {
public:
    Light() {};
    void on() { cout << "light on" << endl; }
    void off() { cout << "light off" << endl; }
};

class LightOnCommmand : public Command {
public:
    Light light;
    LightOnCommmand(Light l):light(l) {}
    void execute() override { light.on(); }
    void undo() override { light.off(); }
    string classname() override { return "light-on command"; }
};

class GarageDoor {
public:
    GarageDoor() {};
    void on() { cout << "door open" << endl; }
    void off() { cout << "door close" << endl; }
};

class GarageDoorOpenCommand : public Command{
public:
    GarageDoor garageDoor;
    GarageDoorOpenCommand(GarageDoor gdoor):garageDoor(gdoor) {};
    void execute() override { garageDoor.on(); }
    void undo() override { garageDoor.off(); }
    string classname() override { return "garage door open command"; }
};

class SimpleRemoteControl {
public:
    vector<Command*> onCommands;
    vector<Command*> offCommands;
    Command* undoCommand;

    SimpleRemoteControl() {
        onCommands.reserve(7);
        offCommands.reserve(7);

        Command* noCommand = new Command();
        for (int i = 0; i < 7; i++) {
            onCommands[i] = noCommand;
            offCommands[i] = noCommand;
        }
        undoCommand = noCommand;
    }
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }
    void onButtonWasPressed(int slot) {
        onCommands[slot]->execute();
        undoCommand = onCommands[slot];
    }
    void offButtonWasPressed(int slot) {
        offCommands[slot]->execute();
        undoCommand = offCommands[slot];
    }
    void undoButtonWasPressed() {
        undoCommand->undo();
    }
    void toString() {
        cout << endl << "--------------------------------" << endl;
        for (int i = 0; i < 7; i++) {
            cout << "[slot " + to_string(i) + "]"
                 << typeid(*onCommands[i]).name()
                 << "   "
                 << onCommands[i]->classname()
                 << "\t"
                 << offCommands[i]->classname()
                 << endl;
        }
        cout  << "-----------------------------------------" << endl;
    }
};

int main() {
    SimpleRemoteControl* remote = new SimpleRemoteControl;
    Light light;
    GarageDoor gdoor;
    
    LightOnCommmand* lightOn = new LightOnCommmand(light);
    GarageDoorOpenCommand* garageOpen = new GarageDoorOpenCommand(gdoor);

    remote->setCommand(1, lightOn, lightOn);
    remote->onButtonWasPressed(1);
    remote->offButtonWasPressed(1);
    remote->undoButtonWasPressed();
    remote->setCommand(2, garageOpen, garageOpen);
    remote->offButtonWasPressed(2);

    remote->toString();
    delete remote;
    delete lightOn;

    return 0;
}