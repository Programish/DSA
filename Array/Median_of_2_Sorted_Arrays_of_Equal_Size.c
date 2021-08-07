#include<stdio.h>
#include"General.h"

int getMedian(int*, int*, int);

int median(int [], int); /* to get median of a sorted array */

/*int getMedian(int arr1[], int arr2[], int n){ // Intermediate Solution because time complexity is O(n)

	int i = 0, j = 0, count, m1 = -1, m2 = -1;
 
    	for (count = 0; count <= n; count++){
        	if (i == n){
            		m1 = m2;
            		m2 = arr2[0];
            		break;
        	}
 
        	else if (j == n){
            		m1 = m2;
            		m2 = arr1[0];
            		break;
        	}
        	if (arr1[i] <= arr2[j]){
            		m1 = m2;
            		m2 = arr1[i];
            		i++;
        	}
        	else{
            		m1 = m2; 
            		m2 = arr2[j];
            		j++;
        	}
    	}
    return (m1 + m2)/2;
}*/

int main(){
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a1[n], a2[n];
	printf("Array 1:");
	INPUT_ARRAY(a1,n);
	printf("\nArray 2:");
        INPUT_ARRAY(a2,n);

	printf("\nMedian of the arrays is %d\n",getMedian(a1, a2, n));

	return 0;
}

int getMedian(int ar1[], int ar2[], int n){  //Best Solution because time complexity is O(logn)
    	if (n <= 0)
        	return -1;
    	if (n == 1)
        	return (ar1[0] + ar2[0])/2;
    	if (n == 2)
        	return (MAX(ar1[0], ar2[0]) + MIN(ar1[1], ar2[1])) / 2;
 
    	int m1 = median(ar1, n);
    	int m2 = median(ar2, n);
 
    	if (m1 == m2)
        	return m1;
 
    	if (m1 < m2){
        	if (n % 2 == 0)
            		return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        	return getMedian(ar1 + n/2, ar2, n - n/2);
    	}
 
    	if (n % 2 == 0)
        	return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    	return getMedian(ar2 + n/2, ar1, n - n/2);
}
 
int median(int arr[], int n){
    	if (n%2 == 0)
        	return (arr[n/2] + arr[n/2-1])/2;
    	else
        	return arr[n/2];
}

/*int getMedian(int ar1[], int ar2[], int n){ // Worst Solution because time complexity is O(nlogn)
    	int j = 0;
    	int i = n - 1;
    	while (ar1[i] > ar2[j] && j < n && i > -1)
        	SWAP(&ar1[i--], &ar2[j++]);
    	SORT(ar1, 0, n-1);
    	SORT(ar2, 0, n-1);
    	return (ar1[n - 1] + ar2[0]) / 2;
}*/
