#include<stdio.h>
#include"General.h"

void threeWayPartition(int arr[], int n, int lowVal, int highVal){
	int start = 0, end = n-1;
	    
    	for (int i=0; i<=end;){
        	if (arr[i] < lowVal)
            		SWAP(&arr[i++], &arr[start++]);
        	else if (arr[i] > highVal)
            		SWAP(&arr[i], &arr[end--]);
        	else
            		i++;
    }
}

int main(){
	int n,a,b;
	printf("Enter no. of elements in array, lower value of range and higher value of range.");
	printf("All of the three values separated by space:");
	scanf("%d %d %d",&n,&a,&b);
	int array[n];
	INPUT_ARRAY(array,n);
	printf("Initial array:\t");
	PRINT_ARRAY(array,n);
	threeWayPartition(array,n,a,b);
	printf("Resultant array:");	
	PRINT_ARRAY(array,n);

	return 0;
}
