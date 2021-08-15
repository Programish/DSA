//adding 2 linked lists as a number

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
	if(n == 0)
		return 1;
	while(n != 0) {
		count++;
		n = n/10;
	}
	
//	printf("%d\n", count);
	return count;
}

struct Node *newNode() {
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
    	new_node->data = 0;
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

struct Node* Add2LL(struct Node* head1, struct Node* head2) {
	
	head1 = reverse(head1);
	head2 = reverse(head2);
	print(head1);
	print(head2);

	int carry = 0, dig;
	
	struct Node* temp1 = head1;
	struct Node* temp2 = head2;

	while ((temp1->next != NULL) && (temp2 != NULL)) {
		dig = digits(temp1->data);
		temp1->data = temp1->data + temp2->data + carry;
		printf("%d\n", temp1->data);
	 	carry =(temp1->data)/((int)pow(10, dig));
		printf("%d\n", carry);
		temp1->data = (temp1->data)%((int)pow(10, dig));
		printf("%d\n", temp1->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	
	while(temp2 != NULL) {
		if((temp1->next == NULL) && (temp2->next != NULL))
			temp1->next = newNode();
		dig = digits(temp1->data);
		temp1->data = temp1->data + temp2->data + carry;
		printf("%d\n", temp1->data);
	 	carry =(temp1->data)/((int)pow(10, dig));
		printf("%d\n", carry);
		temp1->data = (temp1->data)%((int)pow(10, dig));
		printf("%d\n", temp1->data);

		if((temp2->next == NULL) && carry) {//If temp is at last node and carry is
						   //still there , then we've to create new
						   //node and attach to last of list and give
						   //carry to data of that node
			temp1->next = newNode();
			temp1 = temp1->next;
			temp1->data = carry;
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	while((temp1 != NULL) && carry) {
		dig = digits(temp1->data);
		temp1->data = temp1->data + carry;
		printf("%d\n", temp1->data);
	 	carry =(temp1->data)/((int)pow(10, dig));
		printf("%d\n", carry);
		temp1->data = (temp1->data)%((int)pow(10, dig));
		printf("%d\n", temp1->data);
		if((temp1->next == NULL) && carry) {
			temp1->next = newNode();
			temp1 = temp1->next;
			temp1->data = carry;
			break;
		}
		temp1 = temp1->next;
	}
	print(head1);
	head1 = reverse(head1);

	return head1;
}

/* Driver program to test above function*/
int main() {
	/* Start with the empty list */
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;

	push(&head1, 6);
	push(&head1, 4);
	push(&head1, 9);
	push(&head1, 5);
	push(&head1, 7);
	push(&head2, 4);
	push(&head2, 8);

	printf("Previous1 ");
	print(head1);
	printf("Previous2 ");
	print(head2);

	head1 = Add2LL(head1, head2);

	printf("Resultant ");
	print(head1);

	return 0;
}
