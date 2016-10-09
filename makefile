objects = project1.o BinaryTree.o Worker.o

project1: $(objects)
	g++ -g -o project1 $(objects)
project1.o: project1.cpp BinaryTree.h Worker.h
	g++ -g -c project1.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp
Worker.o: Worker.cpp BinaryTree.h Worker.h
	g++ -g -c Worker.cpp

.PHONY: clean
clean:
	-rm project0 $(objects)
