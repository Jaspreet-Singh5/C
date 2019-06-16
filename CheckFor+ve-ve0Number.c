/* To find whether a given number is positive, negative or zero */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/*Main function starts*/
main()
{
	/* declare a variable to store the value of the given number */
	int n;
	/* print a message */
	printf("Enter  a number: ");
	/* store the value of character in a variable */
	scanf("%d",&n);
	/* check whether a given character is a vowel or consonant */
	if(n > 0)
		/* print the  value of the number */
		printf("The given number:%d is a positive number",n);
	else if(n < 0)
		/* print the  value of the number */
		printf("The given number:%d is a negative number",n);
	else 
		/* print the  value of the number */
		printf("The given number:%d is zero",n);
}
/* Main function ends */
	
