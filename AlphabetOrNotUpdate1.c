/* To check whether a given character is an alphabet or not */
/* Coded by Jaspreet Singh */
/* directory for standard input and output */
#include <stdio.h>
/* directory for character handling */
#include <ctype.h> 
/* directory for string manipulation */
#include <string.h>
#include <windows.h> 
/* Main function starts */
main()
{
	/* declare a variable to store the value of the character input by the user */ 
	char a, flag[100], *pos;
	do
	{	
		system("cls");
		/* print a message */
		printf("Check whether a given character is an alphabet or not \n \n");
		/* print a message */
		printf("Enter any character: ");
		/* store the value of the character input by the user in a variable */
		scanf("%c",&a);
		/* check whether it is a character or not */
		if(isalpha(a) == 0)
		{
			system("cls");
			/* print a message */
			printf("%c is not an alphabet",a);
			getch();
		}
		else
		{
			system("cls");
			/* print a message */
			printf("%c is an alphabet",a);
			getch();
		}
		system("cls");
		// print a message
		printf("Do you want to continue? ");			
		fflush(stdin);
		gets(flag);
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	/* print a message */
	printf("You quit the program");
}
/* main function ends */
