// C++ program to print left view of

// Binary Tree



#include<bits/stdc++.h>

using namespace std;



// A Binary Tree Node

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node (int data) {
		this->data = data;
		left = right = NULL;
	}

};

// function to print left view of
// binary tree

void printLeftView(Node* root) {

	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {	

		// number of nodes at current level

		int n = q.size();

		// Traverse all nodes of current level

		for(int i = 1; i <= n; i++) {
			Node* temp = q.front();
			q.pop();

			// Print the left most element
			// at the level

			if (i == 1)
				cout<<temp->data<<" ";

			// Add left node to queue

			if (temp->left != NULL)
				q.push(temp->left);

			// Add right node to queue

			if (temp->right != NULL)
				q.push(temp->right);

		}

	}

}	

void printRightView(Node* root) {

	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {	

		// number of nodes at current level

		int n = q.size();

		// Traverse all nodes of current level

		for(int i = 1; i <= n; i++) {
			Node* temp = q.front();
			q.pop();

			// Print the left most element
			// at the level

			if (i == 1)
				cout<<temp->data<<" ";

			// Add left node to queue

			if (temp->right != NULL)
				q.push(temp->right);

			// Add right node to queue

			if (temp->left != NULL)
				q.push(temp->left);

		}

	}

}	

// function to fill the top view map
void fillTopMap(Node* root, int d, int l, map<int, pair<int, int> >& m) {

    	if (root == NULL)
        	return;

    	if (m.count(d) == 0)
        	m[d] = make_pair(root->data, l);

    	else if (m[d].second > l)
        	m[d] = make_pair(root->data, l);

    	fillTopMap(root->left, d - 1, l + 1, m);
    	fillTopMap(root->right, d + 1, l + 1, m);

}

// function should print the topView of the binary tree
void printTopView(struct Node* root) {

    	// map to store the pair of node value and its level
    	// with respect to the vertical distance from root.

    	map<int, pair<int, int> > m;

    	// fillmap(root,vectical_distance_from_root,level_of_node,map)

    	fillTopMap(root, 0, 0, m);

    	for (auto it = m.begin(); it != m.end(); it++)
        	cout << it->second.first << " ";

}

// function to fill the bottom view map
void fillBottomMap(Node* root, int d, int l, map<int, pair<int, int> >& m) {

    	if (root == NULL)
        	return;

    	if (m.count(d) == 0)
        	m[d] = make_pair(root->data, l);

    	else if (m[d].second < l)
        	m[d] = make_pair(root->data, l);

    	fillBottomMap(root->left, d - 1, l + 1, m);
    	fillBottomMap(root->right, d + 1, l + 1, m);

}

// function should print the topView of the binary tree
void printBottomView(struct Node* root) {

    	// map to store the pair of node value and its level
    	// with respect to the vertical distance from root.

    	map<int, pair<int, int> > m;

    	// fillmap(root,vectical_distance_from_root,level_of_node,map)

    	fillBottomMap(root, 0, 0, m);

    	for (auto it = m.begin(); it != m.end(); it++)
        	cout << it->second.first << " ";

}
// Driver code
int main() {

	// Let's construct the tree as
	// shown in example

	Node* root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(18);
	
	cout << "Left View: "; 
	printLeftView(root); 
	cout << endl;
	
	cout << "Right View: "; 
	printRightView(root); 
	cout << endl;
	
	cout << "Top View: "; 
	printTopView(root); 
	cout << endl;
	
	cout << "Bottom View: "; 
	printBottomView(root); 
	cout << endl;

}
