#include<stdio.h>
void main(){
	int n,i,j,x;
	printf("Enter no. of elements \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements only in 0,1,2 \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nUnsorted array: ");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;){
			if(a[i]==1 && a[j]==0){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				++j;
			}
			else if(a[i]==2 && a[j]==0){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				++j;
			}
			else if(a[i]==2 && a[j]==1){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				++j;
			}
			else
				++j;          
		}
	printf("\n  Sorted array: ");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
