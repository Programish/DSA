#include<stdio.h>

int main(void){
	int n,count = 0;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in array:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < n;){
		if(a[i] == 0)
			i++;
		i += a[i];
		count++;
		if(i >= (n-1))
			break;
	}
	printf("Minimum no. of jumps = %d\n",count);
	return 0;
}
