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

void BinaryTree::insertNode(string str) {

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

bool BinaryTree::searchNode(string str) {

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

void BinaryTree::displayInOrder(TreeNode *nodePtr) const {

	if(nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << ": " << nodePtr->counter << endl;
		displayInOrder(nodePtr->right);
	}
}

