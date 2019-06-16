// Program to print number of days in a month using switch case statement 
// Coded by Jaspreet Singh 
// for console input and output 
#include<windows.h>
// for standard input and output
#include<stdio.h>
// for standard input and output
#include<conio.h>
// for working with strings
#include <string.h>
// main function starts
main()
{
	// declare variables to store the given month, given year, counter, flag; 
	int n, yr, i;
	char flag = 'Y';
	char month[12][20];
	strcpy(month[0],"January");
	strcpy(month[1], "February");
	strcpy(month[2], "March");
	strcpy(month[3], "April");
	strcpy(month[4], "May");
	strcpy(month[5], "June");
	strcpy(month[6], "July");
	strcpy(month[7], "August");
	strcpy(month[8], "September");
	strcpy(month[9], "October");
	strcpy(month[10], "November");
	strcpy(month[11], "December");
	// loop
	while(flag == 'Y' || flag == 'y')
	{
		// clear the screen
		system("cls");
		// print a message
		printf("\nProgram to print number of days in a month \n\n");
		//print a message
		printf("Enter the number of the month: ");
		//store the value in a variable
		scanf("%d",&n);
		// check for the various cases
		switch(n)
		{
			
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
					// clear the screen
					system("cls");
					printf("The number of days in  the %s is 31",month[n - 1]);
					break;
			case 2:
					// clear the screen
					system("cls");
					//print a message
					printf("Enter the year: ");
					//store the value in a variable
					scanf("%d",&yr);
					// check for the leap year or not
					if((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
					{
						// clear the screen
						system("cls");
						//print a message
						printf("This is a leap year\n");
						//print a message
						printf("The number of days in  the %s is 29",month[n - 1]);
					}
					else
					{
						// clear the screen
						system("cls");
						//print a message
						printf("The number of days in  the %s is 28",month[n - 1]);
						
					}
					break;
			case 4:
			case 6:
			case 9:
			case 11:
					// clear the screen
					system("cls");
					printf("The number of days in the %s is 30",month[n - 1]);
					break;
			default: 
					//print a mesasage
					printf("Wrong input");
					break;	
		}	
		fflush(stdin);
		//print a message
		printf("\n\nDo you want to continue(type Y/y): ");
		//store the value in a variable
		scanf("%c",&flag);
	}
	// clear the screen
	system("cls");
	//print a mesasage
	printf("Program has been quit");
}
/*  main function ends */
