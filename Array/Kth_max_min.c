#include<stdio.h>
void main(){
	int n , i , k , j , x;
	printf("Enter no. of elements \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter value of k:");
	scanf("%d",&k);
	for(i=0;i<n;i++) //for sorting in increasing order
		for(j=i+1;j<n;j++)
			if(a[i]>a[j]){
				x=a[j];
				a[j]=a[i];
				a[i]=x;
			}

	if (n != 0 || n != 1){
		int temp[n];
	    	j = 0;
	        for (i = 0; i < n - 1; i++)
			if (a[i] != a[i + 1])
				temp[j++] = a[i];
		  	temp[j++] = a[n - 1];
		    	for (i = 0; i < j; i++)
				a[i] = temp[i];
	}
	else 
		j = n;

	printf("Sorted array\n");
	for(i=0;i<j;i++)
		printf("%d  ",a[i]);
	printf("\n %dth Maximum:%d & %dth Minimum:%d\n",k,a[j-k],k,a[k-1]);
}
