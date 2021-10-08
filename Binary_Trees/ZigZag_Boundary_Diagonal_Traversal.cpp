#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node {

	int data;
	Node *left, *right;

	Node (int data) {
		this->data = data;
		left = right = NULL;
	}

};

// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root) {

	deque<Node*> q;
	vector<int> v;
	q.push_back(root);
	v.push_back(root->data);
	Node* temp;

	// set initial level as 1, because root is
	// already been taken care of.

	int l = 1;		

	while (!q.empty()) {

		int n = q.size();

		for (int i = 0; i < n; i++) {

			// popping mechanism

			if (l % 2 == 0) {
				temp = q.back();
				q.pop_back();
			}

			else {
				temp = q.front();
				q.pop_front();
			}

			// pushing mechanism

			if (l % 2 != 0) {

				if (temp->right) {
					q.push_back(temp->right);
					v.push_back(temp->right->data);
				}

				if (temp->left) {
					q.push_back(temp->left);
					v.push_back(temp->left->data);
				}

			}

			else if (l % 2 == 0) {

				if (temp->left) {
					q.push_front(temp->left);
					v.push_back(temp->left->data);
				}

				if (temp->right) {
					q.push_front(temp->right);
					v.push_back(temp->right->data);
				}

			}

		}

		l++; // level plus one

	}

	return v;

}

// A simple function to print leaf nodes of a binary tree
void printLeaves(struct Node* root) {

    	if (root == NULL)
        	return;

    	printLeaves(root->left);

    	// Print it if it is a leaf node

    	if (!(root->left) && !(root->right))
        	printf("%d ", root->data);

    	printLeaves(root->right);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(struct Node* root) {

    	if (root == NULL)
        	return;

    	if (root->left) {

        	// to ensure top down order, print the node
        	// before calling itself for left subtree

        	printf("%d ", root->data);
        	printBoundaryLeft(root->left);
    	}

    	else if (root->right) {
        	printf("%d ", root->data);
        	printBoundaryLeft(root->right);
    	}

    	// do nothing if it is a leaf node, this way we avoid
    	// duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(struct Node* root) {

    	if (root == NULL)
        	return;

    	if (root->right) {

        	// to ensure bottom up order, first call for right
        	// subtree, then print this node

        	printBoundaryRight(root->right);
        	printf("%d ", root->data);
    	}

    	else if (root->left) {
        	printBoundaryRight(root->left);
        	printf("%d ", root->data);
    	}

    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary tree
void BoundaryTraversal(struct Node* root) {

    	if (root == NULL)
        	return;

    	printf("%d ", root->data);

    	// Print the left boundary in top-down manner.
    	printBoundaryLeft(root->left);

    	// Print all leaf nodes
    	printLeaves(root->left);
    	printLeaves(root->right);

    	// Print the right boundary in bottom-up manner
    	printBoundaryRight(root->right);
}

//For diagonal traversal
void diagonalPrintUtil(Node* root, int d,

                map<int, vector<int>> &diagonalPrint) {

    	// Base case
    	if (!root)
        	return;

    	// Store all nodes of same
    	// line together as a vector
    	diagonalPrint[d].push_back(root->data);

    	// Increase the vertical
    	// distance if left child
    	diagonalPrintUtil(root->left, d + 1, diagonalPrint);

    	// Vertical distance remains
    	// same for right child
    	diagonalPrintUtil(root->right, d, diagonalPrint);
}

// Print diagonal traversal
// of given binary tree
void DiagonalTraversal(Node* root) {

    	// create a map of vectors
    	// to store Diagonal elements
    	map<int, vector<int> > diagonalPrint;
    	diagonalPrintUtil(root, 0, diagonalPrint);

    	cout << "\nDiagonal Traversal of binary tree : \n";

    	for (auto it :diagonalPrint) {
        
		cout << it.first << ": ";
		vector<int> v=it.second;

        	for(auto it:v)
          		cout<<it<<" ";

        	cout<<endl;

    	}

}

// Driver program
int main() {

	// vector to store the traversal order.
	vector<int> v;

	// create tree
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);

	cout << "\nZigZag Order traversal of binary tree is \n";
	v = zigZagTraversal(root);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	cout << "\nBoundary Order traversal of binary tree is \n";
	BoundaryTraversal(root);
	cout << endl;
	
	DiagonalTraversal(root);
	cout << endl;
	
	return 0;

}
