// Program to print the minimum and maximum range of basic data types in C 
// Coded by Jaspreet Singh 
// for console input and output 
#include<windows.h>
// for standard input and output
#include<stdio.h>
// for limits of int and char data types
#include<limits.h>
// for limits of float and double data types
#include<float.h>
// main function starts
main()
{
	// declare variables to store the option 1, option 2, option for short and long int, navigator and flag
	int opt1, opt2, optsl;
	char flag = 'Y', nav;
	// loop
	while(flag == 'Y' || flag == 'y')
	{
		firstmenu:
		system("cls");
		// print a message
		printf("Program to print the minimum and maximum range of basic data types in C \n\n");
		//print a message
		printf("Choose one of the basic data types:- \n");
		//print a message
		printf("1. int \n");
		//print a message
		printf("2. char \n");
		//print a message
		printf("3. float \n");
		//print a message
		printf("4. double \n");
		//print a message
		printf("Selected option: ");
		//store the value in a variable
		scanf("%d",&opt1);
		//clear the screen
		system("cls");
		// check for the basic data type selected
		if(opt1 == 1)
		{
			intmenu:
			system("cls");
			//print a message
			printf("Choose one of the modifiers:- \n");
			//print a message
			printf("1. signed \n");
			//print a message
			printf("2. unsigned \n");
			//print a message
			printf("3. short \n");
			//print a message
			printf("4. long \n");
			//print a message
			printf("5. go back to the previous menu \n");
			//print a message
			printf("Selected option: ");
			//store the value in a variable
			scanf("%d",&opt2);
			//clear the screen
			system("cls");
			//check for different cases
			switch(opt2)
			{
				// signed int
				case 1 : // print the minimum value
						 printf("The minimum value of SIGNED INT = %d\n", INT_MIN);
						 // print the maximum value
					     printf("The maximum value of SIGNED INT = %d\n", INT_MAX); 
						 break;
				// unsigned int
				case 2 : // print the minimum value
						 printf("The minimum value of UNSIGNED INT = 0\n");
						 // print the maximum value
					     printf("The maximum value of UNSIGNED INT = %u\n", UINT_MAX); 
						 break;
				// short int
				case 3 : //print a message
						 printf("Choose one of the modifiers: \n");
						 //print a message
					     printf("1. signed \n");
						 //print a message
					     printf("2. unsigned \n");
						 //print a message
						 printf("3. go back to the previous menu \n");
						 //print a message
						 printf("Selected option: ");
						 //store the value in a variable
						 scanf("%d",&optsl);
						 //clear the screen
						 system("cls");
						 // check for the selected option
						 if(optsl == 1)
						 {
							// print the minimum value
						 	printf("The minimum value of SIGNED SHORT INT = %hi\n", SHRT_MIN);
						    // print the maximum value
					        printf("The maximum value of SIGNED SHORT INT = %hi\n", SHRT_MAX); 
					 	 }
						 else if(optsl == 2)
					 	 {
							// print the minimum value
						 	printf("The minimum value of UNSIGNED SHORT INT = 0\n");
						    // print the maximum value
					        printf("The maximum value of UNSIGNED SHORT INT = %hu\n", USHRT_MAX); 
						 }
						 else if(optsl == 3)
							goto intmenu;
						 else 
						 {
							//print a message
						    printf("Wrong input");
						 }
						 break;
				// long int
				case 4 : //print a message
						 printf("Choose one of the modifiers:- \n");
						 //print a message
					     printf("1. signed \n");
						 //print a message
					     printf("2. unsigned \n");
						 //print a message
						 printf("3. go back to the previous menu \n");
						 //print a message
						 printf("Selected option: ");
						 //store the value in a variable
						 scanf("%d",&optsl);
						 //clear the screen
						 system("cls");
					  	 // check for the selected option
					 	 if(optsl == 1)
						 { 
							// print the minimum value
						 	printf("The minimum value of SIGNED LONG INT = %ld\n", LONG_MIN);
						    // print the maximum value
					        printf("The maximum value of SIGNED LONG INT = %ld\n", LONG_MAX); 
						 }
						 else if(optsl == 2)
						 {
							// print the minimum value
						 	printf("The minimum value of UNSIGNED LONG INT = 0\n");
						    // print the maximum value
					        printf("The maximum value of UNSIGNED LONG INT = %lu\n", ULONG_MAX); 
						 }
						 else if(optsl == 3)
							goto intmenu;
						 else 
						 {
							//print a message
						    printf("Wrong input");
						 }
						 break;
				// go to previous menu
				case 5 : goto firstmenu;
					     break;
				default : //print a message
						  printf("Wrong input");
			}
		}
		// check for the basic data type selected
		else if(opt1 == 2)
		{
			//print a message
			printf("Choose one of the modifiers:- \n");
			//print a message
			printf("1. signed \n");
			//print a message
			printf("2. unsigned \n");
			//print a message
			printf("3. go back to the previous menu \n");
			//print a message
			printf("Selected option: ");
			//store the value in a variable
			scanf("%d",&opt2);
			system("cls");
			//check for different cases
			switch(opt2)
			{
				// signed char
				case 1 : // print the minimum value
						 printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
						 // print the maximum value
					     printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX); 
						 break;
				// unsigned char
				case 2 : // print the minimum value
						 printf("The minimum value of UNSIGNED CHAR = 0\n");
						 // print the maximum value
					     printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX); 
						 break;
				// go to previous menu
				case 5 : goto firstmenu;
					     break;
				default : //print a message
						  printf("Wrong input");
			}
		}
		// check for the basic data type selected
		else if(opt1 == 3)
		{
			// print the minimum value
			printf("The minimum value of FLOAT = %e\n", FLT_MIN);
			// print the maximum value
			printf("The maximum value of FLOAT = %e\n", FLT_MAX);
		}
		// check for the basic data type selected
		else if(opt1 == 4)
		{
			//print a message
			printf("Choose one of the modifiers:- \n");
			//print a message
			printf("1. none \n");
			//print a message
			printf("2. long \n");
			//print a message
			printf("3. go back to the previous menu \n");
			//print a message
			printf("Selected option: ");
			//store the value in a variable
			scanf("%d",&opt2);
			//clear the screen
			system("cls");
			//check for different cases
			switch(opt2)
			{
				// double
				case 1 : // print the minimum value
						 printf("The minimum value of DOUBLE = %e\n", DBL_MIN);
						 // print the maximum value
					     printf("The maximum value of DOUBLE = %e\n", DBL_MAX); 
						 break;
				// unsigned long
				case 2 : // print the minimum value
						 printf("The minimum value of LONG DOUBLE = %e\n", LDBL_MIN);
						 // print the maximum value
						 
						 
						 
						 
						 
						 //error
					     printf("The maximum value of LONG DOUBLE = %e\n", LDBL_MAX); 
						 break;
				// go to previous menu
				case 5 : goto firstmenu;
					     break;
				default : //print a message
						  printf("Wrong input");
			}
		}
		else 
		{
			//print a message
			printf("Wrong input");
		}
		fflush(stdin);
		//print a message
		printf("Do you want to continue(type Y/y): ");
		//store the value in a variable
		scanf("%c",&flag);
	}
}
/*  main function ends */
