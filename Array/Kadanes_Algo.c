#include<stdio.h>

void maxSubArraySum(int a[],int size){
	int max_so_far = a[0], max_ending_here = 0,start = 0,end = 0,s = 0;
	for (int i = 0; i < size;i++){
		max_ending_here += a[i];			 
	        if (max_so_far < max_ending_here){
    			max_so_far = max_ending_here;
	                start = s;
	                end = i;		
			printf("1st if: max_so_far is %d, start is %d, end is %d, i is %d\n",max_so_far,start,end,i);
		}			 
	        if (max_ending_here < 0){
	                max_ending_here = 0;
	                s = i + 1;
			printf("2nd if: max_ending_here is %d, s is %d, i is %d\n",max_ending_here,s,i);
	        }
	}
	printf("Maximum contiguous sum is: %d\n",max_so_far);
	printf("Starting index: %d\nEnding index: %d\n",start,end);
}

int main(void){
	int n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&arr[i]);
	maxSubArraySum(arr,n);
	return 0;
}
