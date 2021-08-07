#include<stdio.h>

int maxProfit(int *,int);

int min(int a,int b){
	if(a > b)
		return b;
	return a;
}

int max(int a,int b){
	if(a > b)
		return a;
	return b;
}

int maxProfit(int price[],int n){ //Best Solution ; Space Complexity is O(1) and Time Complexity is O(1)

	int maxProfit = 0;
	int minSoFar = price[0];

	for(int i = 0;i < n;i++){
		minSoFar = min(minSoFar,price[i]);
		int Profit = price[i] - minSoFar;
		maxProfit = max(maxProfit,Profit);
	}
	printf("minSoFar = %d \n",minSoFar);
	return maxProfit;
}

// Driver code
int main()
{
    int price[] = { 100, 180, 260, 310,
                    40, 535, 695 };
    int n = 7;

    printf("Result = %d\n",maxProfit(price,n));

    return 0;
}

//int maxProfit(int price[],int n){//  Intermediate Solution ; Space Complexity is O(n) and Time Complexity is O(1)
// 
//	int temp[n];
//	int maxSoFar = 0;
//	int maxProfit = 0;
//
//	for(int i = n-1;i >= 0;i--){
//		if(price[i] > maxSoFar)
//			maxSoFar = price[i];
//		temp[i] = maxSoFar;
//		maxProfit = max(maxProfit,temp[i]-price[i]);
// 	}
// 	printf("maxSoFar = %d\n",maxSoFar);
// 	return maxProfit;
//}

//int maxProfit(int price[],int n){
// 
//	int maxSoFar = 0;
//	int maxProfit = 0;
//
//	for(int i = n-1;i >= 0;i--){
//		if(price[i] > maxSoFar)
//			maxSoFar = price[i];
//		maxProfit = max(maxProfit,maxSoFar-price[i]);
//	}
// 	printf("maxSoFar = %d\n",maxSoFar);
// 	return maxProfit;
//}

//int maxProfit(int Price[],int n){  // Worst Solution ; Space Complexity is O(1) and Time Complexity is O(n^2)
//
//	int maxProfit = 0;
//	
//	for(int i = 0;i < n;i++)
//		for(int j = i+1;j < n;j++)
//			maxProfit = max(Price[j] - Price[i],maxProfit);
//	return maxProfit;
//}
