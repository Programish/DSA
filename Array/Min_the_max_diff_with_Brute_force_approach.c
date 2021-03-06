/* 1 array will be given
 * Elements of the array will be considered as heights of towers
 * Factor k is the value by which each element of the array 
 * must be either added or subtracted.
 * Array with negative elements should not be considered,
 * because heights can't be in negative.
 * If initially n elements are there in array
 * Then 2^n combination of array can be created by subtraction
 * and addition of k.
 * We have to minimize the maximum difference.
 * So, once a array is created(out of those 2^n combination)
 * Then that array should be sorted
 * After sorting, difference of 1st and last element of that
 * array should be calculated. If the calculated difference is smaller 
 * than previous value of difference, then only diff should be updated 
 * to current difference, else leave diff as it is
 * For that 2^n combinations i is iterated
 * Binary value of i checked by shifting right
 * Acc. to i either k will be added or k will be subtracted 
 * For example a[3] = {1,15,10}
 * when i is 0(000 in bit) then k will be added to all 3 elements
 * i is 1(001 in bit) then then k will be subtracted from 1 element
 * and then k will be added to other 2 element
 * i is 2(010 in bit) k will be subtracted from middle element and
 * then k will be added to other 2 elements
 * .......
 * like this when i is 7(111) then k will be subtracted from all the elements
 */

#include<stdio.h>
#include<math.h>

void sort(int* a,int n){
	int temp;
	for(int i = 0;i < n;i++)
		for(int j = i + 1;j < n;j++)
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

int main(void){
	int l,k;
	printf("Enter no. of elements and factor k separated by a space:\n");
	scanf("%d %d",&l,&k);
	int a[l];
	printf("Enter elements in array:\n");
	for(int i = 0;i < l;i++)
		scanf("%d",&a[i]);
	int diff = 99999;
	int digit = 0,flag = 0;
	for(int i = 0;i < pow(2,l);i++){
		digit = 0;  //this variable is to iterate throuth elements of array
		int copy[l];
		for(int i = 0;i < l;i++)
			copy[i] = a[i];
		while(digit < l){  
			if((i >> digit) & 0b1){ //k will be subtracted from that element only where this if condition satisfies
				printf("if in array %d   digit %d\n",i + 1,digit + 1);
				copy[digit] -= k;
				printf("Array%d digit%d   is %d\n",i + 1,digit + 1,copy[digit]);
			}
			else{  // if k is not subtracted then it shoul be added to that element
				printf("else in array %d   digit %d\n",i+1,digit+1);
				copy[digit] += k;
				printf("Array%d digit%d   is %d\n",i+1,digit + 1,copy[digit]);
			}
			digit++;
		}
		sort(copy,l);
		if(copy[0] >= 0)  //Checking that array  doesn't contain -ve elements
			flag = 1;
                if(flag > 0)
              	 	if((copy[l - 1] - copy[0]) < diff)
               			diff = copy[l - 1] - copy[0];
		flag = 0;

		printf("Diff of array%d is %d \n\n\n",i+1,diff);
	}
	printf("Minimized maximum difference = %d\n\n",diff);
	return 0;
}
