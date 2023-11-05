CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lstdc++
MAIN = bin
DEPS = $(MAIN).o

$(MAIN): $(DEPS)

clean:
	rm *.o $(MAIN)

.PHONY = clean all
