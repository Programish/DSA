// C program to split circular linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

void splitList(struct Node *head, struct Node **head1_ref,
                                            struct Node **head2_ref)
{
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;
 
  if(head == NULL)
    return;
  
  /* If there are odd nodes in the circular list then
     fast_ptr->next becomes head and for even nodes
     fast_ptr->next->next becomes head */
  while(fast_ptr->next != head &&
         fast_ptr->next->next != head)
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  } 
 
 /* If there are even elements in list then move fast_ptr */
  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;     
   
  /* Set the head pointer of first half */
  *head1_ref = head;   
      
  /* Set the head pointer of second half */
  if(head->next != head)
    *head2_ref = slow_ptr->next;
   
  /* Make second half circular */  
  fast_ptr->next = slow_ptr->next;
   
  /* Make first half circular */  
  slow_ptr->next = head;      
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
void printList(struct Node *head)
{
  struct Node *temp = head;
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}

/* Driver program to test above function*/
int main()
{
  int list_size, i;
   
  /* Initialize lists as empty */
  struct Node *head = NULL;
  struct Node *head1 = NULL;
  struct Node *head2 = NULL; 
 
  /* Created linked list will be 12->56->2->11 */
  push(&head, 12);
  push(&head, 56);  
  push(&head, 2);  
  push(&head, 11);  

  head->next->next->next->next = head; 

  printf("Original Circular Linked List");
  printList(head);     
  
  /* Split the list */
  splitList(head, &head1, &head2);
  
  printf("\nFirst Circular Linked List");
  printList(head1); 
 
  printf("\nSecond Circular Linked List");
  printList(head2); 
  printf("\n");

  return 0;
}
