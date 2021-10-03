// C++ program to print inorder traversal
// using stack.

#include<bits/stdc++.h>

using namespace std;

/* A binary tree Node has data, pointer to left child
and a pointer to right child */

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node (int data) {
		this->data = data;
		left = right = NULL;
	}

};

/* Iterative function for inorder tree
traversal */

void InOrder(struct Node *root) {

	stack<Node *> s;
	Node *curr = root;

	while (curr != NULL || s.empty() == false) {
		
		/* Reach the left most Node of the curr Node */
		
		while (curr != NULL) {
			/* place pointer to a tree node on
			the stack before traversing
			the node's left subtree */
			s.push(curr);
			curr = curr->left;
		}
		
		curr = s.top();
		s.pop();
		cout << curr->data << " ";
		/* we have visited the node and its
		left subtree. Now, it's right subtree's turn */
		curr = curr->right;
	} /* end of while */

}

void PostOrder(struct Node *root) {

	if (root == NULL)
        	return;
    	
	stack<Node *> s;
	Node *curr = root;
    	
	do {
        	// Move to leftmost node
        	while (curr) {
            	// Push root's right child and then root to stack.
            		if (curr->right)
                		s.push(curr->right);
            		s.push(curr);
	            	// Set root as root's left child
        		curr = curr->left;
        	}

	        // Pop an item from stack and set it as root    

        	curr = s.top();
		s.pop();

		// If the popped item has a right child and the right child is not

        	// processed yet, then make sure right child is processed before root
		
		if (s.empty()) {
			printf("%d ", curr->data);
			break;
		}

        	if (curr->right && (s.top() == curr->right)) {
            		s.pop(); // remove right child from stack
            		s.push(curr); // push root back to stack
            		curr = curr->right; // change root so that the right
                        // child is processed next
        	}

        	else {// Else print root's data and set root as NULL
            		printf("%d ", curr->data);
            		curr = NULL;
        	}

    	} while (!s.empty());

}

void PreOrder(Node* root) {

    	// Base Case

    	if (root == NULL)
        	return;

    	// Create an empty stack and push root to it

    	stack<Node*> s;
    	s.push(root);

    	/* Pop all items one by one. Do following for every popped item
       	a) print it
       	b) push its right child
       	c) push its left child
    	Note that right child is pushed first so that left is processed first */

    	while (!s.empty()) {

        	// Pop the top item from stack and print it

        	struct Node* node = s.top();
        	printf("%d ", node->data);
        	s.pop();

        	// Push right and left children of the popped node to stack

        	if (node->right)
            		s.push(node->right);

        	if (node->left)
            		s.push(node->left);

    	}

}

/* Driver program to test above functions*/

int main() {

	/* Constructed binary tree is

			1
		      /   \
		     2     3
	    	   / 	 /   \
	 	  4     5     6
	 	      /   \
		     7     8
	*/

	struct Node* root = new Node(1);
	root->left = new Node(2);
    	root->right = new Node(3);
    	root->left->left = new Node(4);
    	root->right->left = new Node(5);
    	root->right->right = new Node(6);
    	root->right->left->left = new Node(7);
    	root->right->left->right = new Node(8);

	cout << "\nPreorder traversal of binary tree is \n";
	PreOrder(root);

	cout << "\nInorder traversal of binary tree is \n";
	InOrder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	PostOrder(root);

	cout << endl;

	return 0;

}
