#include<stdio.h>
#include"General.h"

int isSubarray(int*,int,int*,int);

int isSubarray(int arr1[],int n1,int arr2[],int n2){
	int flag;
	for(int i = 0;i < n2;i++){
		flag = 0;
		for(int j = 0;j < n1;j++){
			if(arr2[i] == arr1[j]){
				flag = 1;
				break;
			}
			if((j == (n1-1)) && (!flag)){
				flag = 2;
				break;
			}
		}
		if(flag == 2)
			break;
	}
	return flag;
}

int main(){
	int n1,n2;
	printf("Enter no. of elements in parent array and subarray separated by a space.\nNo. of elements of parent array should be greater than subarray:");
	scanf("%d %d",&n1,&n2);
	int a1[n1],a2[n2];
	printf("Parent array elements:\n");
	INPUT_ARRAY(a1,n1);
	printf("\nSubarray elements:\n");
	INPUT_ARRAY(a2,n2);
	int f = isSubarray(a1,n1,a2,n2);
	(f == 2)?printf("\n2nd array is not subarray\n"):printf("\n2nd array is subarray\n");
	return 0;
}		
