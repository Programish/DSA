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

struct Node *reverse(struct Node *head) {//To reverse the LL
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

int digits(int n) {//To count digits of orginal data of node
	int count = 0;
	while(n != 0) {
		count++;
		n = n/10;
	}
//	printf("%d\n", count);
	return count;
}

struct Node *newNode(int data) {//To create new node for attaching it to last of LL
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
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

struct Node* Add1ToNumber(struct Node* head) {//Adding 1 to LL pretending LL as a normal number

	head = reverse(head);//LL is reversed to do addition and provide carry to next element
			     //starting from 1st node. Because originally this 1st node is the
			     //last node and we do addition starting from right to left.
//	print(head);

	int carry = 1, dig;
	
	struct Node* temp = head;

	if(temp == NULL)
		return 0;
	
	while (temp != NULL) {
		dig = digits(temp->data);// dig will have original digits of data of the node
					 // before addng carry to it.
		temp->data = temp->data + carry;
//		printf("%d\n", temp->data);
	 	carry =(temp->data)/((int)pow(10, dig));//Here data of the node is dvided by
						        //10^dig so that if the digits are 
							//greater than the original digits
							//So that the extra digits go to carry
//		printf("%d\n", carry);
		temp->data = (temp->data)%((int)pow(10, dig));//Here mod is taken from data of
							      //node by 10^dig. So that if the
							      //digits are greater than 
							      //original digits of data. Then
							      //the original number of digits
							      //could be stored in that node
//		printf("%d\n", temp->data);
		
		if((temp->next == NULL) && carry) {//If temp is at last node and carry is
						   //still there , then we've to create new
						   //node and attach to last of list and give
						   //carry to data of that node
			temp->next = newNode(carry);
			temp = temp->next;
			break;
		}
//		printf("%d\n", temp->data);
		temp = temp->next;
	}

//	print(head);
	head = reverse(head);//LL is reversed again , to get original sequence of LL

	return head;
}

/* Driver program to test above function*/
int main() {
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 8);
	push(&head, 99);
	push(&head, 888);
	push(&head, 9999);

	printf("Previous ");
	print(head);

	head = Add1ToNumber(head);

	printf("Resultant ");
	print(head);

	return 0;
}
