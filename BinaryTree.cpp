#include<iostream>
#include<fstream>
#include<string>
#include "BinaryTree.h"



void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {

	if(nodePtr == NULL) {
		nodePtr = newNode;
	}
	else if(newNode->value < nodePtr->value) {
		insert(nodePtr->left, newNode);
	}
	else if(newNode->value > nodePtr->value) {
		insert(nodePtr->right, newNode);
		}
	else {
		nodePtr->counter++;
	}
}

void BinaryTree::insertNode(int str) {

	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->value = str;
	newNode->counter = 1;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void BinaryTree::destroySubTree(TreeNode *nodePtr) {
	
	if(nodePtr) {
		if(nodePtr->left) {
			destroySubTree(nodePtr->left);
		}
		if(nodePtr->right) {
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}

bool BinaryTree::searchNode(int str) {

	TreeNode *nodePtr = root;

	while(nodePtr) {
		if(nodePtr->value == str) {
			return true;
		}
		else if(str < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else {
			nodePtr = nodePtr->right;
		}
	}
	return false;
}

void BinaryTree::display(string fileName) {
  string preFileName = fileName;
  preFileName.append(".preorder");
  string postFileName = fileName;
  postFileName.append(".postorder");
  string orderFileName = fileName;
  orderFileName.append(".inorder");

  ofstream preFile, postFile, orderFile;

  preFile.open(preFileName.c_str());
  postFile.open(postFileName.c_str());
  orderFile.open(orderFileName.c_str());

  cout << "\nPreOrder traversal: \n";
  BinaryTree::displayPreOrder(root, 0, preFile);
  cout << "\n";
  cout << "InOrder traversal: \n";
  BinaryTree::displayInOrder(root, 0, orderFile);
  cout << "\n";
  cout << "PostOrder traversal: \n";
  BinaryTree::displayPostOrder(root, 0, postFile);
  cout << "\n";
  cout << "Visual Display: \n";
  BinaryTree::displayVisual(root, 1);
  cout << "\n";

  preFile.close();
  postFile.close();
  orderFile.close();
}

void BinaryTree::displayPreOrder(TreeNode *nodePtr, int level, ofstream &file) {
	if(nodePtr) {
    for(int i = 0; i <= level; i++) {
      cout << "   ";
    } 
	  cout << nodePtr->value << ": " << nodePtr->counter << endl;
		for(int i = 0; i <= level; i++) {
      file  << "   ";
    }
    file << nodePtr->value << ": " << nodePtr->counter << endl;
 		displayPreOrder(nodePtr->left, level + 1, file);
	  displayPreOrder(nodePtr->right, level + 1, file);
 }

}

void BinaryTree::displayPostOrder(TreeNode *nodePtr, int level, ofstream &file) {
	if(nodePtr) {
		displayPostOrder(nodePtr->left, level + 1, file);
	  displayPostOrder(nodePtr->right, level + 1, file);
    for(int i = 0; i <= level; i++) {
      cout << "   ";
    } 
	  cout << nodePtr->value << ": " << nodePtr->counter << endl;
		for(int i = 0; i <= level; i++) {
      file  << "   ";
    }
		file << nodePtr->value << ": " << nodePtr->counter << endl;
  }

}

void BinaryTree::displayInOrder(TreeNode *nodePtr, int level, ofstream &file) {

	if(nodePtr) {
		displayInOrder(nodePtr->left, level + 1, file);
    for(int i = 0; i <= level; i++) {
      cout << "   ";
    } 
	  cout << nodePtr->value << ": " << nodePtr->counter << endl;
		for(int i = 0; i <= level; i++) {
      file  << "   ";
    }
		file << nodePtr->value << ": " << nodePtr->counter << endl;
		displayInOrder(nodePtr->right, level + 1, file);
	}
}

void BinaryTree::displayVisual(TreeNode *ptr, int level) {

  if (ptr != NULL) {
    displayVisual(ptr->right, level+1);
    cout << "\n";
    if (ptr == root)
      cout << "Root->:  ";
    else {
      for (int i = 0;i < level;i++)
        cout << "       ";
    }
    cout << ptr->value;
    displayVisual(ptr->left, level+1);
  }
}

