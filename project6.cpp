#include<iostream>
#include<cstdlib>
#include<fstream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char *argv[]) {

	//Variable declarations
	int tries = 3;
	int max;
	string fileName, line, preFormStr, postFormStr, temp2;
	fstream file;

	//Create an instance of the binary tree
	BinaryTree tree;

	//While loop to get file name and open it
	if(argc > 1) {
	
		file.open(argv[1]);
	
		if(!file) {
			perror("Error opening file");
      return -1;
		}
	while(getline (file, line)) {
		cout << "Pre formatted: " << line << endl;
		preFormStr.append(line);
	}
	file.close();
}
	
	//For loop goes through post formatted string and 
	//inserts nodes
  cout << preFormStr.size() << endl;
	for(int i = 0; i < preFormStr.size(); i++) {
    if(preFormStr[i] != ' ') {
      string temp1;
      temp1 = preFormStr[i];
      temp2.append(temp1);
      if(i == preFormStr.size() - 1 && temp2.size() != 0) {
        tree.insertNode(atoi(temp2.c_str()));
      } 
    }
    else {
      if(temp2.size() != 0) {
        tree.insertNode(atoi(temp2.c_str()));
        temp2 = ""; 
      }
    }
    
  }
	
	tree.displayInOrder();
  tree.displayVisual();

	return 0;
}

