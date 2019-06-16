// program to find the prime number(s) between a given interval
// directory for standard input and output
#include <stdio.h>
//directories for console input and output
#include <conio.h>
#include <windows.h>
// for string handling
#include <string.h>
// for string manipulation
#include <ctype.h>
// for math functions
#include <math.h>
// main function starts
main()
{
	// declare a variable to store the desired integer upto which the series of prime numbers will be printed
	int N1, N2, i, j, prime, count, opt;
	char flag[100], *pos;
	// loop
	do
	{
		system("cls");
		// print a message
		printf("Program to find the prime number(s) between a given interval\n");
		printf("------------------------------------------------------------\n\n");
		// print a message
		printf("1. Definition\n");
		// print a message
		printf("2. Find\n");
		// print a message
		printf("Selected option: ");
		scanf("%d", &opt);
		// switch
		switch(opt)
		{
			case 1:
					system("cls");
					// PRINT a message
					printf("Prime number\n");
					printf("------------\n\n");
					printf("A prime number is a whole number greater than 1, which is only divisible by 1 and itself. \n");		 
					printf("First few prime numbers are : 2 3 5 7 11 13 17 19 23");		 
					getch();
			break;
			case 2: 
					N1 = N2 = i = j = count = 0;
					system("cls");
					// print a message
					printf("Find the prime number(s) between a given interval\n");
					printf("-------------------------------------------------\n\n");
					// print a message
					printf("Enter the first number of the interval: ");
					// take the first given whole number as an input
					scanf("%d", &N1);
					// print a message
					printf("Enter the last number of the interval:  ");
					// take the second given whole number as an input
					scanf("%d", &N2);
					// prime number is a whole number greater than 1, which is only divisible by 1 and itself 
					// iterate through each and every whole number between N1 and N2
					for(i = N1; i <= N2 && !(N1 < 0) && !(N2 < 0) && !(N1 > N2) && !(N1 == N2); i++)
					{
						// set the value for prime as true
						prime = 1;
						if(i == 1 || i == 0)
							continue;
						// iterate through every whole number greater than one and smaller than the number being checked
						for(j = 2; j <= sqrt(i); j++)
						{
							// check if the number being checked is divisible by any whole number greater than one and smaller than it
							if(i % j == 0)
							{
								prime = 0;
								break;
							}
						}
						// check for the status of the variable prime
						if(prime)
						{
							if(count == 0)
							{
								system("cls");
								// print a message
								printf("The following are the prime number(s) between %d and %d: \n", N1, N2);
							}
							// print a message
							printf("%d ", i);
							count++;
						}
						if(i == N2 && count != 0)
							getch();
					}
					// validation
					//for zero prime numbers
					if(count == 0 && !(N1 < 0 || N2 < 0) && !(N1 > N2) && !(N1 == N2))
					{
						system("cls");
						// print a message
						printf("There is no prime number between %d and %d\n", N1, N2);
						getch();
					}
					//for zero number in the interval
					if(N1 == N2)
					{
						system("cls");
						// print a message
						printf("There is no number between %d and %d\n", N1, N2);
						getch();
					}	
					// for negative numbers
					if(N1 < 0 || N2 < 0)
					{
						system("cls");
						printf("Input can not be negative");
						getch();
					}
					// for out of constraint interval
					if(N1 > N2)
					{
						system("cls");
						printf("The first number of the interval should be less than the last number of the interval");
						getch();
					}
			break;
			default: 
					system("cls");
					// print a message
					printf("Wrong input");
					getch();
			break;
		}
		system("cls");
		//print a message
		printf("Do you want to continue? ");
		fflush(stdin);
		gets(flag);
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	// print a message
	printf("You quit the program");
	getch();
}
