/* Program to check if a linked list is palindrome */
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	char data;
	struct Node* next;
};

/* Push a node to linked list. Note that this function
changes the head */
void push(struct Node** head_ref, char new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to pochar to the new node */
	(*head_ref) = new_node;
}

/* Function to delete a given node from the list */
void deleteNode(struct Node* head, int key)
{
    if (head == NULL)
        return;
 
    // Find the required node
    struct Node *curr = head, *prev;
    while (curr->data != key)
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
 
        prev = curr;
        curr = curr->next;
    }
 
    // Check if node is only node
    if (curr->next == head)
    {
        head = NULL;
        free(curr);
        return;
    }
 
    // If more than one node, check if
    // it is first node
    if (curr == head)
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
 
    // check if node is last node
    else if (curr->next == head && curr == head)
    {
        prev->next = head;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}

// A utility function to print a given linked list
void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
 
    printf("\n");
}

/* Drier program to test above function*/
int main()
{
    /* Initialize lists as empty */
    struct Node* head = NULL;
 
    /* Created linked list will be 2->5->7->8->10 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    head->next->next->next->next->next = head;

    printf("List Before Deletion: ");
    printList(head);
 
    deleteNode(head, 7);
 
    printf("List After Deletion: ");
    printList(head);
 
    return 0;
}
