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
    cout << "Increasing counter" << endl;
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

void BinaryTree::displayInOrder(TreeNode *nodePtr) const {

	if(nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << ": " << nodePtr->counter << endl;
		displayInOrder(nodePtr->right);
	}
}

void BinaryTree::displayVisual(TreeNode *ptr, int level) const
{
    int i;
    if (ptr != NULL)
    {
        displayVisual(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
    }
        cout<<ptr->value;
        displayVisual(ptr->left, level+1);
    }
}

