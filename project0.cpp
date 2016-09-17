#include<iostream>
#include<cstdlib>
#include<fstream>
#include "BinaryTree.h"
#include "Worker.h"

using namespace std;

int main(int argc, char *argv[]) {

	//Create an instance of the binary tree

  processData(argv, argc); 	
		
  displayData();

	return 0;
}

