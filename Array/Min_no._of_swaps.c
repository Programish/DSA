#include<stdio.h>
#include"General.h"

int minSwap(int arr[], int n,int k){
	int count = 0;
    	for (int i = 0; i < n; ++i)
        	if (arr[i] <= k)
            		++count;

	int start = 9999;
	for(int i = 0; i < n; i++)
		if(arr[i] <= k){
			start = i;
			break;
		}
    	int bad = 0;
    	for (int i = start + 1; i < (start+count); ++i)
        	if (arr[i] > k)
            		++bad;
      
	if (start == 9999)
		return start;
    	return bad;
}

int main(){
	int n,k;
	printf("Enter no. of elements and value of k separated by a space:");
	scanf("%d %d",&n,&k);
	int a[n];
	INPUT_ARRAY(a,n);
	int swaps = minSwap(a,n,k);
	if(swaps == 9999)
		printf("\nThere's no elements smaller than or equal to %d , so no. of swaps will be 0!!!\n",k);
	else
		printf("\nNo. of swaps = %d.\n",swaps);

	return 0;
}
