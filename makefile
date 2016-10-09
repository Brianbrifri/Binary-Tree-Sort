objects = Main.o Scanner.o

project1: $(objects)
	g++ -g -o project1 $(objects)
Main.o: Main.cpp Token.h Scanner.h
	g++ -g -c Main.cpp
Scanner.o: Scanner.cpp Token.h Scanner.h
	g++ -g -c Scanner.cpp

.PHONY: clean
clean:
	-rm project1 $(objects)
