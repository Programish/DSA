// C program to check if linked list is circular
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* This function returns true if given linked
   list is circular, else false. */
bool isCircular(struct Node *head)
{
    // An empty linked list is circular
    if (head == NULL)
       return true;
 
    // Next of head
    struct Node *node = head->next;
 
    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;
 
    // If loop stopped because of circular
    // condition
    return (node == head);
}

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// A utility function to print a given linked list

void printNode(struct Node *head){
        while(head != NULL){
            printf("%d->", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	int i;

	for (i=5; i>0; i--)
	{
		push(&head, i);
//		printList(head);
	}
//	head->next->next->next->next->next = head;

	isCircular(head) ? printf("Given linked list is circular.\n") : printf("Given linked list is not circular.\n");
	
	return 0;
}

