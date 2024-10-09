CXX =	g++
CFLAGS = -std=c++17 -Wall
LDFLAGS =

positionLetter:  positionLetter.o funciones.o
	$(CXX)  positionLetter.o	funciones.o -o positionLetter 

funciones.o:	funciones.cc
	$(CXX)	funciones.cc	-c	

positionLetter.o:	positionLetter.cc
	$(CXX)  positionLetter.cc	-c

clean:
	rm -f	*.o positionLetter 	
.PHONY: clean
