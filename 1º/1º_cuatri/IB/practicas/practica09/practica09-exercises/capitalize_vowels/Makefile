CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++
MAIN = capitalize_vowels
DEPS = $(MAIN).o funciones.o

$(MAIN): $(DEPS)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
