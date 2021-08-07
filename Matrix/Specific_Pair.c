// A Naive method to find maximum value of mat[d][e]
// - ma[a][b] such that d > a and e > b
#include <stdio.h>
#include "General.h"
#include <stdlib.h>
#include <limits.h>

// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.

int findMaxValue(int**, int);

/*int findMaxValue(int** mat, int N) {  // Worst Solution because time Complexity is O(n^4)
	// stores maximum value
	int maxValue = INT_MIN;

	// Consider all possible pairs mat[a][b] and
	// mat[d][e]
	for (int a = 0; a < N - 1; a++)
		for (int b = 0; b < N - 1; b++)
			for (int d = a + 1; d < N; d++)
				for (int e = b + 1; e < N; e++)
					if (maxValue < (mat[d][e] - mat[a][b]))
						maxValue = mat[d][e] - mat[a][b];

	return maxValue;
}
*/
int main() {
	
	int N;                                                              	
        int** a;
        printf("Enter value of N for NxN matrix:");
        scanf("%d", &N);
                                                                                
        a = (int**) malloc (N * sizeof(int*));
        INPUT_MATRIX(a, N, N);
        PRINT_MATRIX(a, N, N);
	printf("Maximum Difference Value is %d\n", findMaxValue(a, N));

	return 0;
}

int findMaxValue(int** mat, int N) {  // Good Solution because time complexity is O(n^2) 
    	//stores maximum value	      // but bad thing is that space complexity is increased to O(n^2)
    	int maxValue = INT_MIN;
 
    	// maxArr[i][j] stores max of elements in matrix
    	// from (i, j) to (N-1, N-1)
    	int maxArr[N][N];
 
    	// last element of maxArr will be same's as of
    	// the input matrix
    	maxArr[N-1][N-1] = mat[N-1][N-1];
 
    // preprocess last row
    // In this last row is processed in a way every element is 
    // replaced with maximum element to its right side.
    	int maxv = mat[N-1][N-1];  // Initialize max
    	for (int j = N - 2; j >= 0; j--) {
        	if (mat[N-1][j] > maxv)
            		maxv = mat[N - 1][j];
        	maxArr[N-1][j] = maxv;
    	}
 
    // preprocess last column
    // In this last column is processed in a way every element is 
    // replaced with maximum element to its down side.
    	maxv = mat[N - 1][N - 1];  // Initialize max
    	for (int i = N - 2; i >= 0; i--) {
        	if (mat[i][N - 1] > maxv)
            		maxv = mat[i][N - 1];
        	maxArr[i][N - 1] = maxv;
    	}
 
    // preprocess rest of the matrix from bottom
    // In this whole matrix is processed except last row and last column
    // because those are already processed previously.
    /* 
     * For a element at [i,j] position in maxArray
     * Firstly maxArray[i+1][j+1] - mat[i][j] is checked, if this value
     * is greater than maxValue then maxValue is replaced by maxArray[i+1][j+1] - mat[i][j]
     * Secondly maximum element from maxArray[i][j+1], maxArray[i+1][j], mat[i][j]
     * is placed at maxArray[i][j]
     * At last maxValue is returned as maximum difference.
     */
    	for (int i = N-2; i >= 0; i--)
        	for (int j = N-2; j >= 0; j--) {
            		// Update maxValue
            		if (maxArr[i+1][j+1] - mat[i][j] > maxValue)
                		maxValue = maxArr[i + 1][j + 1] - mat[i][j];
 
            	// set maxArr (i, j)
            		maxArr[i][j] = MAX(mat[i][j], MAX(maxArr[i][j + 1], maxArr[i + 1][j]) );
        	}
 
    return maxValue;
}
