// C++ program to find largest subtree
// sum in a given binary tree.

#include <bits/stdc++.h>

using namespace std;

// Structure of a tree node.
struct Node {

	int key;
	Node *left, *right;
	
	Node(int value) {
		key = value;
		left = right = NULL;
	}

};

// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{

	// If current node is null then
	// return 0 to parent node.
	if (root == NULL)	
		return 0;
	
	// Subtree sum rooted at current node.
	int currSum = root->key +
	findLargestSubtreeSumUtil(root->left, ans)
	+ findLargestSubtreeSumUtil(root->right, ans);

	// Update answer if current subtree
	// sum is greater than answer so far.
	ans = max(ans, currSum);

	// Return current subtree sum to
	// its parent node.
	return currSum;

}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{

	// If tree does not exist,
	// then answer is 0.
	if (root == NULL)	
		return 0;
	
	// Variable to store maximum subtree sum.
	int ans = INT_MIN;

	// Call to recursive function to
	// find maximum subtree sum.
	findLargestSubtreeSumUtil(root, ans);

	return ans;

}

// Driver function
int main()
{

	Node* root = new Node(1);
	root->left = new Node(-2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(-6);
	root->right->right = new Node(2);

	cout << findLargestSubtreeSum(root) << endl;

	return 0;

}
