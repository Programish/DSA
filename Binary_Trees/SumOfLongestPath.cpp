// C++ implementation to find the sum of nodes
// on the longest path from root to leaf node

#include <bits/stdc++.h>

using namespace std;

// Node of a binary tree
struct Node {

	int data;
	Node* left, *right;

	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

// function to find the sum of nodes on the
// longest path from root to leaf node
void sumOfLongRootToLeafPath(Node* root, int sum,
					int len, int& maxLen, int& maxSum) {

	// if true, then we have traversed a
	// root to leaf path
	if (!root) {

		// update maximum length and maximum sum
		// according to the given conditions
		if (maxLen < len) {

			maxLen = len;
			maxSum = sum;

		} 
		
		else if (maxLen == len && maxSum < sum)
			maxSum = sum;

		return;

	}

	// recur for left subtree
	sumOfLongRootToLeafPath(root->left, sum + root->data,
							len + 1, maxLen, maxSum);

	// recur for right subtree
	sumOfLongRootToLeafPath(root->right, sum + root->data,
							len + 1, maxLen, maxSum);

}

// utility function to find the sum of nodes on
// the longest path from root to leaf node
int sumOfLongRootToLeafPathUtil(Node* root) {

	// if tree is NULL, then sum is 0
	if (!root)
		return 0;

	int maxSum = INT_MIN, maxLen = 0;

	// finding the maximum sum 'maxSum' for the
	// maximum length root to leaf path
	sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);

	// required maximum sum
	return maxSum;

}

// Driver program to test above
int main() {

	// binary tree formation
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(1);
	root->right->left = new Node(2);
	root->right->right = new Node(3);
	root->left->right->left = new Node(6);

	cout << "Sum = " << sumOfLongRootToLeafPathUtil(root) << endl;

	return 0;

}
