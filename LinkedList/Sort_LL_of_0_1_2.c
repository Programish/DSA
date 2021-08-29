// C Program to sort a linked list 0s, 1s

// or 2s by changing links

#include <stdio.h>
#include <stdlib.h>

/* Link list node */

struct Node {

	int data;

	struct Node* next;

};

struct Node* newNode(int data);

// Sort a linked list of 0s, 1s and 2s

// by changing pointers.

struct Node* sortList(struct Node*);
/*
struct Node* sortList(struct Node* head) {

	if (!head || !(head->next))

		return head;

	// Create three dummy nodes to point to

	// beginning of three linked lists. These

	// dummy nodes are created to avoid many

	// null checks.

	struct Node* zeroD = newNode(0);

	struct Node* oneD = newNode(0);

	struct Node* twoD = newNode(0);

	// Initialize current pointers for three

	// lists and whole list.

	struct Node* zero = zeroD, *one = oneD, *two = twoD;

	// Traverse list

	struct Node* curr = head;

	while (curr) {

		if (curr->data == 0) {

			zero->next = curr;

			zero = zero->next;

			curr = curr->next;

		} 
		
		else if (curr->data == 1) {

			one->next = curr;

			one = one->next;

			curr = curr->next;

		} 
		
		else {

			two->next = curr;

			two = two->next;

			curr = curr->next;

		}

	}

	// Attach three lists

	zero->next = (oneD->next) ? (oneD->next) : (twoD->next);

	one->next = twoD->next;

	two->next = NULL;

	// Updated head

	head = zeroD->next;

	// Delete dummy nodes

	free(zeroD);

	free(oneD);

	free(twoD);

	return head;

}
*/
// Function to create and return a node

struct Node* newNode(int data) {

	// allocating space

	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));

	// inserting the required data

	newNode->data = data;

	newNode->next = NULL;
	
	return newNode;

}

/* Function to print linked list */

void printList(struct Node* node) {

	while (node != NULL) {

		printf("%d ", node->data);

		node = node->next;

	}

	printf("\n");

}

/* Driver program to test above function*/

int main(void) {

	// Creating the list 1->2->4->5

	struct Node* head = newNode(1);

	head->next = newNode(2);

	head->next->next = newNode(0);

	head->next->next->next = newNode(1);

	printf("Linked List Before Sorting\n");

	printList(head);

	head = sortList(head);
	
	printf("Linked List After Sorting\n");

	printList(head);
	
	return 0;

}
/*
struct Node* sortList(struct Node *head) {

	int count[3] = {0, 0, 0};  // Initialize count of '0', '1' and '2' as 0

    	struct Node *ptr = head;

    	// count total number of '0', '1' and '2'

    	// count[0] will store total number of '0's

    	// count[1] will store total number of '1's

    	// count[2] will store total number of '2's  

    	while (ptr != NULL) {

        	count[ptr->data] += 1;

        	ptr = ptr->next;

    	}

    	int i = 0;

    	ptr = head;

    	// Let say count[0] = n1, count[1] = n2 and count[2] = n3

    	// now start traversing list from head node,

    	// 1) fill the list with 0, till n1 > 0

    	// 2) fill the list with 1, till n2 > 0

    	// 3) fill the list with 2, till n3 > 0 

    	while (ptr != NULL) {

        	if (count[i] == 0)

            		++i;

        	else {

            		ptr->data = i;

            		--count[i];

            		ptr = ptr->next;

        	}

    }

    	return head;
}*/

struct Node* sortList(struct Node* head) {

    	// Single element list is already sorted

    	if(head == NULL || head->next == NULL)

        	return head;

    	// pointer to last node in the list

    	struct Node* last = head;

    	int numOfNodes = 1;

    	while(last->next != NULL) {

        	last = last->next;

        	numOfNodes++;

    	}

    	struct Node *tail = last;

	struct Node *ptr = head;

    	struct Node *prev = head;

    	for(int i = 0; i<numOfNodes; i++) {

		struct Node* temp = ptr;

       		ptr = ptr->next;

        	if(temp->data == 0) {

            		// Inserting at head (If First Node - Skip)

            		if(prev != temp) {

                		temp->next = head;

                		head = temp;

                		prev->next = ptr;

            		}	

        	}

        	else if(temp->data == 2) {

            		// Inserting at the End.

            		tail->next = temp;

            		temp->next = NULL;

            		tail = temp;

            		// If first Node.

            		if(prev == temp)

                		head = prev = ptr;

            		else

                		prev->next = ptr;

        	}

        	else {

            		if(prev != temp)

                		prev = prev->next;

        	}

    	}

	return head;
	
}
