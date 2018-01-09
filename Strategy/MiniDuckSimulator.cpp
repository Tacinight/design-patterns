#include "Duck.h"
#include "MallardDuck.h"
#include "ModelDuck.h"
#include "FlyRocketPowered.h"

int main() {
    Duck *mallard = new MallardDuck;
    mallard->performQuack();
    mallard->performFly();

    Duck *model = new ModelDuck;
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered);
    model->performFly();

    return 0;
}