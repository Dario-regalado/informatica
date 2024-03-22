CXX =	g++
CFLAGS = -std=c++17 -Wall
LDFLAGS =

TRE:  TRE.o funciones.o
	$(CXX)  TRE.o	funciones.o -o TRE 

funciones.o:	funciones.cc
	$(CXX)	funciones.cc	-c	

TRE.o:	TRE.cc
	$(CXX)  TRE.cc	-c

clean:
	rm -f	*.o TRE 	
.PHONY: clean
