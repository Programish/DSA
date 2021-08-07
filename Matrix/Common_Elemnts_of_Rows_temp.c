#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include <limits.h>

void printCommonElements(int** mat, int M, int N) {

	for(int i = 0; i < M; i++)
		SORT(mat[i], 0, N-1);
	printf("Sorted:\n");
	PRINT_MATRIX(mat, M, N);

	//Replace duplicate elements with INT_MAX
	for(int i = 0; i < M; i++) {
		int distinct = 0;
		for(int j = 1; j < N; j++) {
			if(mat[i][j] == mat[i][distinct])
				mat[i][j] = INT_MAX;
			else
				distinct = j;
		}
	}
	PRINT_MATRIX(mat, M, N);

	//Check common elements
	printf("Distinct:");
	int test_indx = 0, count = 1;
	for(int i = 1, j = 0; i < M; i++) {
	//	printf("i = %d\n", i);
		if(mat[0][test_indx] != INT_MAX) {
			for(j = 0; j < N; j++)
				if(mat[0][test_indx] == mat[i][j]) {
					count++;
			//		printf("j = %d\n", j);
				        j = 0;	
					break;
				}
			if((j == N)&&(count == 1)) {
				test_indx++;
				i = 0;
				count = 1;
				if(test_indx == N) {
					printf("\n");
					return;
				}
				continue;
			}
			if(count == M) {
				printf("%d\t", mat[0][test_indx]);
				test_indx++;
				i = 0;
				count = 1;
				if(test_indx == N) {
					printf("\n");
					return;
				}
				continue;
			}
			if(test_indx == N) {
				printf("\n");
				return;
			}
		}
		else {
			test_indx++;
			i = 0;
			count = 1;
			if(test_indx == N) {
				printf("\n");
				return;
			}
			continue;
		}
	}

	printf("\n");
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
