CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++
MAIN = ReduceSum
DEPS = $(MAIN).o dependencies.o

$(MAIN): $(DEPS)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
