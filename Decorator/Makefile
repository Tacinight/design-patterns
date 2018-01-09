CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

StarbuzzCoffee: StarbuzzCoffee.o 
	$(CXX) $(CXXFLAGS) -o StarbuzzCoffee  StarbuzzCoffee.o

StarbuzzCoffee.o: StarbuzzCoffee.cc Starbuzz.h

clean:
	rm *.o