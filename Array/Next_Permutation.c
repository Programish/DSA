#include<stdio.h>

void Swap(int*,int*);

void Reverse(int arr[],int initial,int final){
	for(int i = initial;i < final-initial;i++)
		Swap(&arr[i],&arr[final-i+initial]);
}

void Swap(int *n1,int *n2){
	int temp = *n1;
       	*n1 = *n2;
        *n2 = temp;
}

int* NextPermutation(int arr[],int n){  // Best Solution; Both the complexities are O(1)

	int breakpoint = 9999,i,j;

	for(i = n-2;i >= 0;i--)
		if(arr[i] < arr[i+1])
			break;
	if(i < 0){
		printf("Descending array\n");
		Reverse(arr,0,n-1);
	}
	else{
		for(j = n-1;j > i;j--)
			if(arr[j] > arr[i])
				break;
		Swap(&arr[i],&arr[j]);
		Reverse(arr,i+1,n-1);
	}
	return arr;
}	

int main(){

	int n;
	printf("Enter no. of digits in the number: ");
	scanf("%d",&n);

	int num[n];
	printf("Enter digits:\n");

	for(int i = 0;i < n;i++)
		scanf("%d",&num[i]);

	printf("Entered number is: ");
	for(int i = 0;i < n;i++)
		printf("%d  ",num[i]);
	printf("\n");

	NextPermutation(num,n);

	printf("Next Permutation of Entered number is: ");
	for(int i  = 0;i < n;i++)
		printf("%d  ",num[i]);
	printf("\n");

	return 0;
}

// WORST case will be with Brute Force Approach
// Create all the permutations from the digits of given number
// and then find the number which is given as input.
// The number next to it will be the result.
