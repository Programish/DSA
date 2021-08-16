//Intersection point of 2 linked lists

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

void Intersect(struct Node** head1, struct Node** head2, int pos) {

	struct Node* temp1 = *head1;
	while(--pos)
		temp1 = temp1->next;

	struct Node* temp2 = *head2;
	while(temp2->next)
		temp2 = temp2->next;

	temp2->next = temp1;
}

int Length_LL(struct Node* head) {

	struct Node* temp = head;
	int count = 0;
	while(temp) {
		count++;
		temp = temp->next;
	}

	return count;
}

int Intersection_Point(struct Node* head1, struct Node* head2) {
	
	int l1 = Length_LL(head1);
	int l2 = Length_LL(head2);
	int diff = abs(l1 - l2);

	struct Node* temp1 = NULL;
	struct Node* temp2 = NULL;

	if(l1 > l2) {
		temp1 = head1;
		temp2 = head2;
	}
	else {
		temp1 = head2;
		temp2 = head1;
	}

	while(diff--)
		temp1 = temp1->next;

	while(temp1 != NULL && temp2 != NULL) {

        	if ((temp1 == NULL) || (temp2 == NULL))
			return -1;
        	if (temp1->data == temp2->data)
			return temp1->data;
            		
		temp1 = temp1->next;
            	temp2 = temp2->next;
    	}
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
	Intersect(&head1, &head2, 4);

	printf("Previous1 ");
	print(head1);
	printf("Previous2 ");
	print(head2);

	int res = Intersection_Point(head1, head2);

	printf("Resultant Node:%d\n", res);

	return 0;
}
