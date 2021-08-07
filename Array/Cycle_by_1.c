#include<stdio.h>
int main(void){
	int l,temp;
	printf("Enter length of array: ");
	scanf("%d",&l);
	int a[l];
	printf("Enter elements in array:\n");
	for(int i = 0;i < l;i++)
		scanf("%d",&a[i]);
	temp = a[l-1];
	for(int i = l - 1;i > 0;i--){
		a[i] = a[i -1];
	}
	a[0] = temp;
	printf("Rotated array by one:");
	for(int i = 0;i < l;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
