objects = project6.o BinaryTree.o

a.out: $(objects)
	g++ -o a.out $(objects)
project6.o: project6.cpp BinaryTree.h
	g++ -g -c project6.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp

.PHONY: clean
clean:
	-rm a.out $(objects)
