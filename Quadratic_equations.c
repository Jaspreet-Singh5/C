// Program to find the roots of a quadratic equation
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

double grtrthn1(double b, double d, double a)
{
	double x1, x2;
	
	x1 = (-b + sqrt(d)) / (2*a);
	x2 = (-b - sqrt(d)) / (2*a);
	
	system("cls");
	printf("----------------------------------\n");
	printf(" The roots are real and distinct.\n");
	printf(" Root1: %.2lf\n", x1);	 
	printf(" Root2: %.2lf\n", x2);
	printf("----------------------------------\n");
	getch();
}

double lwrthn1(double b, double d, double a)
{
	double realp, imagp;
	
	realp = -b / (2.0 * a) ;
    imagp = sqrt(abs(d)) / (2.0 * a);
            
	system("cls");
	printf("---------------------------------------\n");
	printf(" The roots are imaginary and distinct.\n");
	printf(" Root1 = %.2lf  +i %.2lf\n", realp, imagp);
    printf(" Root2 = %.2lf  -i %.2lf\n", realp, imagp);
	printf("---------------------------------------\n");
	getch();
}

double equalto1(double b, double d, double a)
{
	double x;
	
	x = -b / (2*a);
	
	system("cls");
	printf("-------------------------------\n");
	printf(" The roots are real and equal.\n");
	printf(" Root1: %.2lf\n", x);	 
	printf(" Root2: %.2lf\n", x);
	printf("-------------------------------\n");
	getch();
}
double main()
{
	double a, b, c, d;
	char flag[20], *pos;
	int opt;
		
		do
	{
		system("cls");
		// print a message
	    printf("---------------------------------------------------\n");
		printf(" Program to find the roots of a quadratic equation \n");
		printf("---------------------------------------------------\n\n\n");
		
		printf("----------------------------------------------\n");
		// print a message
	    printf("Choose one of the following options: \n");
	    // print a message
	    printf("1. Find the roots of a quadratic equation\n");
	    // print a message
	    printf("2. Defintition\n");
		// print a message
	    printf("Selected  option is: ");
		// store the number in a variable
		scanf("%d",&opt);
	 	printf("----------------------------------------------\n");
	 	getch();
		switch(opt)
		{
			case 1:
					a = b = c = 0;
					system("cls");
					printf("---------------------------------------------------\n");
					printf(" Program to find the roots of a quadratic equation \n");
					printf("---------------------------------------------------\n\n\n");
					printf("---------------------------\n");
					printf(" Enter the value of a: ");
					scanf("%lf",&a);
					printf("---------------------------\n\n");
					printf("---------------------------\n");
					printf(" Enter the value of b: ");
					scanf("%lf",&b);
					printf("---------------------------\n\n");
					printf("---------------------------\n");
					printf(" Enter the value of c: ");
					scanf("%lf",&c);
					printf("---------------------------\n");
			
					d = pow(b,2) - 4 * a * c;
					
					if(d > 0 && a != 0)
					{
						grtrthn1(b, d, a);
					}
					
					else if(d < 0 && a != 0)
					{
						lwrthn1(b, d, a);
					}
					
					else if(d == 0 && a != 0)
					{
						equalto1(b, d, a);
					}
					
					else
					{
						system("cls");
						printf("---------------------------------------------------\n");
						printf(" The value of a should be greater than or less than 0\n");
						printf("---------------------------------------------------\n");
						getch();
					}
			break;
			case 2 :
					system("cls");
					// print a message
					printf("---------------------\n");
				    printf(" Quadratic equations\n");
					printf("---------------------\n\n\n");
					    
					printf("----------------------------------------------------------------------------------------------------------\n");
					printf("In algebra, a quadratic equation (from the Latin quadratus for 'square') is any equation having the form\n"); 
					printf("ax^2+bx+c=0\n");
					printf("where x represents an unknown, and a, b, and c represent known numbers such that a is not equal to 0.\n");
	
					printf("If a = 0, then the equation is linear, not quadratic. The numbers a, b, and c are the coefficients of the \n");
					printf("equation, and may be distinguished by calling them, respectively, the quadratic coefficient, the linear \n");
					printf("coefficient and the constant or free term.\n");
	
					printf("----------------------------------------------------------------------------------------------------------\n");
					getch();
					break;
			default: printf("Wrong input");
					 getch();
		}
		system("cls");
		fflush(stdin);
		printf("------------------------------------\n");
		printf(" Do you want to continue? ");
		gets(flag);
		printf("------------------------------------\n");
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
}

