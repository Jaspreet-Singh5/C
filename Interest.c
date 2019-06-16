// Program to calculate the simple interest and compound interest 
// Coded by Jaspreet Singh 
// for console input and output 
#include<windows.h>
// for standard input and output
#include<stdio.h>
// for standard input and output
#include<conio.h>
// for y raise to the power of x
#include <math.h> 
// main function starts
main()
{
	/* declare variables to store the principal, time period involved in years, simple interest, compound interest, option selected, raise to the power of x 
		no. of times the interest is compounded in a year, no. of times the interest is compounded in a year, counter */
	float principal, interest, si, ci, x, p, difference1, difference;
	int optf, optc, time, times, n, i;
	char flag = 'Y';
	// loop
	while(flag == 'Y' || flag == 'y')
	{
		firstmenu:
		system("cls");
		// print a message
		printf("Program to calculate the simple interest and compound interest \n\n");
		// print a message
		printf("Choose the type of interest that you want to calculate: \n");
		//print a message
		printf("1. Simple interest \n");
		//print a message
		printf("2. Compound interest \n");
		//print a message
		printf("Selected option: ");
		//store the value in a variable
		scanf("%d",&optf);
		//clear the screen
		system("cls");
		// check for the type of interest selected
		if(optf == 1)
		{
			//print a message
			printf("Enter the principal amount: ");
			//store the value in a variable
			scanf("%f",&principal);
			//print a message
			printf("Enter the rate of interest per year: ");
			//store the value in a variable
			scanf("%f",&interest);
			//print a message
			printf("Enter the time involved in years: ");
			//store the value in a variable
			scanf("%d",&time);
			// calculate the simple interest
			si = (principal * interest * time) / 100;
			// clear the screen
			system("cls");
			// print the result
			printf("The simple interest is %.2f",si);
		}
		else if(optf == 2)
		{
			// print a message
			printf("Choose one following options: \n");
			//print a message
			printf("1. Yearly compounding \n");
			//print a message
			printf("2. Quarterly compounding \n");
			//print a message
			printf("3. Difference \n");
			//print a message
			printf("4. Customized compounding \n");
			//print a message
			printf("5. go back to the previous menu \n");
			//print a message
			printf("Selected option: ");
			//store the value in a variable
			scanf("%d",&optc);
			// goto statement
			if(optc == 5)
				continue;
			// check for the selected option
			//clear the screen
			system("cls");
			//print a message
			printf("Enter the principal amount: ");
			//store the value in a variable
			scanf("%f",&principal);
			//print a message
			printf("Enter the rate of interest per year: ");
			//store the value in a variable
			scanf("%f",&interest);
			//print a message
			printf("Enter the time involved in years: ");
			//store the value in a variable
			scanf("%d",&time);
			//check for different cases
			switch(optc)
			{
				// yaearly compounding
				case 1 :	// calculate and store 1 + interest / (100 * 1) in a variable
							x = 1 + interest / (100 * 1);
							// claculate and store the power
							p = 1 * time;
							// calculate the compound interest
							ci = (principal * pow(x,p)) - principal;
							// clear the screen
							system("cls");
							// print the result
							printf("The yearly compound interest is %.2f",ci);
							break;
				// quarterly compounding
				case 2 :	// calculate and store 1 + interest / (100 * 4) in a variable
							x = 1 + interest / (100 * 4);
							// claculate and store the power
							p = 4 * time;
							// calculate the compound interest
							ci = (principal * pow(x,p)) - principal;
							// clear the screen
							system("cls");
							// print the result
							printf("The quarterly compound interest is %.2f",ci);
							break;
				// difference bw the value of yearly compound interest and quarterly compound interest
 				case 3 :	// calculate and store 1 + interest / (100 * 4) in a variable
							x = 1 + interest / (100 * 4);
							// claculate and store the power
							p = 4 * time;
							// calculate the compound interest
							ci = (principal * pow(x,p)) - principal;
							// assign the value to difference1
							difference1 = ci;
							// calculate and store 1 + interest / (100 * 1) in a variable
							x = 1 + interest / (100 * 1);
							// claculate and store the power
							p = 1 * time;
							// calculate the compound interest
							ci = (principal * pow(x,p)) - principal;
							// calculate the result
							difference = difference1 - ci;
							// clear the screen
							system("cls");
							// print the result
							printf("The differnce is %.2f",difference);
							break;
				// customized compounding
				case 4 :	// print a message
							printf("Enter the number of times the interest is compounded per year: ");
							scanf("%d",&times);
							// calculate and store 1 + interest / (100 * 4) in a variable
							x = 1 + interest / (100 * times);
							// claculate and store the power
							p = times * time;
							// calculate the compound interest
							ci = (principal * pow(x,p)) - principal;
							// clear the screen
							system("cls");
							// print the result
							printf("The quarterly compound interest is %.2f",ci);
							break;
			}
		}
		else
		{	
			//print a message
			printf("Wrong input");
		}
		fflush(stdin);
		//print a message
		printf("\n \nDo you want to continue(type Y/y): ");
		//store the value in a variable
		scanf("%c",&flag);
	}
	//print a mesasage
	printf("\nYou quit the program",getch());
}
/*  main function ends */
