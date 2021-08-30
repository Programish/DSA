#include <stdio.h>
#include <stdlib.h>

// A Linked List Node

struct Node {

    int data;

    struct Node *next;
};

 
struct Node* new_Node(int data) {

	struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
	
	ptr->data = data;

        ptr->next = NULL;

	return ptr;

}

// Utility function to print contents of a linked list

void printList(struct Node* node) {

    	while (node != NULL) {

        	printf("%d —> ", node->data);

        	node = node->next;

    	}

    	printf("NULL\n");

}

// Takes two lists sorted in increasing order and merge their nodes

// to make one big sorted list returned

struct Node *sortedMerge(struct Node* a, struct Node* b) {

    	// base cases

    	if (a == NULL)

        	return b;

    	else if (b == NULL)

        	return a;

    	struct Node *result;

    // pick either `a` or `b`, and recur

    	if (a->data <= b->data) {

        	result = a;

        	result->next = sortedMerge(a->next, b);

    	}

    	else {

        	result = b;

        	result->next = sortedMerge(a, b->next);

    	}

    	return result;

}

// The main function to merge given `k` sorted linked lists.

// It takes array `lists` of size `k` and generates the sorted output

struct Node *mergeKLists(struct Node* list[], int k) {

    	int last = k - 1;

    // repeat until only one list is left

    	while (last != 0) {

        	int i = 0, j = last;
        
		// `(i, j)` forms a pair

        	while (i < j) {

            		// merge list `j` with `i`

            		list[i] = sortedMerge(list[i], list[j]);

            		// consider the next pair

            		i++; 
			
			j--;

	            	// if all pairs are merged, update last

            		if (i >= j)

                		last = j;
    
		}

    	}	

    	return list[0];

}

int main() {

    	int k = 3;    // total number of linked lists

    	// an array to store the head nodes of the linked lists

    	struct Node *list[k];

    	list[0] = new_Node(1);

    	list[0]->next = new_Node(5);

    	list[0]->next->next = new_Node(7);

    	list[1] = new_Node(2);

    	list[1]->next = new_Node(3);

    	list[1]->next->next = new_Node(6);

    	list[1]->next->next->next = new_Node(9);

    	list[2] = new_Node(4);

    	list[2]->next = new_Node(8);

    	list[2]->next->next = new_Node(10);

    	// Merge all lists into one

    	struct Node* head = mergeKLists(list, k);

    	printList(head);

    	return 0;

}
