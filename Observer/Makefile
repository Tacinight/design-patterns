CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

WeatherStation: WeatherStation.o Display.o WeatherData.o
	$(CXX) $(CXXFLAGS) -o WeatherStation WeatherStation.o Display.o WeatherData.o

WeatherStation.o: Display.h WeatherData.h

Display.o: Observer.h Display.h

WeatherData.o: Observer.h WeatherData.h

clean:
	rm *.o