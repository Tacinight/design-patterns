CXX = g++
CXXFLAGS = -Wall -g 

MiniDuckSimulator: Duck.o FlyNoWay.o FlyWithWinds.o MiniDuckSimulator.o MallardDuck.o ModelDuck.o FlyRocketPowered.o Quack.o
	$(CXX) $(CXXFLAGS) -o MiniDuckSimulator Duck.o FlyNoWay.o FlyWithWinds.o MiniDuckSimulator.o MallardDuck.o ModelDuck.o FlyRocketPowered.o Quack.o

MiniDuckSimulator.o: ModelDuck.h MallardDuck.h FlyRocketPowered.h

ModelDuck.o: Duck.o FlyNoWay.o Quack.o ModelDuck.h

MallardDuck.o: Duck.o FlyWithWinds.o Quack.o MallardDuck.h

Duck.o: Duck.h FlyBehavior.h QuackBehavior.h

FlyWithWinds.o: FlyBehavior.h FlyWithWinds.h

FlyNoWay.o: FlyBehavior.h FlyNoWay.h

FlyRocketPowered.o: FlyBehavior.h FlyRocketPowered.h

Squeak.o: QuackBehavior.h Squeak.h

Quack.o: QuackBehavior.h Quack.h

MuteQuack.o: QuackBehavior.h MuteQuack.h

clean:
	rm *.o
