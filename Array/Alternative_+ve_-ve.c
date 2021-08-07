#include<stdio.h>
#include"General.h"

void Alternate_Pos_Neg(int*,int);

void Alternate_Pos_Neg(int arr[],int n){  //Positive numbers will be at even indexes
					  //Negative numbers will be at od indexes
	int i,j,flag = 0;		  // flag is 0 at even index and 1 in odd index

	for(i = 0,j = 0;i < n-1;i++){
		j = i+1;
		if(!flag){
			if(arr[i] >= 0){
				flag = 1;
				printf("same array in if\n");
				PRINT_ARRAY(arr,n);
				continue;
			}
			else{
				while(arr[j] < 0 && j < n)
					j++;
				if(j == n)
					j = n-1;
				printf("changed array in if\n");
				SWAP(&arr[i],&arr[j]);
				PRINT_ARRAY(arr,n);
			}
		}
		else{
			if(arr[i] < 0){
				flag = 0;
				printf("same array in else\n");
				PRINT_ARRAY(arr,n);
				continue;
			}
			else{
				while(arr[j] >= 0 && j < n)
					j++;
				if(j == n)
					j = n-1;
				printf("changed array in else\n");
				SWAP(&arr[i],&arr[j]);
				PRINT_ARRAY(arr,n);
			}
		}
		flag = !flag;
	}
}

int main(){
	int n;
	printf("Enter no. of elements in array: ");
	scanf("%d",&n);

	int a[n];
	printf("Enter elements in array:\n");
	INPUT_ARRAY(a,n);

	Alternate_Pos_Neg(a,n);
	printf("\n\nAlternate positive and negative elements in array: ");
	PRINT_ARRAY(a,n);

	return 0;
}
