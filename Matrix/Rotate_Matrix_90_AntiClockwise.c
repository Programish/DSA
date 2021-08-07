#include <stdio.h>
#include "General.h"
#include <stdlib.h>

void rotate90AntiClockwise(int**, int);

int main() {

	int N;
	printf("Enter value of N for NxN Marix:");
	scanf("%d", &N);

	int** mat = (int**) malloc (N * sizeof(int*));
	INPUT_MATRIX(mat, N, N);
	printf("Initial Matrix:\n");
	PRINT_MATRIX(mat, N, N);
	printf("Final Matrix:\n");

	rotate90AntiClockwise(mat, N);

	return 0;
}
/*
// Function1 to rotate the matrix 90 degree clockwise
void rotate90AntiClockwise(int** arr, int N) {
	// printing the matrix on the basis of
    	// observations made on indices.
    	for (int j = N - 1; j >= 0; j--) {
        	for (int i = 0; i < N; i++)
            		printf("%d/t", arr[i][j]);
        	printf("\n");
    	}
}

// Function2 to rotate the matrix 90 degree anticlockwise
void rotate90AntiClockwise(int** arr, int N) {
     
    	// First rotation
    	// with respect to middle row
    	for(int i = 0; i < N / 2; i++)
        	for(int j = 0; j < N; j++) {
            		int temp = arr[i][j];
            		arr[i][j] = arr[N - 1 - i][j];
            		arr[N - 1 - i][j] = temp;
        	}
     
    	// Second rotation
    	// with respect to Secondary diagonal
    	for(int i = 0; i < N; i++)
        	for(int j = 0; j < N - i; j++) {
            		int temp = arr[i][j];
            		arr[i][j] = arr[N - 1 - j][N - 1 - i];
            		arr[N - 1 - j][N - 1 - i] = temp;
        	}
    	
	PRINT_MATRIX(arr, N, N);
}
*/
// Function3 to rotate the matrix 90 degree anticlockwise
void rotate90AntiClockwise(int** arr, int N) {
     
    	// First rotation
    	// with respect to middle column
    	for(int i = 0; i < N; ++i)
        	for(int j = 0; j < N / 2; ++j) {
            		int temp = arr[i][j];
            		arr[i][j] = arr[i][N - j - 1];
            		arr[i][N - j - 1] = temp;
        	}
     
    	// Second rotation
    	// with respect to main diagonal
    	for(int i = 0; i < N; ++i)
        	for(int j = 0; j < i; ++j) {
            		int temp = arr[i][j];
            		arr[i][j] = arr[j][i];
            		arr[j][i] = temp;
        	}

    	PRINT_MATRIX(arr, N, N);
}
