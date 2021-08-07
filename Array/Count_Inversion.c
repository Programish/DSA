#include<stdio.h>

void INVRSN_CNT(int arr[],int n){
	int count = 0;
	for(int i = 0;i < n-1;i++)
		for(int j = i+1;j < n;j++)
			if(arr[i] > arr[j])
				printf("Inversion %d is (%d,%d)\n",++count,arr[i],arr[j]);
	printf("Total inversion count is %d.\n",count);
}
int main(){
	int n;
	printf("Enter length of array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in array:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	INVRSN_CNT(a,n);
	return 0;
}
