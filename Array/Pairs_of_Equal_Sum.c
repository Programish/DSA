#include<stdio.h>

void Count_Pairs(int*,int,int);

void Count_Pairs(int arr[],int n,int value){  //Worst Solution; Time Complexity is O(n^2)
	
	int count = 0;
	for(int i = 0;i < n-1;i++)
		for(int j = i+1;j < n;j++)
			if(arr[i]+arr[j] == value)
				printf("Pair %d is (%d,%d)\n",++count,arr[i],arr[j]);
}

int main(){
	int n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);

	int a[n];

	printf("Enter elements in array:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	
	int sum;
	printf("Enter the value of the sum to be checked: ");
	scanf("%d",&sum);

	Count_Pairs(a,n,sum);

	return 0;
}
