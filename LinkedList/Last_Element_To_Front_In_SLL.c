//Move last element to first in single linked list

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

int Last_to_First(struct Node** head) {
	
	struct Node *second_last = *head;
        struct Node *last;
	
	if(second_last == NULL)
		return 0;
	
	while (second_last->next->next != NULL)
		second_last = second_last->next;

	last = second_last->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;

	return 0;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	printf("Prev ");
	print(head);

	Last_to_First(&head);

	printf("Resultant ");
	print(head);

	return 0;
}

