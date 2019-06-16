/* To find area of a triangle */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare the variables to store the values of height, base and area of a triangle */
	float b, h, area;
	/* print a message */
	printf("Enter the value of height of a triangle: ");
	/* take the value of height of a triangle from the user */
	scanf("%f",&h);
	/* print a message */
	printf("Enter the value of base of a triangle: ");
	/* take the value of height of a circle from the user */
	scanf("%f",&b);
	/* calculate area of a triangle */
	area = 0.5 * b * h;
	/* print the value of area of the circle */
	printf("The area of the triangle is: %.2f", area);
}
/* Main function ends */

