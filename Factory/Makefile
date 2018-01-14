CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

PizzaTestDrive: PizzaTestDrive.o 
	$(CXX) $(CXXFLAGS) -o PizzaTestDrive  PizzaTestDrive.o

PizzaTestDrive.o: PizzaTestDrive.cc Pizza.h

clean:
	rm *.o