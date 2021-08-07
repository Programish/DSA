#include<stdio.h>
#include<math.h>
#include"General.h"

int getMedian(int*, int, int*, int);
//1st Method
/*int getMedian(int ar1[], int n, int ar2[], int m){  //Intermediate Solution because time complexity is O(m+n)
    	int i = 0; 
    	int j = 0; 
    	int count;
	int m1 = -1, m2 = -1;

    	if((m + n) % 2 == 1) {
        	for (count = 0; count <= (n + m)/2; count++) {
            		if(i != n && j != m){
            			m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
			}
            		else if(i < n){
            			m1 = ar1[i++];
			}
            		else{
            			m1 = ar2[j++];
			}
        	}
        	return m1;
    	}

    	else {
        	for (count = 0; count <= (n + m)/2; count++) {
			printf("prev for   i = %d    j = %d    m2 = %d\n",i,j,m2);
            		m2 = m1;
			printf("post for   i = %d    j = %d    m2 = %d\n",i,j,m2);
            		if(i != n && j != m){
            			m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
				printf("if   i = %d    j = %d    m1 = %d\n",i,j,m1);
			}
            		else if(i < n){
            			m1 = ar1[i++];
				printf("else if   i = %d    m1 = %d\n",i,m1);
			}
            		else{
           			m1 = ar2[j++];
				printf("else   j = %d    m1 = %d\n",j,m1);
			}
        	}
        	return (m1 + m2)/2;
    	}
}*/
//2nd Method
int MO2(int a, int b){ 
	return ( a + b ) / 2; 
}
 
int MO3(int a, int b, int c){
    	return a + b + c - MAX(a, MAX(b, c)) - MIN(a, MIN(b, c));
}
 
int MO4(int a, int b, int c, int d){
    	int Max = MAX( a, MAX( b, MAX( c, d ) ) );
    	int Min = MIN( a, MIN( b, MIN( c, d ) ) );
    	return ( a + b + c + d - Max - Min ) / 2;
}
 
int medianSingle(int arr[], int n){
   	if (n == 0)
      		return -1;
   	if (n%2 == 0)
        	return (arr[n/2] + arr[n/2-1])/2;
   	return arr[n/2];
}
 
int findMedianUtil( int A[], int N, int B[], int M ){ //This method considers that N is either small or equal to M
    	if (N == 0)
      		return medianSingle(B, M);
 
    	if (N == 1){
        	if (M == 1)
            		return MO2(A[0], B[0]);
 
        	if (M & 1)
            		return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
 
        	return MO3( B[M/2], B[M/2 - 1], A[0] );
    	}
 
    	else if (N == 2){
        	if (M == 2)
            		return MO4(A[0], A[1], B[0], B[1]);
 
        	if (M & 1)
            		return MO3 ( B[M/2], MAX(A[0], B[M/2 - 1]), MIN(A[1], B[M/2 + 1]));
 
        	return MO4 ( B[M/2], B[M/2 - 1], MAX( A[0], B[M/2 - 2] ), MIN( A[1], B[M/2 + 1] ));
    	}
 
    	int idxA = ( N - 1 ) / 2;
    	int idxB = ( M - 1 ) / 2;
 
    	if (A[idxA] <= B[idxB] )
      		return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );
 
    	return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}
 
int getMedian( int A[], int N, int B[], int M ){  //Best Solution because time complexity is O(min(log m, log n))
    	if (N > M)
       		return findMedianUtil( B, M, A, N );
 
    	return findMedianUtil( A, N, B, M );
}
//3rd Method
/*float getMedian(int ar1[], int n, int ar2[], int m){  //Worst Solution because time complexity is O(nlogn) and
       						        //space complexity is O(m+n)
	int ar3[n+m];
        int l =  n+m;
        // Merge two array into one array
        for(int k=0;k<n;k++)
        {
            ar3[k]=ar1[k];
        }
	printf("\n");
  	PRINT_ARRAY(ar3,n);         
        int a=0; 
        for(int k=n;k<m+n;k++)
        {
            ar3[k]=ar2[a++];
        }
	printf("\n");
 	PRINT_ARRAY(ar3,l); 
        // Sort the merged array
        SORT(ar3, 0, l-1);
	printf("\n");
	PRINT_ARRAY(ar3,l); 
     	if (l % 2 == 0){
       		int z = l / 2;
		printf("\nz = %d\n",z);
       		int e = ar3[z];
		printf("e = %d\n",e);
       		int q = ar3[z - 1];
		printf("q = %d\n",q);
       		int ans = (e + q) / 2;
		printf("ans = %d\n",ans);
       		return ans;
     	}
    
    	else{
       		int z = l / 2;
       		return ar3[z];
     	}
}*/

int main(){
	int l1,l2;
	printf("Enter size of 1st and 2nd array separated by a space:");
	scanf("%d %d", &l1, &l2);
	int a1[l1], a2[l2];
	printf("Array1:");
	INPUT_ARRAY(a1,l1);
	printf("Array2:");
        INPUT_ARRAY(a2,l2);
	int median = getMedian(a1,l1,a2,l2);
	printf("\nMedian = %d\n",median);

	return 0;
}
