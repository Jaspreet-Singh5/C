/* To celsius into celsius into fahrenheit and vice-versa */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/*Main function starts*/
main()
{
	/* declare a variable to store the value of given type of temperature and result */
	float t, result;
	/* declare a variable to store the given type of temperature */
	char type;
	/* print a message */
	printf("Enter the value of the temperature: ");
	/* store the value of the temperature in a variable */
	scanf("%f ",&t);
	/* store the value of the type of temperature in a variable */
	scanf("%c",&type);
	/* check whether a given character is a vowel or consonant */
	if(type == 'c' || type == 'C')
	{
		/* convert the given value into degree fahrenheit */
		result = t  * 1.8 + 32;
		/* print the value of the result */
		printf("The value of the temperature after conversion is:%f F",result);	
	}
	else
	{
		/* convert the given value into degree celsius */
		result = (t - 32) / 1.8;
		/* print the value of the result */
		printf("The value of the temperature after conversion is:%f C",result);	
	}
}
