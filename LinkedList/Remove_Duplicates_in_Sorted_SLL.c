//Remove duplicates from a sorted single linked list

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

int remove_duplicates(struct Node* head) {
	
	struct Node *temp = head;
        struct Node *nxt_temp;
	int flag;
	
	if(temp == NULL)
		return 0;
	
	while (temp->next != NULL) {

		if (temp->next->data == temp->data) {
			nxt_temp = temp->next->next;
			temp->next = nxt_temp;
		}
		else
			temp = temp->next;
	}
	return 0;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 20);
	push(&head, 20);
	push(&head, 20);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);
	push(&head, 15);
	push(&head, 15);
	push(&head, 15);
	push(&head, 15);
	push(&head, 10);
	push(&head, 10);

	printf("Prev ");
	print(head);

	remove_duplicates(head);

	printf("Resultant ");
	print(head);

	return 0;
}

