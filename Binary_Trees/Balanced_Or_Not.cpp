#include <iostream>

using namespace std;

// Data structure to store a binary tree node
struct Node {

    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }

};

// Recursive function to check if a given binary tree is height-balanced or not
int isHeightBalanced(Node* root, bool &isBalanced) {

    	// base case: tree is empty or not balanced

    	if (root == NULL || !isBalanced)
        	return 0;

    	// get the height of the left subtree
    	int left_height = isHeightBalanced(root->left, isBalanced);

    	// get the height of the right subtree
    	int right_height = isHeightBalanced(root->right, isBalanced);

    	// tree is unbalanced if the absolute difference between the height of
    	// its left and right subtree is more than 1
    	if (abs(left_height - right_height) > 1)
        	isBalanced = false;

    	// return height of subtree rooted at the current node
    	return max(left_height, right_height) + 1;

}

// The main function to check if a given binary tree is height-balanced or not
bool isHeightBalanced(Node* root) {
    	bool isBalanced = true;
    	isHeightBalanced(root, isBalanced);
    	return isBalanced;
}

int main() {

    /* Construct the following tree

              1

            /   \

           /     \

          2       3

         / \     /

        4   5   6

    */

    	Node* root = new Node(1);
    	root->left = new Node(2);
    	root->right = new Node(3);
    	root->left->left = new Node(4);
    	root->left->right = new Node(5);
    	root->right->left = new Node(6);

    	if (isHeightBalanced(root))
        	cout << "\nBinary tree is balanced.\n\n";

    	else
        	cout << "\nBinary tree is not balanced.\n\n";

    	return 0;

}
