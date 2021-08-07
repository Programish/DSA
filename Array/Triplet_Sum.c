#include<stdio.h>
#include"General.h"

int find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;

	SORT(A, 0 , arr_size-1);

	for (int i = 0; i < arr_size - 2; i++) {
		l = i + 1; 
		r = arr_size - 1; 
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				printf("Triplet is %d, %d, %d", A[i],
					A[l], A[r]);
				return 1;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else //(A[i] + A[l] + A[r] > sum)
				r--;
		}
	}
	return 0;
}

int main()
{
	int n,sum;
	printf("Enter no. of elements in array and the value of the sum separated by a space:");
	scanf("%d %d",&n,&sum);
	int a[n];
	INPUT_ARRAY(a,n);
	find3Numbers(a, n, sum)?printf("\nTriplet Found\n"):printf("\nTriplet not Found!!!\n");

	return 0;
}

