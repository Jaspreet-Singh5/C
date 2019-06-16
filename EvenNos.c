/* To print all the even numbers within a given range */
/* Coded by Jaspreet Singh */
#include<stdio.h>
/* Main function starts */
main()
{
	/* declare variables to store the lower limit of the range and a counter for while loop */
	int lolmt, i = 1;
	/* print a message */
	printf("Enter the given range: 1-");
	/* store the value in a variable */
	scanf("%d",&lolmt);
	/* start while loop for a given range */
	while(i <= lolmt)
	{
		/* check if the given number is even or not */
		if(i % 2 == 0)
		{	
			/* print a message */
			printf("%d \n",i);
		}
		/* increase the value of counter by one */
		i++;
	}
}
/* Main function ends */
