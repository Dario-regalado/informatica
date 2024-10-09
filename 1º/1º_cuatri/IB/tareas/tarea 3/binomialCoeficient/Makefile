CXX =	g++
CFLAGS = -std=c++17 -Wall
LDFLAGS =

binomialCoeficient:  binomialCoeficient.o funciones.o
	$(CXX)  binomialCoeficient.o	funciones.o -o binomialCoeficient 

funciones.o:	funciones.cc
	$(CXX)	funciones.cc	-c	

binomialCoeficient.o:	binomialCoeficient.cc
	$(CXX)  binomialCoeficient.cc	-c

clean:
	rm -f	*.o binomialCoeficient 	
.PHONY: clean
