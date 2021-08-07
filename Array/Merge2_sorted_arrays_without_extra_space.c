#include<stdio.h>

/* Solution-----
 * First smallest element will be placed in 1st array
 * Then increasing sorting in array1 (taking 2 elements 
 * from array1 starting and checking that, is there any 
 * element in array2 which is in between or equal to 
 * those two elements if yes then swap that element with
 * 2nd element of those choosed 2 elements) array2
 * Once array1 is sorted then array2 can be sorted normally
 * using SORT()
 */
void ENTRY(int a[],int n){
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
}

void PRINT(int a[],int n){
	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
}

void SWAP(int *num1,int *num2){
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

void SORT(int a[],int n){
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
			if(a[j] < a[i])
				SWAP(&a[j],&a[i]);
}

void MERGE(int arr1[],int n1,int arr2[],int n2){
	if(arr2[0] < arr1[0])
		SWAP(&arr2[0],&arr1[0]);
	for(int i = 0;i < n1-1;i++){
		int k = 0;
		while(k < n2){
                	if((arr2[k] >= arr1[i]) && (arr2[k] <= arr1[i+1]))
                        	SWAP(&arr2[k],&arr1[i+1]);
                        k++;
                }
	}
	SORT(arr2,n2);
	printf("Sorted array1: ");
	PRINT(arr1,n1);
	printf("\n");
	printf("Sorted array2: ");
	PRINT(arr2,n2);
	printf("\n");
	printf("Resultant sorted array: ");
	PRINT(arr1,n1);
	PRINT(arr2,n2);
	printf("\n");
}

int main(void){
	int n1,n2;
	printf("Enter no. of elements in array 1 & 2 separated by space :\n");
	scanf("%d %d",&n1,&n2);
	int a1[n1],a2[n2];
	printf("Enter elements in array1 in increasing order:\n");
	ENTRY(a1,n1);
	printf("Enter elements in array2 in increasing order:\n");
        ENTRY(a2,n2);
	printf("Array 1: ");
	PRINT(a1,n1);
	printf("\nArray 2: ");
	PRINT(a2,n2);
	printf("\n");
	MERGE(a1,n1,a2,n2);
	return 0;
}
