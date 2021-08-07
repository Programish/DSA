#include <stdio.h>
#include <stdlib.h>
#include "General.h"

void printCommonElements(int** mat, int M, int N) {

	int n = 1, row1column = 0, flag, count, temp_arr[M];
	temp_arr[0] = mat[0][0];
	for(int i = 1; i < N; i++) {
		flag = 0;
		for(int j = 0; j < n; j++)
			if(mat[0][i] == temp_arr[j])
				flag = 1;
		if(!flag)
			temp_arr[n++] = mat[0][i];
	}

	printf("\n\n\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", temp_arr[i]);
	printf("\n");
	int times = 1;
	printf("Common elements in all rows:");
	for(int i = 1;;) {
		flag = 0;
		count = 0;
		for(int j = 0; j < N; j++) {
			if(mat[i][j] == temp_arr[row1column]) {
				count++;
				if(count == M-1) {
					printf("\t%d", temp_arr[row1column++]);
					if(row1column == n)
						return;
				}
				flag = 1;
				continue;
			}
			if((j == N-1) && (!flag)) {
				i++;
				if(i == M) {
					i = 1;
					times++;
					if(times == n)
						return;
				}
			}
		}
	}
				
}

int main() {

	int M, N;
	int** arr;

	printf("Enter numbers of rows and columns of matrix separated by a space:");
	scanf("%d %d", &M, &N);
	
	arr = (int**) malloc (M * sizeof(int*));
	INPUT_MATRIX(arr, M, N);
	PRINT_MATRIX(arr, M, N);

	printCommonElements(arr, M, N);

	return 0;
}
