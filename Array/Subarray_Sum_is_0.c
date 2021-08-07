#include<stdio.h>
#include"General.h"

void Subarray_sum_0(int*,int);

void Subarray_sum_0(int arr[],int n){

	int sum,i,j,flag = 0;

	for(i = 0;i < n;i++){
		sum = 0;
		for(j = i;j < n;j++){
			sum += arr[j];
			if(!sum){
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}

	if(flag)
		printf("From index %d to %d subarray sum is 0.\n",i,j);
	else
		printf("There is no subarray with sum equal to 0.\n");
}

int main(){
	int n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);

	int a[n];

	printf("Enter elements in array:\n");
	INPUT_ARRAY(a,n);

	Subarray_sum_0(a,n);
	
	return 0;
}
