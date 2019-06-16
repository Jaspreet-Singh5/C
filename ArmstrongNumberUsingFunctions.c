// program using c functions to check whether a given number is an Armstrong number
// Coded by Jaspreet Singh
// for standard input and output
#include <stdio.h> 
// for console input and output
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
	
int armstrong(int number)
{
	int indprod, sum = 0, j = 1; 
	int originalNumber, remainder, result = 0, n = 0 ;
	
	originalNumber = remainder = result = n = 0;
	indprod = sum = 0;
	j = 1;
		
	originalNumber = number;
				    
	do
	{
		originalNumber /= 10;
		++n;
	}
	while (originalNumber != 0);
				    
	originalNumber = number;
					
	system("cls");
	do
	{
		remainder = originalNumber%10;
		indprod = pow(remainder, n);
	    sum += indprod;
		printf("%d. %d ^ %d = %d \n", j, remainder, n, indprod);
		getch();
		result += pow(remainder, n);
		originalNumber /= 10;
		j++;
	}
	while (originalNumber != 0);
	printf("Sum of the above given %d terms is: %d", n, sum);
	getch();
	if(sum == number)
	{
		system("cls");
		printf("%d is an Armstrong number.", number);
		getch();
	}
	else
	{
		system("cls");
		printf("%d is not an Armstrong number.", number);
		getch();
	}
}
// main function starts
main()
{
	int opt; 
	int number;
	char flag[100], *pos;
	// loop
	do
	{
		opt = 0;
		number = 0;
		fflush(stdin);
		system("cls");
		// print a message
	    printf("Program to check whether a given number is an Armstrong number or not\n");
	    printf("---------------------------------------------------------------------------------------------------------------- \n\n");
	    // print a message
	    printf("Choose one of the following options: \n");
	    // print a message
	    printf("1. Armstrong Number\n");
		// print a message
	    printf("2. Definition\n");
		// print a message
	    printf("Selected  option is: ");
		// store the number in a variable
		scanf("%d",&opt);
	 	
		switch(opt)
		{
			case 1 :
					system("cls");
					// print a message
				    printf("Program to check whether a given number is an armstrong number or not\n");
					printf("--------------------------------------------------------------------- \n\n");
					    
					printf("Enter an integer: ");
				    scanf("%d", &number);
					if(number < 0)
							break;
				   
				    armstrong(number);
				break;
			case 2:
				system("cls");
				printf("Armstrong Number\n");
				printf("----------------\n\n");
				printf("Given a number x, determine whether the given number is Armstrong number or not.\n");
				printf("A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if.\n");
				printf("abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ....");
				getch();
			break;
			default: printf("Wrong input");
					 getch();
			break;
		}
		system("cls");
	    // check to continue or not
	    if(number < 0 && opt == 1)
		{
			printf("Input could not be a negative integer\n\n");
			getch();
		}
		system("cls");
	    printf("Do you want to continue? ");
	    fflush(stdin);
	    gets(flag);
	    pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	printf("You quit the program");
	getch();
}
 
 
