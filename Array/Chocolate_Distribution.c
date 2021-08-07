#include<stdio.h>
#include"General.h"

/* First of all sort the array
 * 3 temp variables are indexes, for checking
 * the min diff between max and min element.
 * 3 final variables are the final indexes and 
 * difference of max and min element.
 * Both of end variables are total no. of 
 * students ahead of both the start variables.
 * We've to find the min diff that's why we're
 * updating the final variables only when temp_diff
 * is smaller than final_temp.
 */

void findMinDiff(int arr[],int n,int students){
	
	SORT(arr,0,n-1);
	
	int final_start, final_end, final_diff = 9999;
	int temp_start, temp_end = students-1, temp_diff;
	
	for(int i = 0; i <= n-students; i++){
		temp_start = i;
		temp_diff = arr[temp_end] - arr[temp_start];
		printf("temp_start=%d\ttemp_end=%d\ttemp_diff=%d\n",temp_start,temp_end,temp_diff);	
		
		if(temp_diff < final_diff){
			final_start = temp_start;
			final_end = temp_end;
			final_diff = temp_diff;
		}
		
		printf("final_start=%d\tfinal_end=%d\tfinal_diff=%d\n\n",final_start,final_end,final_diff);	
		temp_end++;
	}
	
	printf("Minimum Difference is %d.\n",final_diff);
	printf("Packets of Chocolates to be distibuted are:");
	for(int i = final_start; i <= final_end; i++)
		printf("\t%d",arr[i]);
	printf("\n");
}

int main(){
	int n,m;
	printf("Enter no. of elements in array(no. of packets of chocolates) and no. of students separated by a space:");
	scanf("%d %d",&n,&m);
	int a[n];
	INPUT_ARRAY(a,n);
	printf("\n");
	findMinDiff(a,n,m);
	return 0;
}
