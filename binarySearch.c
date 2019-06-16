#include <Stdio.h>

int binarySearch(int [],int,int);

main(){
	int A[]={2,5,7,34,235,543,754,1242,5325,6434};
	int x,index=0;
	printf("Enter the number you want to find: ");
	scanf("%d",&x);
	index=binarySearch(A,10,x);
	if(index!=-1)
		printf("Element %d found at index %d",x,index);
	else
		printf("Element %d not found",x);	
}

int binarySearch(int A[],int n,int x){
	int low=0, high=n-1, mid;
	while(low<=high){
		mid=low+(high-low)/2; //to prevent low+high overflow
		if(A[mid]==x)
			return mid;
		else if(x<A[mid])
			high=mid-1;
		else
			low=mid+1;	
	}	
	return -1;
}


