/* To find area of a circle */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare the variables to store the values of radius and area of a circle */
	float r, area;
	/* print a message */
	printf("Enter the value of radius of a circle: ");
	/* take the value of radius of a circle from the user */
	scanf("%f",&r);
	/* calculate area of a circle */
	area = 3.14 * r * r;
	/* print the value of area of the circle */
	printf("The area of the circle is: %.2f", area);
}
/* Main function ends */

