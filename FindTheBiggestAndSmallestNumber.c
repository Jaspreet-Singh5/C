/* To find the biggest and smallest number */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare the variables to store the values of three numbers */
	int a, b, c;
	/* print a message */
	printf("Enter the value of a: ");
	/* take the value of a from the user */
	scanf("%d",&a);
	/* print a message */
	printf("Enter the value of b: ");
	/* take the value of b from the user */
	scanf("%d",&b);
	/* print a message */
	printf("Enter the value of c: ");
	/* take the value of c from the user */
	scanf("%d",&c);
	/* check whether a is bigger than b or not */
	if(a > b)
	{
		/* check whether a is bigger than c or not */
		if(a > c)
		/* print the result */
		printf("The biggest number is a \n");
		
		else
		printf("The biggest number is c \n");
	}
	
	else
	{
		/* check whether b is bigger than c or not */
		if(b > c)
		/* print the result */
		printf("The biggest number is b \n");
		
		else
		printf("The biggest number is c \n");
		
	}
	
	/* check whether a is smaller than b or not */
	if(a < b)
	{
		/* check whether a is smaller than c or not */
		if(a < c)
		/* print the result */
		printf("The smallest number is a \n");
		
		else
		printf("The smallest number is c \n");
	}
	
	else
	{
		/* check whether b is smaller than c or not */
		if(b < c)
		/* print the result */
		printf("The smallest number is b \n");
		
		else
		printf("The smallest number is c \n");
		
	}
}
/* Main function ends */

