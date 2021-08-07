#include<stdio.h>
int main(void){
	int l1,l2,temp,flag = 0,count = 0;
	printf("Enter size of 1st and 2nd array separated by space:");
	scanf("%d %d",&l1,&l2);
	int a1[l1],a2[l2];
	printf("Enter elements in 1st array:\n");
	for(int i = 0;i < l1;i++)
		scanf("%d",&a1[i]);
	printf("Enter elements in 2nd array:\n");
        for(int i = 0;i < l2;i++)
        	scanf("%d",&a2[i]);
	//Calculation of union
	/* Take a element from a1[] and put
	 * that element in a[] only when there is no
	 * copy of that element in a[]
	 */   
	int a[l1+l2];
	for(int i = 0;i < l1;i++){
		for(int j = 0;j < count;j++){
			if(a[j] == a1[i]){
				printf("i=%d j=%d\n",i,j);
				flag = 1;
			}
		}
		if(flag == 0){
			printf("%d to be entered in %d position\n",a1[i],count);
			a[count++] = a1[i];
		}
		flag = 0;
	}
	printf("1st array done!!\n");
	/* Take a element from a2[] and put
	 * that element in a[] only when there is no
	 * copy of that element in a[]
	 */   
	flag = 0;
	for(int i = 0;i < l2;i++){
        	for(int j = 0;j < i + count;j++){
        		if(a[j] == a2[i]){
				printf("i=%d j=%d\n",i,j);
        			flag = 1;
        		}
        	}
        	if(flag == 0){
			printf("%d to be entered in %d position\n",a2[i],count);
        		a[count++] = a2[i];
        	}
		flag  = 0;
        }
	printf("Union of entered arrays: ");
	for(int i = 0;i < count;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	//Calculation of intersection
	/* Take a element from a1[] 
	 * check that the same element should
	 * also be present in a2[] and should
	 * not present in a[]
	 * only in this case element should be
	 * entered in a[]
	 */
	flag = 0;
	count = 0;
        for(int i = 0;i < l1;i++){
        	for(int j = 0;j < l2;j++){
			if(a2[j] == a1[i]){
				flag = 1;
				printf("i=%d j=%d\n",i,j);
				for(int k = 0;k < count;k++){
        				if(a1[i] == a[k]){
        					flag = 0;
        				}
				}printf("outside k loop\n");
			}
        	}printf("outside j loop\n");
        	if(flag == 1){
			printf("%d to be entered in %d position\n",a1[i],count);
        		a[count++] = a1[i];
        	}
        	flag = 0;
        }printf("outside i loop\n");
        printf("Intersection of entered arrays: ");
        for(int i = 0;i < count;i++){
        	printf("%d ",a[i]);
        }
        printf("\n");

	return 0;
}
