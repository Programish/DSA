//add 1 to number represented as a linked list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

struct Node *reverse(struct Node *head) {
    	struct Node * prev = NULL;
    	struct Node * current = head;
    	struct Node * next;
    	while (current != NULL) {
     		next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
    	}
    return prev;
}

int digits(int n) {
	int count = 0;
	while(n > 0) {
		count++;
		n = n/10;
	}
	return count;
}

struct Node *newNode(int data) {
    	struct Node *new_node;
    	new_node->data = data;
    	new_node->next = NULL;
    	return new_node;
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

int Add1ToNumber(struct Node* head) {
	
	struct Node* res = head;

	head = reverse(head);

	int carry = 1, crnt_value;
	
	struct Node* temp = head;

	if(temp == NULL)
		return 0;
	
	while (temp != NULL) {
		
		temp->data = temp->data + carry;
	 	carry = (temp->data)/((int)pow(10, digits(temp->data)));
		temp->data = (temp->data)%((int)pow(10, digits(temp->data)));
		
		if((temp->next == NULL) && carry)
			temp = newNode(carry);
	}

	head = reverse(head);

	return 0;
}

/* Driver program to test above function*/
int main() {
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 9999);
	push(&head, 999);
	push(&head, 99);
	push(&head, 9);

	printf("Previous ");
	print(head);

	int result = Add1ToNumber(head);

	printf("Resultant ");
	print(head);

	return 0;
}
