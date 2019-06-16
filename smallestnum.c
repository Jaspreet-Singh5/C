// program to demonstrate a program using C function to find the smallest element in an array
#include <stdio.h>

int smallestnum=0;

int smallest(int num)
{
	if(num<smallestnum)
		smallestnum=num;
}

main()
{
	int n[10],len,i=0;
	
	printf("Enter no. of elements of the array: ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		printf("Enter no.%d element of the array: ",i+1);
		scanf("%d",&n[i]);
		
		if(i==0)
			smallestnum = n[i];
	
		smallest(n[i]);
	}
	printf("The smallest num in the array is:%d",smallestnum);
}
