// C++ program to check if two trees are mirror
// of each other

#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{

	int data;
	Node* left, *right;

	Node(int value) {
		data = value;
		left = right = NULL;
	}
};

/* Given two trees, return true if they are
mirror of each other */
/*As function has to return bool value instead integer value*/
bool areMirror(Node* a, Node* b)
{

	/* Base case : Both empty */
	if (a==NULL && b==NULL)
		return true;

	// If only one is empty
	if (a==NULL || b == NULL)
		return false;

	/* Both non-empty, compare them recursively
	Note that in recursive calls, we pass left
	of one tree and right of other tree */
	return a->data == b->data &&
			areMirror(a->left, b->right) &&
			areMirror(a->right, b->left);

}

/* Driver program to test areMirror() */
int main()
{

	Node *a = new Node(1);
	Node *b = new Node(1);
	a->left = new Node(2);
	a->right = new Node(3);
	a->left->left = new Node(4);
	a->left->right = new Node(5);
	b->left = new Node(3);
	b->right = new Node(2);
	b->right->left = new Node(5);
	b->right->right = new Node(4);

	areMirror(a, b) ? cout << "Yes\n" : cout << "No\n";

	return 0;

}


