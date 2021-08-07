#include<stdio.h>
#include"General.h"

int findMinOps(int arr[], int n)
{
	int ans = 0;

	for (int i=0,j=n-1; i<=j;){
		if (arr[i] == arr[j]){
			i++;
			j--;
		}
		else if (arr[i] > arr[j]){
			j--;
			arr[j] += arr[j+1] ;
			ans++;
		}
		else{
			i++;
			arr[i] += arr[i-1];
			ans++;
		}
	}
	return ans;
}

int main(){
	int n;
	printf("Enter no. of elements in array:");
	scanf("%d",&n);
	int a[n];
	INPUT_ARRAY(a,n);
	
	int no_of_merge = findMinOps(a, n);
	printf("\nMinimum no. of merge to make palindrome array are:%d\n",no_of_merge);

	return 0;
}

