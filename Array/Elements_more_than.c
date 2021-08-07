#include<stdio.h>
#include"General.h"

void times(int arr[],int n,int factor){
	
	int temp = 0,count = 0,i;
	i = temp;
	for(;i < n;i++){
		if(arr[i] == arr[temp]){
			count++;
			if(count > factor){
				printf("%d is %d times.\n",arr[temp],count);
				count = 0;
				i = temp;
				temp++;
			}
		}
		if(i == n-1){
			count = 0;
                        i = temp;
                        temp++;
		}
	}
}

int main(){
	int n,k;
	printf("Enter no. of elemnts and value of k separated by a space:");
	scanf("%d %d",&n,&k);
	int a[n];
	INPUT_ARRAY(a,n);
	int temp = n/k;
	printf("\nRequired elements (who have occurred more than %d times) are : \n",temp);
	times(a,n,n/k);
	printf("\n");
	return 0;
}
