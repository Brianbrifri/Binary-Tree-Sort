project6mkfile: project6.o BinaryTree.o
	g++ -o a.out project6.o BinaryTree.o
project6.o: project6.cpp BinaryTree.h
	g++ -g -c project6.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp
