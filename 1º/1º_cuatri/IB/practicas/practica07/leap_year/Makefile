CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++ 
MAIN = leap_year
DEPS = $(MAIN).o
DEPS2 = $(MAIN)_func.o

$(MAIN): $(DEPS) $(DEPS2)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
