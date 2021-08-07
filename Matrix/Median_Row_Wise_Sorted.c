#include<stdio.h>
#include<stdlib.h>
#include"General.h"

int main() {
	
	int R, C;
	int** a;
	printf("Enter no. of rows, columns (rows and columns should be ODD):");
	scanf("%d %d", &R, &C);

	a = (int**) malloc (R * sizeof(int*));
	INPUT_MATRIX(a, R, C);
	PRINT_MATRIX(a, R, C);
	
	SORT_MATRIX(a, R, C);

	printf("\nMedian = %d\n",a[R / 2][C / 2]);

	return 0;
}
