#include<stdio.h>
#include<string.h>
int main(){
	int x,i,j = 0,temp;
	char y[7];
	printf("Enter no. of elements:");
	scanf("%d",&x);
	int a[x];
	printf("Enter elements:\n");
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	printf("Negative elements will be left/right:");
	scanf("%s",y);
	/*In the else and if else loop
	 * j is having index with which element will
	 * be swapped (acc. to condition) and after 
	 * then only j will be incremented
	 */
	if(!strcmp(y,"left")){
		printf("Entered left loop\n");
		for(i = 0;i < x;i++){
			if(a[i] < 0){
				if(i != j){
					printf("i = %d  j = %d  Values to be swapped are %d and %d \n",i,j,a[j],a[i]);
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				j++;
			}
		}
	}
	else if(!strcmp(y,"right")){
		printf("Entered right loop\n");
		j = 0;
        	for(i = 0;i < x;i++)
        		if(a[i] >= 0){
        			if(i != j){
					printf("i = %d  j = %d  Values to be swapped are %d and %d \n",i,j,a[j],a[i]);
        				temp = a[i];
        				a[i] = a[j];
        				a[j] = temp;
        			}
        			j++;
        		}
	}
	else
		printf("That's not possible!!\n");
	printf("Resultant array:\n");
	for(int i=0;i<x;i++)
		printf("%d  ",a[i]);
	printf("\n");
	return 0;
}


