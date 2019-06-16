// program to implement the usage of while loop to find the factorial of a given number
// Coded by Jaspreet Singh
// for standard input and output
#include <stdio.h> 
// for console input and output
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Maximum number of digits in output
#define MAX 510999
 
// main function starts
main()
{
	// declare variables to store the number whose factorial is to be find, factorial, counter and flag
	int fact[MAX], fact_size = 1, prod, i, n1, opt, x, def, indprod, sum = 0, j = 1; 
	int number, originalNumber, remainder, result = 0, n = 0 ;
	char flag[100], *pos;
	int carry = 0;  // Initialize carry
    // Initialize result
    fact[0] = 1;
    // loop
	do
	{
		number = originalNumber = remainder = result = n = 0;
		fact[0] = 1;
		fact_size = 1;
		prod = i = n1 = opt = x = def = indprod = sum = 0;
		fflush(stdin);
		j = 1;
		carry = 0;
		system("cls");
		// print a message
	    printf("Program to find the factorial of a given number or to check whether a given number is an Armstrong number or not\n");
	    printf("---------------------------------------------------------------------------------------------------------------- \n\n");
	    // print a message
	    printf("Choose one of the following options: \n");
	    // print a message
	    printf("1. Factorial\n");
	    // print a message
	    printf("2. Armstrong Number\n");
		// print a message
	    printf("3. Definition\n");
		// print a message
	    printf("Selected  option is: ");
		// store the number in a variable
		scanf("%d",&opt);
	 	
		switch(opt)
		{
			case 1 :
					for (i = fact_size-1; i>=0; i--)
				        fact[i] = 1;
					fact_size = 1;
					system("cls");
					// print a message
				    printf("Program to find the factorial of a given number\n");
				    printf("----------------------------------------------- \n\n");
				    // print a message
				    printf("Enter the number whose factorial is to be find: ");
				    // store the number in a variable
					scanf("%d",&n1);
					if(n1 < 0)
						break;
				 	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
				   	for (x=2; x<= n1; x++)
					{
						// multiply x with the number 
						// represented by fact[]
						// fact_size is size of fact[] or number of digits in the number represented by fact[] 
						// uses simple school mathematics for multiplication
						for (i=0; i < fact_size; i++)
					    {
					        prod = fact[i] * x + carry;
					 
					        // Store last digit of 'prod' in fact[]  
					        fact[i] = prod % 10;  
					 
					        // Put factt in carry
					        carry  = prod/10;    
					    }
					 
					    // Put carry in fact[] and increase fact_size
					    while (carry)
					    {
					        fact[fact_size] = carry%10;
					        carry = carry/10;
					        fact_size++;
					    }
					}
					system("cls");
					printf("Factorail of the given number is: ");
				    for (i = fact_size-1; i>=0; i--)
				        printf("%d",fact[i]);
				        getch();
			break;
		case 2 :
				system("cls");
				// print a message
			    printf("Program to check whether a given number is an armstrong number or not\n");
				printf("--------------------------------------------------------------------- \n\n");
				    
				printf("Enter an integer: ");
			    scanf("%d", &number);
				if(number < 0)
						break;
			   
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
			break;
			case 3:
				system("cls");
				// print a message
			    printf("Choose one of the following options\n");
				printf("-----------------------------------\n\n");
				printf("1. Factorial\n");
				printf("2. Armstrong number\n");
			    printf("Selected option: ");
				scanf("%d", &def);
				system("cls");
				switch(def)
				{
					case 1: printf("Factorial\n");
							printf("---------\n\n");
							printf("Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n.\n");
							printf("For example factorial of 6 is 6*5*4*3*2*1 which is 720.\n");
							printf("Factorial can be calculated using following recursive formula.\n");
							printf("n! = n * (n-1)! \nn! = 1 if n = 0 or n = 1");
							getch();
					break;
					case 2: printf("Armstrong Number\n");
							printf("----------------\n\n");
							printf("Given a number x, determine whether the given number is Armstrong number or not.\n");
							printf("A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if.\n");
							printf("abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ....");
							getch();
					break;
					default: printf("Wrong input");
						     getch();
				}
		break;
		default: printf("Wrong input");
				 getch();
		break;
		}
		system("cls");
	    // check to continue or not
	    if(n1 < 0 && opt == 1)
		{
			printf("Input could not be a negative integer\n\n");
			getch();
		}
		if(number < 0 && opt == 2)
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
 

