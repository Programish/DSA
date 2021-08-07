#include<stdlib.h>

void SWAP(int *n1,int *n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int MAX(int n1,int n2){
	return (n1 > n2)?n1:n2;
}

int MIN(int n1,int n2){
	return (n1 < n2)?n1:n2;
}

void PRINT_ARRAY(int a[],int n){
	for(int i = 0;i < n;i++)
		printf("%d\t ",a[i]);
	printf("\n");
}

void INPUT_ARRAY(int a[],int n){
	printf("Enter %d elements in array:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
}

int MAX_ARRAY(int a[],int n){
	int max = a[0];

	for(int i = 0;i < n;i++)
		if(a[i] > max)
			max = a[i];
	return max;
}

int MIN_ARRAY(int a[],int n){
 	int min = a[0];
 
 	for(int i = 0;i < n;i++)
 		if(a[i] < min)
 			min = a[i];
 	return min;
 }

// Sorting algorithm starts (its Quick Sort, because its best algorithm for sorting)
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            SWAP(&arr[i], &arr[j]);
        }
    }
    SWAP(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void SORT(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        SORT(arr, low, pi - 1);
        SORT(arr, pi + 1, high);
    }
}
//Sorting algorithm ends


void INPUT_MATRIX(int** a, int r, int c){

	for(int i = 0; i < r; i++)
		a[i] = (int*) malloc (c * sizeof(int));
	printf("Enter %d elements in matrix:\n", r*c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d",(*(a+i)+j));
	
}

void PRINT_MATRIX(int** a, int r, int c) {

	printf("\nMatrix---------\n");
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			printf("%d  ",*(*(a+i)+j));
		printf("\n");
	}
	printf("\n");
	
}

void SORT_MATRIX(int** a, int r, int c) {

	int size = r * c;

    	for (int i = 0; i < size; i++)
        	for (int j = 0; j < size - 1; j++)
            		if (a[j / c][j % c] > a[(j + 1) / c][(j + 1) % c]) {
                		int temp = a[j / c][j % c];
                		a[j / c][j % c] = a[(j + 1) / c][(j + 1) % c];
                		a[(j + 1) / c][(j + 1) % c] = temp;
            		}
}
