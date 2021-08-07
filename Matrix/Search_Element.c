#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"General.h"

bool Search(int** arr, int r, int c, int element) {

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(arr[i][j] == element)
				return true;

	return false;
}

int main(){
	int R, C, value;
	int** a;

	printf("Enter no. of rows, columns and value to be searched, separated by space:");
	scanf("%d %d %d", &R, &C, &value);

	a = (int**) malloc (R * sizeof(int*));
	INPUT_MATRIX(a, R, C);
	PRINT_MATRIX(a, R, C);

	Search(a, R, C, value) ? printf("Element Found ;]\n") : printf("Element not Found !!!\n");

	return 0;
}
