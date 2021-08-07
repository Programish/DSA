#include<stdio.h>
#include"General.h"

int main(void){
	int l;
	printf("Enter no. of elements:");
	scanf("%d",&l);
	int a[l];
	INPUT_ARRAY(a,l);	
	int final_sum = 0,temp_sum = 0;
	for(int i = 0;i < l;i++){
		temp_sum += a[i];
		if(final_sum < temp_sum){
	 		final_sum = temp_sum;
		}
		if(temp_sum < 0){
			temp_sum = 0;
		}
	}
	temp_sum = MAX_ARRAY(a,l);
	if(0 == final_sum)
		final_sum = temp_sum;
	printf("Largest contiguous sum = %d\n",final_sum);
	return 0;
}	
