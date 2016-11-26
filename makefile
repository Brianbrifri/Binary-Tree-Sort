objects = Main.o Scanner.o treePrint.o

testSem: $(objects)
	g++ -g -o testSem $(objects)
Main.o: Main.cpp Token.h Scanner.h
	g++ -g -c Main.cpp
Scanner.o: Scanner.cpp Token.h Scanner.h treePrint.h
	g++ -g -c Scanner.cpp
treePrint.o: treePrint.cpp treePrint.h
	g++ -g -c treePrint.cpp

.PHONY: clean
clean:
	-rm testSem $(objects) *.out
