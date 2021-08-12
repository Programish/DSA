//Floyd’s Cycle detection algorithm
// C program to detect loop in a linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

int getStartPoint(struct Node* list) {
	struct Node *slow_p = list, *fast_p = list;

	if((!list) || (!list->next))
		return 0;

	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			break;
	}

	if(slow_p != fast_p) {
		printf("No Loop Exists !!\n");
		return 0;
	}

	slow_p = list;

	while(slow_p != fast_p) {
		slow_p = slow_p->next;
		fast_p = fast_p->next;
	}

	printf("First Loop element is: %d\n", slow_p->data);

	return 0;
}

	/* Driver program to test above function*/
int main() {
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

		/* Create a loop for testing */
	head->next->next->next->next = head;

	getStartPoint(head);
		
	return 0;
}

