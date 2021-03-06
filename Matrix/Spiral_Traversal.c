#include<stdio.h>
#include"General.h"

void spiralPrint(int m, int n, int** a){
	int i, k = 0, l = 0;

	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator
	*/

	while (k < m && l < n) {
		/* Print the first row from
			the remaining rows */
		for (i = l; i < n; ++i) {
			printf("%d  ",a[k][i]);
		}
		k++;

		/* Print the last column
		from the remaining columns */
		for (i = k; i < m; ++i) {
			printf("%d  ",a[i][n - 1]);
		}
		n--;

		/* Print the last row from
				the remaining rows */
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				printf("%d  ",a[m - 1][i]);
			}
			m--;
		}

		/* Print the first column from
				the remaining columns */
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				printf("%d  ",a[i][l]);
			}
			l++;
		}
	}
}

/* Driver Code */
int main()
{
	int R, C;
	printf("Enter no. of rows and columns separated by a space:");
	scanf("%d %d", &R, &C);
	int** a;
	
	a = (int**) malloc (R * sizeof(int*));
	INPUT_MATRIX(a, R, C);

	// Function Call
	printf("\nSpiral Matrix:");
	spiralPrint(R, C, a);
	printf("\n");
	return 0;
}
