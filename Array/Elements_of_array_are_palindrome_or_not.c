#include<stdio.h>
#include"General.h"

int palindrome_number(int n){
	int copy = n,reverse = 0;
	
	while(copy > 0){
		reverse = reverse*10 + copy%10;
		copy = copy/10;
	}

	if(reverse == n)
		return 1;
	return 0;
}

int palindrome_array(int arr[],int n){

	for(int i = 0; i < n; i++)
		if(!palindrome_number(arr[i]))
				return 0;
	return 1;
}

int main(){
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	INPUT_ARRAY(a,n);
	palindrome_array(a,n) ? printf("\nArray have palindrome numbers.\n") : printf("\nArray don't have palindrome numbers.\n");

	return 0;
}
