#include<stdio.h>
#include"General.h"

int max_prod(int*,int);

int max_prod(int arr[],int n){
	int final_prod = 1,temp_prod = 1;
	for(int i = 0;i < n;i++){
		temp_prod *= arr[i];
		if(final_prod < temp_prod)
 			final_prod = temp_prod;
	}
	temp_prod = MAX_ARRAY(arr,n);
	if(final_prod < temp_prod)
		final_prod = temp_prod;
	return final_prod;
}



int main(void){
	int l,res;
	printf("Enter no. of elements:");
	scanf("%d",&l);
	int a[l];
	INPUT_ARRAY(a,l);
	res = max_prod(a,l);
	printf("Largest subarray product = %d\n",res);
	return 0;
}	
