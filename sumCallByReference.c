#include <stdio.h>
#include <math.h>

int add(int *a, int *b)
{
	return *a + *b;
}

int max(int *a, int *b)
{
	return *a>*b?*a:*b;	
}

double factorial(double a)
{
	return 1/sqrt(5)*(pow((1+sqrt(5))/2,a)-pow((1-sqrt(5))/2,a));
}

int main()
{
	int x, y, sum, Max;
	double i, fact;
	printf("Enter the value of number1: ");
	scanf("%d",&x);
	
	printf("Enter the value of number2: ");
	scanf("%d",&y);
	      
	sum = add(&x,&y);
	printf("%d\n",sum);
	
	Max = max(&x,&y);
	printf("%d",Max);
	
	for(i=0;i<=x;i++)
	{
		fact = factorial(i);
		printf("\n%lf",fact);	
	}
}
