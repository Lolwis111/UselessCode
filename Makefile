CFLAGS=-std=c99
CXXFLAGS=-std=c++11

all: convert map helloWorld

convert: convert.cpp
	$(CXX) $(CXXFLAGS) -o convert convert.cpp

map: map.c
	$(CC) $(CFLAGS) -o map map.c

helloWorld: helloWorld.cpp
	$(CXX) $(CXXFLAGS) -o helloWorld helloWorld.cpp