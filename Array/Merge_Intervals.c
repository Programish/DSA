#include<stdio.h>
#include<stdlib.h>
#include"STACK.c"

void merge(node*,node*,int*);

void iterate(){
	node *temp1 = head,*temp2;
	int  flag = 0;
	while(temp1->next != NULL){
		temp2 = temp1->next;
		merge(temp1,temp2,&flag);
		if(flag == 0)
			temp1 = temp1->next;
		flag = 0;
		printf("1st while\n");
	}
}

void merge(node* fixed,node* mobile,int* f){
	printf("\ninside 2nd while\n");
	while(mobile != NULL){
        	if((mobile->start >= fixed->start) && (mobile->start <= fixed->end)){//ex-(1,9),(5,9) will be merged to(1,9)
        		printf("inside if\n");					     //ex-(1,9),(6,17) will be merged to (1,17)
        		if(fixed->end < mobile->end)	  //if start time of next node is between start and end time of current interval
        			fixed->end = mobile->end; //including start and end time of current interval then only next node of 
        		fixed->next = mobile->next;	  //interval should be merged with current interval and next pointer of current
        		*f = 1;	//interval should be linked with next pointer of next interval.	
        		break;  //else get to next node and check that it can be merged or not 
        	}
        	mobile = mobile->next;
	}
}

int main(void){
	int start,end,n;
	printf("Enter no. of intervals:");
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		printf("Enter interval %d \nstart:",i+1);
		scanf("%d",&start);
		printf("end:");
		scanf("%d",&end);
		push(start,end);
	}
	printf("Given Intervals:\n");
	display();
	sort();
	printf("\nSorted Intervals:\n");
	display();
	iterate();
	printf("\nMerged Intervals:\n");
	display();
	return 0;
}



