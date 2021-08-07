#include<stdio.h>
#include"General.h"

// GFG

int maxProfit(int price[], int n){
    int buy1, profit1, buy2, profit2;
 
    buy1 = buy2 = 9999;
    profit1 = profit2 = 0;
 
    for (int i = 0; i < n; i++) {
	int temp;
        buy1 = MIN(buy1, price[i]);
	temp = price[i] - buy1;
        profit1 = MAX(profit1, temp);
	temp = price[i] - profit1;
        buy2 = MIN(buy2, temp);
	temp = price[i] - buy2;
        profit2 = MAX(profit2, temp);
    }
    return profit2;
}

int main(){
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	INPUT_ARRAY(a,n);
	printf("Maximum Profit = %d\n",maxProfit(a,n));
	return 0;
}
