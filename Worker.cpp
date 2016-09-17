#include "Worker.h"
string fileName, line, numberString;
fstream file;
string data = ".data";
string preName = "out";
BinaryTree *tree = new BinaryTree();

BinaryTree *processData(char ** argv, int argc) {
   
	//Create an instance of the binary tree

	if(argc > 1) {
    preName = argv[1];
    size_t found = preName.find(data);
    if(found > preName.size()) {
      fileName = preName + data;
    }
    else {
      fileName = preName;
      preName = fileName.substr(0, found);
    }
		file.open(fileName.c_str());
	
		if(!file) {
			perror("Error opening file");
      exit(1);
		}
	  while(getline (file, line)) {
		  numberString.append(line);
	  }
	  file.close();
  }

  else {
    fileName = preName;
    while(getline(cin, line)) {
      numberString.append(line);
    }
  }

  //BinaryTree *ptr = addToTree(numberString);
  return addToTree(numberString);

}

BinaryTree *addToTree(string numberString) {
  string temp2 = "";
  for(int i = 0; i < numberString.size(); i++) {
    if(numberString[i] != ' ') {
      string temp1;
      temp1 = numberString[i];
      temp2.append(temp1);
      if(i == numberString.size() - 1) {
        tree->insertNode(atoi(temp2.c_str()));
      } 
    }
    else {
      if(temp2.size() != 0) {
        tree->insertNode(atoi(temp2.c_str()));
        temp2 = ""; 
      }
    }
    
  }
	
  return tree;
}

void displayData() {
  tree->display(preName);
}
