// Program to generate the fibonacci numbers for a given limit
// Coded by Jaspreet Singh
// for standard input and output
#include <stdio.h> 
// for console input and output
#include <conio.h>
#include <windows.h>
#include <string.h>

int fibonacci(int n)
{
	if(n == 0)
	return 0;
	
	else if(n == 1)
	return 1;
	
	
	else
	return fibonacci(n-1) + fibonacci(n-2); 
}

// main function starts
main()
{
	int num, i, opt;
	char flag[100], *pos;
	// loop
	do
	{
		system("cls");
		// print a message
	    printf("------------------------------------------------------------- \n");
	    printf(" Program to generate the fibonnaci numbers for a given limit\n");
	    printf("------------------------------------------------------------- \n\n");
	    printf("----------------------------------------------\n");
		// print a message
	    printf("Choose one of the following options: \n");
	    // print a message
	    printf("1. Fibonacci Numbers\n");
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
			case 1 :
					system("cls");
					printf("\n");
					printf("-------------------------------------\n");
					printf(" Enter the limit(n): ");
					scanf("%d", &num);
					printf("-------------------------------------\n");
					
					if(num<=0)
					break;
					system("cls");
					fflush(stdin);
					// print a message
					printf("------------------\n");
				    printf(" Fibonnaci Numbers\n");
					printf("------------------\n\n\n");
					
					for(i=0;i<num;i++)
					{
						printf("%d\n",fibonacci(i));
					}
					getch();
			break;
		case 2 :
				system("cls");
				// print a message
				printf("------------------\n");
			    printf(" Fibonnaci Numbers\n");
				printf("------------------\n\n\n");
				    
				printf("--------------------------------------------------------------------------------------------------\n");
				printf("In mathematics, the Fibonacci numbers are the numbers in the following integer sequence, called\n"); 
				printf("the Fibonacci sequence, and characterized by the fact that every number after the first two is\n");
				printf("the sum of the two preceding ones:\n");

				printf("1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ....\n");
				printf("Often, especially in modern usage, the sequence is extended by one more initial term:\n");
				printf("0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ....\n");

				printf("By definition, the first two numbers in the Fibonacci sequence are either 1 and 1, or\n");
				printf("0 and 1, depending on the chosen starting point of the sequence, and each subsequent\n");
				printf("number is the sum of the previous two.\n");

				printf("-----------------------------------------------------------------------------------------------\n");
				
				break;
		default: printf("Wrong input");
				 getch();
	}
		if(num <= 0)
			printf("Input could not be a negative integer or zero\n\n");
			getch();
		system("cls");
	    // check to continue or not
	    printf("Do you want to continue? ");
	    fflush(stdin);
	    gets(flag);
	    pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	printf("You quit the program");
	getch();
}
 

