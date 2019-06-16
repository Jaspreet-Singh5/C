/* To find whether a given character is a vowel or consonant */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/*Main function starts*/
main()
{
	/* declare a variable to store the character */
	char c;
	/* print a message */
	printf("Type  a character: ");
	/* store the value of character in a variable */
	scanf("%c",&c);
	/* check whether a given character is a vowel or consonant */
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		/* print the  value of the character */
		printf("The given character: %c is a vowel",c);
	else
		/* print the  value of the character */
		printf("The given character:%c is a consonant",c);
}
