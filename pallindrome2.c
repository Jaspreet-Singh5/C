// Demonstrate a program to check whether a given string is a palindrome or not and also convert the string to uppercase without using inbuilt string function
// Coded by Jaspreet Singh
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
// main function starts
main()
{
	int flag = 1, i, j, k, u, opt, opt2;
	char first[50], check[20], *pos;
	
	do
	{
		system("cls");
		flag = 1;
		i = j = k = u = opt = opt2 =0;
		first[0] = '\0';
		
		printf("\n");
		printf("----------------------------------------------------------------------------------------------------------- \n");
		printf(" Program to check whether a given string is a palindrome or not and also convert the string to uppercase \n");
		printf("----------------------------------------------------------------------------------------------------------- \n");
		printf("----------------------------------------------------------------------------------------------------------- \n\n");
		printf("---------------------------- \n");
		printf("1. Pallindrome or not \n");
		printf("2. Case conversion \n");
		printf("3. Definition of Pallindrome \n");
		printf("---------------------------- \n");
		printf("Selected option: ");
		scanf("%d", &opt);
		printf("---------------------------- \n");
		switch(opt)
		{
			case 1:
					system("cls");
					printf("---------------------------- \n");
				  	printf("1. Pallindrome or not \n");
				  	printf("---------------------------- \n\n");
				  	fflush(stdin);
					printf("--------------------- \n");
					puts("Enter any string:- ");
					gets(first);
					printf("--------------------- \n");
					
					for(i = 0; first[i] != '\0'; i++)
					{
						if(first[i] >= 'a' && first[i] <= 'z')
							first[i] = first[i] - 32;
					}
					
					for(j = 0, k = (i - 1); j < i, k >= 0; j++, k--)
					{
						if(first[j] != first[k]) 
						{
							flag = 0;
							break;
						}		
					}
					if(flag == 1)
					{
						if(first[0] == '\0')
						{
							printf("---------------------\n");
							printf("It's an empty string. \n");
							printf("---------------------\n");
						}
						else
						{
							printf("--------------------------------------------------------------\n");
							printf("Yes, %s's a pallindrome string. \n", first);
							printf("--------------------------------------------------------------\n");
						}
					}
					else
					{
						printf("------------------------------------------------------------------\n");
						printf("No, %s's not a pallindrome string. \n", first);		
						printf("------------------------------------------------------------------\n");
					}
			break;
			
			case 2:
					system("cls");
					printf("---------------------------- \n");
				  	printf("2. Case conversion \n");
				  	printf("---------------------------- \n\n");
				  	fflush(stdin);
				  	printf("---------------------------- \n");
					printf("1. Uppercase \n");
					printf("2. Lowercase \n");
					printf("---------------------------- \n");
					printf("Selected option: ");
					scanf("%d", &opt2);
					printf("---------------------------- \n");
					
					system("cls");
					fflush(stdin);
					printf("----------------------\n");
					puts("Enter any string:- ");
					gets(first);
					printf("----------------------\n");
									
					switch(opt2)
					{
						case 1:
								for(i = 0; first[i] != '\0'; i++)
								{
									if(first[i] >= 'a' && first[i] <= 'z')
										first[i] = first[i] - 32;
								}
								if(first[0] == '\0')
								{
									printf("---------------------\n");
									printf("It's an empty string. \n");
									printf("---------------------\n");
								}
								else
								{
									printf("---------------------\n");
									puts(first);
									printf("---------------------\n");
								}
						break;
						
						case 2:
								for(i = 0; first[i] != '\0'; i++)
								{
									if(first[i] >= 'A' && first[i] <= 'Z')
										first[i] = first[i] + 32;
								}
								if(first[0] == '\0')
								{
									printf("---------------------\n");
									printf("It's an empty string. \n");
									printf("---------------------\n");
								}
								else
								{
									printf("---------------------\n");
									puts(first);
									printf("---------------------\n");
								}
						break;
						
						default: puts("Wrong input!");
					}
			break;
			
			case 3:
					system("cls");
					printf("---------------------------- \n");
				  	printf("3. Pallindrome \n");
				  	printf("---------------------------- \n\n");
				  	printf("--------------------------------------------------------------------------------------------------------- \n");
					puts("The characters read the same backward as forward.\n");
					puts("Some examples of palindromic words are:-");
					puts("redivider, deified, noon, civic, radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer.");
					printf("---------------------------------------------------------------------------------------------------------- \n");
			break;
			
			default:
					printf("------------- \n");
				  	puts("Wrong input!");
				  	printf("------------- \n");
		}
		getch();
		system("cls");
		fflush(stdin);
		printf("\n");
		printf("------------------------------------\n");
		puts("Do you want to continue?");
		gets(check);
		printf("------------------------------------\n");
		pos = strchr(strupr(check), 'Y');
	}
	while(pos);
	printf("You quit the program");
	getch();
}

 
