CXX=g++
CXXFLAGS=-m64 -no-pie

all: main a
	$(CXX) $(CXXFLAGS) main.o a.o -o main.exe
main: main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@.o
a: a.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@.o
clean:
	rm $(wildcard *.o) $(wildcard *.exe)
