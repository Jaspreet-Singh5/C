// Program to read three whole numbers in decimal form and display their values in octal and hexadecimal number systems using access specifier 
// Coded by Jaspreet Singh 
// for console input and output 
#include<windows.h>
// for standard input and output
#include<stdio.h>
// for standard input and output
#include<conio.h>
// main function starts
main()
{
	// declare variables to store the whole number 1, whole number 2, whole number 3, option, condition, navigator and flag
	int wnum1, wnum2, wnum3, opt, check;
	char flag = 'Y', nav;
	// loop
	while(flag == 'Y' || flag == 'y')
	{
		firstmenu:
		system("cls");
		// print a message
		printf("Program to read three whole numbers in decimal form and display their values in octal and hexadecimal number systems using access specifier \n\n");
		//print a message
		printf("Enter the first whole number: ");
		//store the value in a variable
		scanf("%d",&wnum1);
		//print a message
		printf("Enter the second whole number: ");
		//store the value in a variable
		scanf("%d",&wnum2);
		//print a message
		printf("Enter the third whole number: ");
		//store the value in a variable
		scanf("%d",&wnum3);
		//clear the screen
		system("cls");
		// check condition
		if(!(wnum1 >= 0 && wnum2 >= 0 && wnum3 >= 0))
			goto firstmenu;
		//print a message
		printf("Choose one of the number systems:- \n");
		//print a message
		printf("1. octal \n");
		//print a message
		printf("2. hexadecimal \n");
		//print a message
		printf("3. go back to the previous menu \n");
		//print a message
		printf("Selected option: ");
		//store the value in a variable
		scanf("%d",&opt);
		//clear the screen
		system("cls");
		// check for the number system selected
		if(opt == 1)
		{
			printf("The values of %d, %d and %d in octal number system are: ",wnum1,wnum2,wnum3);
			printf("%o, %o and %o respectively",wnum1,wnum2,wnum3);
		}
		else if(opt == 2)
		{
			printf("The values of %d, %d and %d in hexadecimal number system are: ",wnum1,wnum2,wnum3);
			printf("%x, %x and %x respectively",wnum1,wnum2,wnum3);
		}
		else if(opt == 3)
		{
			goto firstmenu;
		}
		else
		{	
			//print a message
			printf("Wrong input");
		}
		fflush(stdin);
		//print a message
		printf("\nDo you want to continue(type Y/y): ");
		//store the value in a variable
		scanf("%c",&flag);
	}
	//print a mesasage
	printf("\nYou quit the program",getch());
}
/*  main function ends */
