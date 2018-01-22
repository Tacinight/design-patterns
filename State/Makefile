CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

GumballMachine: GumballMachine.o
	$(CXX) $(CXXFLAGS) -o GumballMachine.out  GumballMachine.o

GumballMachine.o: GumballMachine.cc GumballMachine.hpp

clean:
	rm *.o