#include<stdio.h>
#include"General.h"

/* First the array is sorted.
 * After that both the start pointers(variables) are initialised to 0
 * We have to move temp_end in array until there's a break in
 * increasing order. When the order breaks , check that the 
 * difference between both the temp variables and both 
 * the final variables. If the difference between temp variables
 * is greater than the difference between final varibles, at 
 * that time update the final variables, else leave final 
 * variables as it is. And at lst print the values from final_start
 * index to final_end index.
 */

void sequence(int *,int);

void sequence(int arr[],int n){
	
	SORT(arr,0,n-1);

	int final_start = 0,final_end = 1,temp_start = 0,temp_end;

	for(int i = 1;i < n;i++){
		temp_end = i;
		if((arr[temp_end]-arr[temp_end-1] != 1) && ((temp_end-temp_start) > (final_end-final_start))){
			final_start = temp_start;
			final_end = i-1;
			temp_start = i;
		}
	}
	printf("final_start = %d\nfinal_end = %d\ntemp_start = %d\ntemp_end = %d\n",final_start,final_end,temp_start,temp_end);
	printf("\nResultant Array:");
	PRINT_ARRAY(arr,n);
	printf("\nRequired Sequence:");
	for(int i = final_start;i <= final_end;i++)
		printf("%d\t",arr[i]);
}

int main(){
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	INPUT_ARRAY(a,n);
	sequence(a,n);
	printf("\n");
	return 0;
}
