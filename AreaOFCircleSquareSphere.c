/* Write a menu-driven program using switch cae statement to calculate the : Area of circle,
   Area of square or Area of sphere */
/* Jaspreet Singh */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare four variables to store option, number 1, number 2 and the result */
	int opt; 
	double a, result;
	/* print a message */
	printf("Choose one of the following options by typing the correspondig number:- \n");
	/* print all the options */
	printf("1. Area of circle \n");
	printf("2. Area of square \n");
	printf("3. Area of sphere \n");
	/* store the value of the selected option in a variable */
	scanf("%d",&opt);
 	/* check for the selected option and execute the corresponding set of starements */
	if(opt == 1)
	{
		/* print a message */
		printf("Enter the radius of a circle: ");
		/* store the value in a variable */
		scanf("%lf",&a);
		/* calculate and store the area of circle in another variable */
		result = 3.14 * a * a;
		/* print the result */
		printf("The area of a circle of radius: %.2lf is: %.2lf",a,result); 
	}
	
	else if(opt == 2)
	{
		/* print a message */
		printf("Enter the side of a sqaure: ");
		/* store the value in a variable */
		scanf("%lf",&a);
		/* calculate and store the area of square in another variable */
		result = a * a;
		/* print the result */
		printf("The area of a sqaure of side: %lf is: %.2lf",a,result); 
	}
	
	else
	{
		/* print a message */
		printf("Enter the radius of a sphere: ");
		/* store the value in a variable */
		scanf("%lf",&a);
		/* calculate and store the area of circle in another variable */
		result = 4 * 3.14 * a * a;
		/* print the result */
		printf("The area of a sphere of radius: %lf is: %.2lf",a,result); 
	}			
}
/* Main function ends */
