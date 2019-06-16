#include <stdio.h>

int fibonacci(int n)
{
	if(n == 0 || n == 1)
	return 1;
	
	else
	return fibonacci(n-1) + fibonacci(n-2); 
}

int sum(int n)
{
	if(n==1)
		return 1;
	else
		return n + sum(n-1);	
}

int count(int n)
{
	if(n/10 == 0)
		return 1;
	else 
		return 1 + count(n/10);
}

main()
{
	int num, i;
	num = 23;
	
	for(i=0;i<num;i++)
	{
		printf("%d\n",fibonacci(i));
	}
	
	printf("\n%d\n",count(num));
	
	printf("\n%d\n",sum(num));
}
