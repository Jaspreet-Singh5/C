/* To calculate the result of y raise to the power of n */
/* Coded by Jaspreet Singh */
#include<stdio.h>
/* Main function starts */
main()
{
	/* declare variables to store the number, raise to the power, a counter and result  */
	int n, x, i = 1, result;
	/* print a message */
	printf("Enter the number: ");
	/* store the value in a variable */
	scanf("%d",&n);
	/* print a message */
	printf("Enter the value for raise to the power: ");
	/* store the value in a variable */
	scanf("%d",&x);
	/* initialize the value of result */
	result = n;
	/* start while loop for a given range */
	while(i < x)
	{
		/* calculate the result */
		result *= n;
		/* increase the value of counter */
		i++;
	}
	/* print the result */
	printf("%d",result);
}
/* Main function ends */
