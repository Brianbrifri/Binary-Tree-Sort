#include<iostream>
#include<fstream>
#include "BinaryTree.h"

using namespace std;

int main() {

	//Variable declarations
	int tries = 3;
	int max;
	string fileName, line, preFormStr, postFormStr, temp2;
	fstream file;

	//Create an instance of the binary tree
	BinaryTree tree;

	//While loop to get the file name and open it
	while(1) {
	
		cout << "What is the name of the file: ";
		cin >> fileName;
		file.open(fileName.c_str());
	
		if(file) {
			break;
		}
		else {
			tries--;
			cout << "You have " << tries << " tries left." << endl;
			file.close();
			file.clear();
		}
		if(tries == 0) {
			cout << "You have used all your tries. Terminating program...";
			exit(1);
		}
	}
	
	cout << "What is the max reccurence for letters? ";
	cin >> max;

	//Copy the text from the file into a pre formatted string
	while(getline (file, line)) {
		cout << "Pre formatted: " << line << endl;
		preFormStr.append(line);
	}
	
	//Close the file. Don't need it any more.
	file.close();

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
	for(int i = 1; i < postFormStr.size(); i++) {
		
		string temp1;

		//If the iterator is at the end of the string
		//it adds the last character to the temp string
		//if equal and then adds the string to the binary tree
		if(i == (postFormStr.size()) - 1) {
			if(postFormStr[i - 1] == postFormStr[i]) {
				temp1 = postFormStr[i - 1];
				temp2.append(temp1);
				tree.insertNode(temp1);
				
				if(temp2.size() == max) {
					tree.insertNode(temp2);
					temp2.clear();
				}
				
				temp1 = postFormStr[i];
				temp2.append(temp1);
				tree.insertNode(temp1);
				tree.insertNode(temp2);
			}
			//or it adds it as its own node if different
			if(postFormStr[i - 1] != postFormStr[i]) {
				temp1 = postFormStr[i - 1];
				temp2.append(temp1);
				tree.insertNode(temp2);

				//Temp1 is always only going to have a size of 1
				//so if temp2 is > 1, that means I can insert temp1
				//without is being the same as temp2 that I just inserted
				if(temp2.size() > 1) {
					tree.insertNode(temp1);
				}
				temp1 = postFormStr[i];
				tree.insertNode(temp1);
			}
		}

		//If two characters next to each other are the same
		//it appends the left character to the end of the string
		//and continues
		if(i < (postFormStr.size()) - 1) {
			if(postFormStr[i - 1] == postFormStr[i]) {
				temp1 = postFormStr[i - 1];
				temp2.append(temp1);
				tree.insertNode(temp1);

				//Inserts the string at its current position 
				//if it reaches the max size
				if(temp2.size() == max) {
					tree.insertNode(temp2);
					temp2.clear();
				}
			}

			//If the two characters next to each other are different
			//it appends the left character to a string then inserts the string
			//into the binary tree
			if(postFormStr[i - 1] != postFormStr[i]) {
				temp1 = postFormStr[i - 1];
				temp2.append(temp1);
				tree.insertNode(temp2);
				if(temp2.size() > 1) {
					tree.insertNode(temp1);
				}
				temp2.clear();
			}
		}
	}
	
	tree.displayInOrder();

	return 0;
}
