#include <stdio.h>

int binarySearch(int [],int,int,int);

main(){
	int x,index;
	int A[]={2,4,6,6,7,23,64,74,74,534};
	printf("Enter the number that you want to search: ");
	scanf("%d",&x);
	
	index=binarySearch(A,0,9,x);
	
	if(index!=-1)
		printf("Element %d found at index %d",x,index);
	else
		printf("Element %d not found",x);
}

int binarySearch(int A[],int low,int high,int x){
	int mid;
	if(low>high)
		return -1;
	mid=low+(high-low)/2;
	if(x==A[mid])
		return mid;
	else if(x<A[mid])
		return binarySearch(A,0,mid-1,x);
	else
		return binarySearch(A,mid+1,high,x);
}
