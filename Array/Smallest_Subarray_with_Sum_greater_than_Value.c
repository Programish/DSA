#include<stdio.h>
#include"General.h"

int Smallest_subarray(int*,int,int);

int Smallest_subarray(int arr[], int n, int value){  // Best Solution because time compleity is O(n)
    int curr_sum = 0, min_len = n + 1;
 
    int start = 0, end = 0;
    while (end < n) {
        while (curr_sum <= value && end < n)
            curr_sum += arr[end++];
 
        while (curr_sum > value && start < n) {
            if (end - start < min_len)
                min_len = end - start;
 
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}

int main(){
	int n,s;
	printf("Enter no. of elements in array and value separated by space:");
	scanf("%d %d",&n,&s);
	int a[n];
	INPUT_ARRAY(a,n);
	int result = Smallest_subarray(a,n,s);
	(result == n+1)?printf("Not possible!!!\n") : printf("Smallest subarray is %d.\n",result);
	
	return 0;
}

/* int Smallest_subarray(int arr[], int n, int value){  // Worst Solution because time compleity is O(n^2)
	int min_len = n + 1;

	for (int start=0; start<n; start++)
	{
		int curr_sum = arr[start];

		if (curr_sum > value) return 1;

		for (int end=start+1; end<n; end++)
		{
			curr_sum += arr[end];

			if (curr_sum > value && (end - start + 1) < min_len)
				min_len = (end - start + 1);
		}
	}
	return min_len;
}*/
