#include <stdio.h>
#include <math.h>

double grtrthn1(double b, double d)
{
	double x1, x2;
	
	x1 = (-b + sqrt(d)) / 2;
	x2 = (-b - sqrt(d)) / 2;
	
	system("cls");
	printf("x1: %d\n", x1);	 
	printf("x2: %d\n", x2);
	getch();
}

int main()
{
	double a, b, c, d;
	
	printf("Enter the value of a: ");
	scanf("%lf",&a);
	
	printf("Enter the value of b: ");
	scanf("%lf",&b);
	
	printf("Enter the value of a: ");
	scanf("%lf",&c);
	
	d = pow(b,2) - 4 * a * c;
	
	if(d > 1)
	{
		grtrthn1(b, d);
	}
}

