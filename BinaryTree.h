#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>

using namespace std;

class BinaryTree {

	private:
		struct TreeNode {
		
			int value;
			int counter;
			TreeNode *left;
			TreeNode *right;
		};

		TreeNode *root;

		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(string, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *, int, ofstream&);
    void displayPostOrder(TreeNode *, int, ofstream&);
    void displayPreOrder(TreeNode *, int, ofstream&);
    void displayVisual(TreeNode *ptr, int level);

	public:
		//Constructor
		BinaryTree() {
			root = NULL;
		}

		//Destructor
		~BinaryTree() {
			destroySubTree(root);
		}

		//Binary Tree Operations
		void insertNode(int);
		bool searchNode(int);
		void remove(string);
    void displayVisual() {
      displayVisual(root, 1);
    }

		void display(string fileName);
		

};
#endif
