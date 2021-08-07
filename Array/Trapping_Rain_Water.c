#include<stdio.h>
#include"General.h"

int findWater(int arr[], int n)
{
	int left[n];
	int right[n];

	int water = 0;
	printf("\noriginal array:");
    	for(int i = 0;i<n;i++)
        	printf("%d  ",arr[i]);
    	printf("\n");
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = MAX(left[i - 1], arr[i]);
    	printf("\n    left array:");
    	for(int i = 0;i<n;i++)
        	printf("%d  ",left[i]);
    	printf("\n");
	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = MAX(right[i + 1], arr[i]);
    	printf("\n   right array:");
    	for(int i = 0;i<n;i++)
        	printf("%d  ",right[i]);
    	printf("\n");
	for (int i = 0; i < n; i++)
		water += MIN(left[i], right[i]) - arr[i];

	return water;
}

int main()
{
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int arr[n];
	INPUT_ARRAY(arr,n);
	printf("\nMaximum water that can be accumulated is %d units.\n\n",findWater(arr, n));
	return 0;
}

