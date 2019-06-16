/* To check whether a given character is an alphabet or not */
/* Coded by Jaspreet Singh */
/* directory for standard input and output */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare a variable to store the value of the character input by the user */ 
	char a;
	/* print a message */
	printf("Check whether a given character is an alphabet or not \n \n");
	/* print a message */
	printf("Enter any character: ");
	/* store the value of the character input by the user in a variable */
	scanf("%c",&a);
	/* check whether it is a character or not */
	if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		/* print a message */
		printf("%c is an alphabet",a);
	else
		/* print a message */
		printf("%c is not an alphabet",a);
}
/* main function ends */
