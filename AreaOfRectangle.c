/* To find area of a rectangle */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/* Main function starts */
main()
{
	/* declare the variables to store the values of length, breadth and area of a rectangle */
	float l, b, area;
	/* print a message */
	printf("Enter the value of length of a rectangle: ");
	/* take the value of length of a rectangle from the user */
	scanf("%f",&l);
	/* print a message */
	printf("Enter the value of breadth of a rectangle: ");
	/* take the value of breadth of a rectangle from the user */
	scanf("%f",&b);
	/* calculate area of a rectangle */
	area = l * b;
	/* print the value of area of the rectangle */
	printf("The area of the rectangle is: %.2f", area);
}
/* Main function ends */

