CXX = g++
CXXFLAGS = -Wall -g -std=c++11 

ChocolateFactory: 
	$(CXX) $(CXXFLAGS) -o ChocolateFactory.out  ChocolateFactory.cc

ChocolateFactoryV1: 
	$(CXX) $(CXXFLAGS) -o ChocolateFactoryV1.out  ChocolateFactoryConcurrency_v1.cc -lpthread

ChocolateFactoryV2: 
	$(CXX) $(CXXFLAGS) -o ChocolateFactoryV2.out  ChocolateFactoryConcurrency_v2.cc -lpthread

ChocolateFactoryV3: 
	$(CXX) $(CXXFLAGS) -o ChocolateFactoryV3.out  ChocolateFactoryConcurrency_v3.cc -lpthread

clean:
	rm *.o