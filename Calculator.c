/* Simple Calculator */
/* Coded by Jaspreet Singh */
/* directory for standard input and output */
#include <stdio.h>
/* main function starts */
main()
{
	/*declare two variables to store the value of two numbers */
	float n1, n2, result;
	char mathopr;
	/* print a message */
	printf("Simple Calculator \n \n");
	/* print a message */
	printf("Which arithmetic operation do you want to perform? ");
	/* store the value of the number in another variable */
	scanf("%c",&mathopr);
	/* print a message */
	printf("Enter first number: ");
	/* store the value of the number in a variable */
	scanf("%f",&n1);
	/* print a message */
	printf("Enter second number: ");
	/* store the value of the number in another variable */
	scanf("%f",&n2);
	
	/* different cases */
	switch(mathopr)
	{
		/* Addition */
		case '+' : /* calculate and store the result */ 
				   result = n1 + n2;
				   /* print a message */
				   printf("The sum of %f and %f gives %.2f",n1,n2,result);
				   break;
		
		/* Subtraction */		   
		case '-' : /* calculate and store the result */
				   result = n1 - n2;
				   /* print a message */
				   printf("The subtraction of %f from %f gives %.2f",n2,n1,result);
				   break;
		
		/* Multiplication */		   
		case '*' : /* calculate and store the result */
				   result = n1 * n2;
				   /* print a message */
				   printf("The multiplication of %f and %f gives %.2f",n1,n2,result);
				   break;
		
		/* Division */		   
		case '/' : /* calculate and store the result */
				   result = n1 / n2;
				   printf("The division of %f by %f is %.2f",n1,n2,result);
				   break;
		
		default :  printf("The input is wrong");
				   break;
	}	
}
