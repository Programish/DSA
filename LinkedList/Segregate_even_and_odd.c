// C program to segregate even and odd nodes in a

// Linked List

#include <stdio.h>

#include <stdlib.h>

/* a node of the singly linked list */

struct Node {

	int data;

	struct Node *next;

};

void segregateEvenOdd(struct Node**);
void printList(struct Node*);
/*
void segregateEvenOdd(struct Node **head_ref) {

	struct Node *end = *head_ref;

	struct Node *prev = NULL;

	struct Node *curr = *head_ref;

	// Get pointer to the last node 

	while (end->next != NULL)

		end = end->next;

	struct Node *new_end = end;

	// Consider all odd nodes before the first even node

	// and move then after end 

	while (curr->data %2 != 0 && curr != end) {

		new_end->next = curr;

		curr = curr->next;

		new_end->next->next = NULL;

		new_end = new_end->next;

	}

	// 10->8->17->17->15

	// Do following steps only if there is any even node

	if (curr->data%2 == 0) {

		// Change the head pointer to point to first even node

		*head_ref = curr;

		// now current points to the first even node

		while (curr != end) {

			if ( (curr->data)%2 == 0 ) {

				prev = curr;

				curr = curr->next;

			}

			else {

				// break the link between prev and current

				prev->next = curr->next;

				// Make next of curr as NULL

				curr->next = NULL;

				// Move curr to end

				new_end->next = curr;

				// make curr as new end of list

				new_end = curr;

				// Update current pointer to next of the moved node

				curr = prev->next;

			}

		}

	}

	// We must have prev set before executing lines following this statement

	else 
		prev = curr;

	// If there are more than 1 odd nodes and end of original list is

	// odd then move this node to end to maintain same order of odd

	// numbers in modified list

	if (new_end!=end && (end->data)%2 != 0) {

		prev->next = end->next;

		end->next = NULL;

		new_end->next = end;

	}

	return;

}
*/
// UTILITY FUNCTIONS

// Function to insert a node at the beginning

void push(struct Node** head_ref, int new_data) {

	// allocate node

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	// put in the data

	new_node->data = new_data;

	// link the old list off the new node

	new_node->next = (*head_ref);

	// move the head to point to the new node

	(*head_ref) = new_node;

}

// Function to print nodes in a given linked list

void printList(struct Node *node) {

	while (node!=NULL) {

		printf("%d ", node->data);

		node = node->next;

	}

}

// Driver program to test above functions

int main() {

	// Start with the empty list

	struct Node* head = NULL;

	// Let us create a sample linked list as following

	// 0->2->4->6->8->10->11

	push(&head, 11);

	push(&head, 10);

	push(&head, 87);

	push(&head, 62);

	push(&head, 49);

	push(&head, 21);

	push(&head, 90);

	printf("Original Linked list \n");

	printList(head);

	segregateEvenOdd(&head);

	printf("\nModified Linked list \n");

	printList(head);

	printf("\n");
	
	return 0;

}

void segregateEvenOdd(struct Node **head_ref) {

    	// Starting node of list having

    	// even values.

    	struct Node *evenStart = NULL;

    	// Ending node of even values list.

    	struct Node *evenEnd = NULL;

    	// Starting node of odd values list.

    	struct Node *oddStart = NULL;

    	// Ending node of odd values list.

    	struct Node *oddEnd = NULL;

    	// Node to traverse the list.

    	struct Node *currNode = *head_ref;

    	while(currNode != NULL){

        	int val = currNode -> data;

        	// If current value is even, add

        	// it to even values list.

        	if(val % 2 == 0) {

            		if(evenStart == NULL){

                		evenStart = currNode;

                		evenEnd = evenStart;

            		}

            		else {

                		evenEnd -> next = currNode;

                		evenEnd = evenEnd -> next;

            		}

        	}

        	// If current value is odd, add

        	// it to odd values list.

        	else {

            		if(oddStart == NULL){

                		oddStart = currNode;

                		oddEnd = oddStart;

            		}

            		else {

                		oddEnd -> next = currNode;

                		oddEnd = oddEnd -> next;

            		}

        	}

        	// Move head pointer one step in

        	// forward direction

        	currNode = currNode -> next;   

    	}

    	// If either odd list or even list is empty,

    	// no change is required as all elements

    	// are either even or odd.

    	if(oddStart == NULL || evenStart == NULL)

        	return;

    	// Add odd list after even list.    

    	evenEnd -> next = oddStart;

    	oddEnd -> next = NULL;

    	// Modify head pointer to

    	// starting of even list.

    	*head_ref = evenStart;

}
