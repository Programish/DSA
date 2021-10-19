// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>

using namespace std;

/* A tree node structure */
struct node {

	int data;
	node *left;
	node *right;

	node (int data) {

		this->data = data;
		left = NULL;
		right = NULL;

	}

};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{

	// Base case
	if(Node == NULL)
	return 0;

	// Store the old value
	int old_val = Node->data;

	// Recursively call for left and
	// right subtrees and store the sum as
	// old value of this node
	Node->data = toSumTree(Node->left) + toSumTree(Node->right);

	// Return the sum of values of nodes
	// in left and right subtrees and
	// old_value of this node
	return Node->data + old_val;

}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{

	if (Node == NULL)
		return;

	printInorder(Node->left);
	cout<<" "<<Node->data;
	printInorder(Node->right);

}

/* Driver code */
int main()
{

	node *root = NULL;
	int x;

	/* Constructing tree given in the above figure */
	root = new node(10);
	root->left = new node(-2);
	root->right = new node(6);
	root->left->left = new node(8);
	root->left->right = new node(-4);
	root->right->left = new node(7);
	root->right->right = new node(5);

	toSumTree(root);

	// Print inorder traversal of the converted
	// tree to test result of toSumTree()
	cout<<"Inorder Traversal of the resultant tree is: \n";

	printInorder(root);
	cout << endl;
	return 0;

}
