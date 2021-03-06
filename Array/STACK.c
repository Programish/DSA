#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int start;
  int end;

  struct NODE *next;
};

typedef struct NODE node;

node *head = NULL;
node *tail = NULL;

void push(int s, int e) {
  node *temp;
  temp = malloc(sizeof(node));

  temp->start = s;
  temp->end = e;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
    tail = head;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void pop() {
  struct NODE *temp = head, *t = head;

  for (; temp->next != NULL; t = temp, temp = temp->next) {
  }
  tail = t;
  t->next = NULL;
  free(temp);
}

void sort(){
	int swapped;
	node *ptr1,*lptr = NULL;
	do{
		swapped = 0;
		ptr1 = head;
		while(ptr1->next != lptr){
			if(ptr1->start > ptr1->next->start){
				int temp = ptr1->start;
				ptr1->start = ptr1->next->start;
				ptr1->next->start = temp;
				temp = ptr1->end;
				ptr1->end = ptr1->next->end;
				ptr1->next->end = temp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}while(swapped);
}
void display() {
  node *temp = head;

  while (temp->next != NULL) {
    printf("  %d | %d ->  ", temp->start, temp->end);
    temp = temp->next;
  }
  printf("%d | %d", temp->start, temp->end);
}
/*
int main() {
  push(2, 3);
  push(1, 2);
  push(1, 2);
  push(1, 2);
  push(1, 2);
  display();
  return 0;
}*/
