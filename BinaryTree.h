#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>

using namespace std;

class BinaryTree {

	private:
		struct TreeNode {
		
			string value;
			int counter;
			TreeNode *left;
			TreeNode *right;
		};

		TreeNode *root;

		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(string, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;

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
		void insertNode(string);
		bool searchNode(string);
		void remove(string);

		void displayInOrder() const {
			displayInOrder(root);
		}

};
#endif
