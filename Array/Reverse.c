#include<stdio.h>
void main(){
	int n,i,x;
	printf("enter no. of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Entered array\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
	for(i=0;i<=n/2;i++){
		x=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=x;
	}
	printf("Reversed array\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
