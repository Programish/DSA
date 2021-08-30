// C program to clone a linked list with next

// and arbit pointers in O(n) time

#include <stdio.h>
#include <stdlib.h>

// Structure of linked list Node

struct Node {

	int data;

	struct Node *next; 

	struct Node *random;

};

struct Node* new_Node(int x) {

	struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
	
	ptr->data = x;

	ptr->next = NULL;
       
	ptr->random = NULL;

	return ptr;

}
// Utility function to print the list.

void print(struct Node *start) {

	struct Node *ptr = start;

	while (ptr) {

		printf("Data = %d, Random = %d\n", ptr->data, ptr->random->data);

		ptr = ptr->next;

	}

}

// This function clones a given linked list

// in O(1) space

struct Node* clone(struct Node *start) {

	struct Node* curr = start, *temp;

	// insert additional node after

	// every node of original list

	while (curr) {

		temp = curr->next;

		// Inserting node

		curr->next = new_Node(curr->data);

		curr->next->next = temp;

		curr = temp;

	}

	curr = start;

	// adjust the random pointers of the

	// newly added nodes

	while (curr) {

		if(curr->next)

			curr->next->random = curr->random ? curr->random->next : curr->random;

		// move to the next newly added node by

		// skipping an original node

		curr = curr->next ? curr->next->next : curr->next;

	}

	struct Node* original = start, *copy = start->next;

	// save the start of copied linked list

	temp = copy;

	// now separate the original list and copied list

	while (original && copy) {

		original->next = original->next ? original->next->next : original->next;

		copy->next = copy->next ? copy->next->next : copy->next;

		original = original->next;

		copy = copy->next;

	}

	return temp;

}

// Driver code

int main() {

	struct Node* start = new_Node(1);

	start->next = new_Node(2);

	start->next->next = new_Node(3);

	start->next->next->next = new_Node(4);

	start->next->next->next->next = new_Node(5);

	// 1's random points to 3

	start->random = start->next->next;

	// 2's random points to 1

	start->next->random = start;

	// 3's and 4's random points to 5

	start->next->next->random = start->next->next->next->next;

	start->next->next->next->random = start->next->next->next->next;

	// 5's random points to 2

	start->next->next->next->next->random = start->next;

	printf("Original list : \n");

	print(start);

	printf("\nCloned list : \n");

	struct Node *cloned_list = clone(start);

	print(cloned_list);

	return 0;

}
