CXX =	g++
CFLAGS = -std=c++17 -Wall
LDFLAGS =

countChar:  countChar.o funciones.o
	$(CXX)  countChar.o	funciones.o -o countChar 

funciones.o:	funciones.cc
	$(CXX)	funciones.cc	-c	

countChar.o:	countChar.cc
	$(CXX)  countChar.cc	-c

clean:
	rm -f	*.o countChar 	
.PHONY: clean
