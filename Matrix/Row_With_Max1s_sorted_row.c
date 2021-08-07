#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "General.h"

int first(int*, int, int);
int rowWithMax1s(int** , int, int);

/*int rowWithMax1s(int** mat, int R, int C)// Best Approach because time complexity is O(m+n)
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
}*/

int main() {
	
	int R, C;                                                              	
        int** a;
        printf("Enter no. of rows, columns separated by a space:");
        scanf("%d %d", &R, &C);
                                                                                
        a = (int**) malloc (R * sizeof(int*));
	printf("\nNote:- Enter elements only in 0 or 1, and elements in each array should be in increasing order\n\n");
        INPUT_MATRIX(a, R, C);
        PRINT_MATRIX(a, R, C);

	int max = rowWithMax1s(a, R, C);

	printf("Row with max. 1s is: %d\n", max+1);

	return 0;
}	

// Function to find the index of first index
// of 1 in a boolean array arr[]
int first(int* arr, int low, int high){
	if(high >= low){
    		// Get the middle index
    		int mid = low + (high - low)/2;
 
    		// Check if the element at middle index is first 1
    		if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
    			return mid;
 
    		// If the element is 0, recur for right side
    		else if (arr[mid] == 0)
    			return first(arr, (mid + 1), high);
     
    		// If element is not first 1, recur for left side
    		else
    			return first(arr, low, (mid -1));
	}
	return -1;
}

int rowWithMax1s(int** mat, int R, int C){  //Worst Solution because time complexity is O(mlogn)
    // Initialize max values
    int max_row_index = 0, max = -1;
 
    // Traverse for each row and count number of 1s
    // by finding the index of first 1
    int i, index;
    for (i = 0; i < R; i++){
    	index = first (mat[i], 0, C-1);
    	if (index != -1 && C-index > max){
        	max = C - index;
        	max_row_index = i;
    	}
    }
 
    return max_row_index;
}
