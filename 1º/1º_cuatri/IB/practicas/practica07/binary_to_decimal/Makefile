CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++ 
MAIN = binary_to_decimal
DEPS = $(MAIN).o
DEPS2 = $(MAIN)_func.o

$(MAIN): $(DEPS) $(DEPS2)

clean:
	rm *.o $(MAIN)

.PHONY = clean all