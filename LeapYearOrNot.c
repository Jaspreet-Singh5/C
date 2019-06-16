/* To check whether Leap year or not */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/* Main function strats */
main()
{
	/* declare a variable to store the value of the year */
	int year;
	/* print a message */
	printf("Check whether Leap year or not \n \n");
	/* print a message */
	printf("Enter any year: ");
	/* store the value in a variable */
	scanf("%d",&year);
	/* check if leap year or not */
	if(year % 400 == 0)
	{	/* print a message */
		printf("%d is a leap year",year);
	}
	else if(year % 100 == 0)
	{	/* print a message */
		printf("%d is not a leap year",year);
	}
	/* if(year % 4 == 0) */
	else
	{	/* print a message */
		printf("%d is a leap year",year);
	}
}
/* main function ends */
/* Main function ends */
