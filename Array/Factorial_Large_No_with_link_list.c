#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int data;
  struct NODE *prev;
};

typedef struct NODE node;

node *head = NULL;
node *tail = NULL;

void link(int value){

	node *temp;
	temp = malloc(sizeof(node));

	temp->data = value;

