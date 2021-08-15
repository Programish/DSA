//Intersection of 2 sorted linked lists

#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

void print(struct Node* node) {
	
	printf("LL:\t");
	while(node->next != NULL) {
		printf("%d-> ", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}

void push(struct Node** head_ref, int new_data) {
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

struct Node* Intersection(struct Node* head1, struct Node* head2) {
	
	struct Node* head3 = NULL;
	struct Node** headref = &head3;
	while (head1 != NULL && head2 != NULL) {
        	if (head1->data == head2->data) {
			push(headref, head1->data);
			headref = &((*headref)->next);
            		head1 = head1->next;
            		head2 = head2->next;
        	}
        	else if (head1->data < head2->data)
            		head1 = head1->next; /* advance the smaller list */
        	else
            		head2 = head2->next;
    	}
	return head3;
}

/* Driver program to test above function*/
int main() {
	/* Start with the empty list */
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;

	push(&head1, 6);
	push(&head1, 5);
	push(&head1, 4);
	push(&head1, 3);
	push(&head1, 2);
	push(&head1, 1);
	push(&head2, 8);
	push(&head2, 6);
	push(&head2, 4);
	push(&head2, 2);

	printf("Previous1 ");
	print(head1);
	printf("Previous2 ");
	print(head2);

	head1 = Intersection(head1, head2);

	printf("Resultant ");
	print(head1);

	return 0;
}
