// Simple C program to find diameter

// of a binary tree.

#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

/* Tree node structure used in the program */

struct Node {

	int data;

	struct Node* left, *right;

};

// returns max of two integers

int max(int a, int b) { return (a > b) ? a : b; }

/* Function to find height of a tree */

int height(struct Node* root, int* ans) {

	if (root == NULL)

		return 0;

	int left_height = height(root->left, ans);

	int right_height = height(root->right, ans);

	// update the answer, because diameter of a

	// tree is nothing but maximum value of

	// (left_height + right_height + 1) for each node

	*ans = max(*ans, 1 + left_height + right_height);

	return 1 + max(left_height, right_height);

}

/* Computes the diameter of binary tree with given root. */

int diameter(struct Node* root) {

	if (root == NULL)

		return 0;

	int ans = INT_MIN; // This will store the final answer

	height(root, &ans);

	return ans;

}

struct Node* newNode(int data) {

	struct Node* node = (struct Node*) malloc (sizeof(struct Node));

	node->data = data;

	node->left = node->right = NULL;

	return (node);

}

// Driver code

int main() {

	struct Node* root = newNode(1);

	root->left = newNode(2);

	root->right = newNode(3);

	root->left->left = newNode(4);

	root->left->right = newNode(5);

	root->right->right = newNode(6);

	printf("Diameter is %d\n", diameter(root));

	return 0;

}
