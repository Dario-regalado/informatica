CXX = g++

countChar: countChar.cc funciones.cc
	$(CXX) countChar.o funciones.o
funciones.o: funciones.cc
	$(CXX) funciones.cc -o funciones.o
countChar.o: countChar.cc
	$(CXX) countChar.cc -o countChar.o

clean:
	rm *.o -rf
.PHONY:
clean 