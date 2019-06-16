// program in C to check whether a given number is even or odd
#include <stdio.h>

int check(int num)
{
	if(num%2==0)
		printf("Even no.");
	else
		printf("Odd no.");
	
}

int main()
{
	int n;
	printf("Enter any number: ");
	scanf("%d",&n);
	
	check(n);
}
