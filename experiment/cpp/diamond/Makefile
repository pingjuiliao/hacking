CXX=g++
CXXFLAGS=-m64 -no-pie

all: main
main: diamond main.cc
	$(CXX) $(CXXFLAGS) -o main.o -c main.cc
	$(CXX) $(CXXFLAGS) -o $@.exe $@.o diamond.o
diamond: diamond.cc
	$(CXX) $(CXXFLAGS) -o $@.o -c $<
clean:
	rm $(wildcard *.o) $(wildcard *.exe)
