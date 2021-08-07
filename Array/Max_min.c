#include<stdio.h>
void main(){
	int n,i;
	printf("Enter no. of elements \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int max=a[0];
	int min=a[0];
	i=0;
	while(i<n){
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
		i++;
	}
	printf("Maximum:%d  Minimum:%d\n",max,min);
}
