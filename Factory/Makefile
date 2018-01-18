CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

PizzaTestDrive: PizzaTestDrive.o 
	$(CXX) $(CXXFLAGS) -o PizzaTestDrive.out  PizzaTestDrive.o

PizzaTestDrive.o: PizzaTestDrive.cc Pizza.cc PizzaIngredient.cc

clean:
	rm *.o