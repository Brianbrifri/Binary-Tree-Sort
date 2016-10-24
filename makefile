objects = Main.o Scanner.o

testScanner: $(objects)
	g++ -std=c++11 -g -o testScanner $(objects)
Main.o: Main.cpp Token.h Scanner.h
	g++ -g -c Main.cpp
Scanner.o: Scanner.cpp Token.h Scanner.h
	g++ -g -c Scanner.cpp

.PHONY: clean
clean:
	-rm testScanner $(objects)
