#include<stdio.h>

void Common(int*,int,int*,int,int*,int);

//void Common(int arr1[],int n1,int arr2[],int n2,int arr3[],int n3){// Worst Solution; Time Complexity is O(n^3)
//
//	int count = 0,flag = 0;
//	
//	for(int i = 0;i < n1;i++){
//		for(int j = 0;j < n2;j++){
//			if(arr1[i] == arr2[j])
//				for(int k = 0;k < n3;k++)
//					if(arr2[j] == arr3[k]){
//						flag = 1;
//						break;
//					}
//			if(flag == 1)
//				break;
//		}
//		if(flag == 1)
//			printf("Common element %d is %d\n",++count,arr1[i]);
//		flag = 0;
//	}
//}
//
int main(){

	int n1,n2,n3;
	printf("Enter no. of elements in 3 arrays separated by a space: ");
	scanf("%d %d %d",&n1,&n2,&n3);

	int a1[n1],a2[n2],a3[n3];
	
	printf("Enter %d elements in 1st array:\n",n1);
	for(int i = 0;i < n1;i++)
		scanf("%d",&a1[i]);
	printf("Enter %d elements in 2nd array:\n",n2);
        for(int i = 0;i < n2;i++)
        	scanf("%d",&a2[i]);
	printf("Enter %d elements in 3rd array:\n",n3);
        for(int i = 0;i < n3;i++)
        	scanf("%d",&a3[i]);

	Common(a1,n1,a2,n2,a3,n3);

	return 0;
}

void Common(int arr1[],int n1,int arr2[],int n2,int arr3[],int n3){  //Best Solutiom ; Time complexity is O(n)
	int i, j, k,count;
    	i = j = k = count = 0;
    	while (i < n1 && j < n2 && k < n3){
        	if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            		printf("Common element %d is %d\n",++count,arr1[i]);   
            		i++; 
            		j++; 
            		k++; 
 		} 
		else if ((arr1[i] <= arr2[j]) && (arr1[i] <= arr3[k]))
            		i++;
		else if ((arr2[j] <= arr3[k]) && (arr2[j] <= arr1[i]))
            		j++;
		else
            		k++;
    	}
}
