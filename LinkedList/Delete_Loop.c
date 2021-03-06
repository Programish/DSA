// C program to detect and remove loop in linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};


void removeLoop(struct Node*, struct Node*);
/*
int detectAndRemoveLoop(struct Node* list)
{
	struct Node *slow_p = list, *fast_p = list;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if (slow_p == fast_p) {
			removeLoop(slow_p, list);

			return 1;
		}
	}

	return 0;
}

void removeLoop(struct Node* loop_node, struct Node* head)
{
	struct Node* ptr1;
	struct Node* ptr2;

	ptr1 = head;
	while (1) {
		ptr2 = loop_node;
		while (ptr2->next != loop_node
			&& ptr2->next != ptr1)
			ptr2 = ptr2->next;

		if (ptr2->next == ptr1)
			break;

		ptr1 = ptr1->next;
	}

	ptr2->next = NULL;
}
*/

int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
 
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
 
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    ptr1 = head;
 
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    ptr2->next = NULL;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

struct Node* newNode(int key)
{
	struct Node* temp
		= (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

/* Driver code*/
int main()
{
	struct Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	printf("Linked List after removing loop \n");
	printList(head);
	printf("\n");
	return 0;
}

