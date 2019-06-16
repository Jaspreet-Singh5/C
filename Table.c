/* To print table of a given number */
/* Coded by Jaspreet Singh */
#include<stdio.h>
/* Main function starts */
main()
{
	/* declare variables to store the number, counter and  result */
	int n, result, i = 1;
	/* print a message */
	printf("Enter any number: ");
	/* store the value in a variable */
	scanf("%d",&n);
	/* start while loop for a given range */
	while(i <= 10)
	{
		/* calculate the result */
		result = n * i;
		/* print the result */
		printf("%d \n",result);
		/* increase the value of counter by one */
		i++;
	}
}
/* Main function ends */
