#include<stdio.h>

int main(void){
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in array as there should be only one duplicate of any one element:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
        for(int i = 0;i < n;i++)
	        for(int j = i + 1;j < n;j++)
			if(a[i] == a[j]){
				printf("Duplicate element is %d\n",a[j]);
				break;
			}
	return 0;
}
