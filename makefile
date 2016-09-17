objects = project0.o BinaryTree.o Worker.o

project0: $(objects)
	g++ -g -o project0 $(objects)
project0.o: project0.cpp BinaryTree.h Worker.h
	g++ -g -c project0.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp
Worker.o: Worker.cpp BinaryTree.h Worker.h
	g++ -g -c Worker.cpp

.PHONY: clean
clean:
	-rm project0 $(objects)
