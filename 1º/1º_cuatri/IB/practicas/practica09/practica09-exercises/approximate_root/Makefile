CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++
MAIN = approximate_root
DEPS = $(MAIN).o funciones.o

$(MAIN): $(DEPS)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
