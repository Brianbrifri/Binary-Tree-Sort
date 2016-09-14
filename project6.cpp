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
	
	//For loop to get rid of the spaces for easier analysis
	for(int i = 0; i < preFormStr.size(); i++) {
		
		string temp;

		//If the sting has a space, increment the iterator
		if(preFormStr[i] == ' ' || preFormStr[i] == '\0') {
			i++;
		}

		//If the string has a character, append it to the formatted string
		else {
			temp = preFormStr[i];
			postFormStr.append(temp);
		}
		
	}

	cout << "Post formatted: " << postFormStr << endl;


	//For loop goes through post formatted string and 
	//inserts nodes
	for(int i = 0; i < postFormStr.size(); i++) {
    string temp1 = "";
    tree.insertNode(temp1);
  }
	
	tree.displayInOrder();
  tree.displayVisual();

	return 0;
}

