CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++
MAIN = scalar_product
DEPS = $(MAIN).o funciones.o

$(MAIN): $(DEPS)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
