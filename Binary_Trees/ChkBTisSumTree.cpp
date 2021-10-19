// C++ program to check if Binary tree

// is sum tree or not

#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has data,
left child and right child */
struct node {

	int data;
	node* left;
	node* right;

	node (int value) {
		data = value;
		left = right = NULL;
	}

};

/* Utility function to check if
the given node is leaf or not */
int isLeaf(node *node) {

	if(node == NULL)
		return 0;

	if(node->left == NULL && node->right == NULL)
		return 1;

	return 0;

}

/* returns 1 if SumTree property holds for the given tree */
int isSumTree(node* node) {

	int ls; // for sum of nodes in left subtree
	int rs; // for sum of nodes in right subtree

	/* If node is NULL or it's a leaf node then
	return true */
	if(node == NULL || isLeaf(node))
		return 1;

	if( isSumTree(node->left) && isSumTree(node->right)) {
	
		// Get the sum of nodes in left subtree
		if(node->left == NULL)
			ls = 0;

		else if(isLeaf(node->left))
			ls = node->left->data;

		else
			ls = 2 * (node->left->data);

		// Get the sum of nodes in right subtree
		if(node->right == NULL)
			rs = 0;

		else if(isLeaf(node->right))
			rs = node->right->data;

		else
			rs = 2 * (node->right->data);

		/* If root's data is equal to sum of nodes in left
		and right subtrees then return 1 else return 0*/
		return(node->data == ls + rs);

	}

	return 0;

}

/* Driver code */
int main() {

	node *root = new node(26);
	root->left = new node(10);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(6);
	root->right->right = new node(3);

	if(isSumTree(root))
		cout << "The given tree is a SumTree \n";

	else
		cout << "The given tree is not a SumTree \n";

	return 0;

}
