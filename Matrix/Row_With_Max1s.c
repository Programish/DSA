#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "General.h"

int rowWithMax1s(int** , int, int);
/*
int rowWithMax1s(int** mat, int R, int C)
{
    int j,max_row_index = 0;
    j = C - 1;

    for (int i = 0; i < R; i++) {
      bool flag=false; 
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1;
          flag=true ;
          }
      if(flag){
            max_row_index = i; 
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}
*/
int main() {
	
	int R, C;                                                              	
        int** a;
        printf("Enter no. of rows, columns separated by a space:");
        scanf("%d %d", &R, &C);
                                                                                
        a = (int**) malloc (R * sizeof(int*));
	printf("\nNote:- Enter elements only in 0 or 1 \n\n");
        INPUT_MATRIX(a, R, C);
        PRINT_MATRIX(a, R, C);

	int max = rowWithMax1s(a, R, C);

	printf("Row with max. 1s is: %d\n", max+1);

	return 0;
}	

int rowWithMax1s(int** mat, int R, int C){   //Worst Solution because Time Complexity is O(R*C)

	int max_count = 0, temp_count, max_row = 0;

	for(int i = 0;i < R;i++){
		temp_count = 0;
		for(int j = 0;j < C;j++){
			if(mat[i][j])
				temp_count++;
			if(max_count < temp_count){
				max_count = temp_count;
				max_row = i;
			}
		}
	}

	return max_row;
}
