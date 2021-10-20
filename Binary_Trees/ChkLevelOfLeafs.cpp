// C++ program to check if all leaves
// are at same level
#include <bits/stdc++.h>

using namespace std;

// A binary tree node
struct Node {

	int data;
	struct Node *left, *right;

	Node(int value) {

		data = value;
		left = right = NULL;
	
	}

};

/* Recursive function which checks whether
all leaves are at same level */
bool checkUtil(struct Node *root,
			int level, int *leafLevel) {

	// Base case
	if (root == NULL) return true;

	// If a leaf node is encountered
	if (root->left == NULL &&
		root->right == NULL) {

		// When a leaf node is found
		// first time
		if (*leafLevel == 0) {

			*leafLevel = level; // Set first found leaf's level

			return true;

		}

		// If this is not first leaf node, compare
		// its level with first leaf's level
		return (level == *leafLevel);

	}

	// If this node is not leaf, recursively
	// check left and right subtrees
	return checkUtil(root->left, level + 1, leafLevel) &&
			checkUtil(root->right, level + 1, leafLevel);

}

/* The main function to check
if all leafs are at same level.
It mainly uses checkUtil() */
bool check(struct Node *root) {

	int level = 0, leafLevel = 0;

	return checkUtil(root, level, &leafLevel);

}

// Driver Code
int main() {

	// Let us create tree shown in third example
	struct Node *root = new Node(12);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->left->right = new Node(9);
	root->left->left->left = new Node(1);
	root->left->right->left = new Node(1);

	if (check(root))
		cout << "Leaves are at same level\n";

	else
		cout << "Leaves are not at same level\n";

	return 0;

}
