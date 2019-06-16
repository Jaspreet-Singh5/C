// Program to advice the student as to which course he/she is eligible for admission on the basis of marks/grades in the following courses 
// Coded by Jaspreet Singh 
// for console input and output 
#include<windows.h>
// for standard input and output
#include<stdio.h>
// for standard input and output
#include<conio.h>
// main function starts
#include<string.h>
main()
{
	// declare variables to store the number of subjects, marks, counter, total marks, percentage and flag
	int i, sum, course;
	double percentage, marks[5];
	char flag = 'Y', maths;	
	// loop
	while(flag == 'Y' || flag == 'y')
	{
		//unset the values of the array marks
		for(i = 0; i < 5; i++)
			marks[i] = 0;
		system("cls");
		// print a message
		printf("Program to advice the student as to which course he/she is eligible for admission on the basis of marks in the following courses \n");
		// print a message
		printf("1. EMS \n");
		// print a message
		printf("2. Social Sciences \n");
		// print a message
		printf("3. Languages \n\n");
		//print a message
		printf("Which course you are interested in: ");
		//store the value in a variable
		scanf("%d",&course);
		// validation
		if(course < 1 || course > 3)
		break;
		// check for different cases
		switch(course)
		{
			case 1: system("cls");
					fflush(stdin);
					// print a message
					printf("Have you studied Mathematics at class XII level: (y/n)");
					// store the value
					scanf("%c",&maths);
					// check for the condition
					if(maths == 'Y' || maths == 'y')
					{
						//clear the screen
						system("cls");
						// for loop to get marks in each subject
						for(i = 0; i < 5; i++)
						{
							//print a message
							printf("Enter your marks in subject %d: ",i +1);
							//store the value in a variable
							scanf("%lf",&marks[i]);
							// calculate total marks
							sum = sum + marks[i];
							if(marks[i] <= 40 || marks[i] >100)
								break;
						}
						// calculate percentage
						percentage = sum / 5;
						// check condition
						if(percentage >= 80)
						{
							printf("Congratulations! You are eligible to apply for EMS");
						}
						else
						{
							if(marks[i] <= 40)
								printf("Sorry! you should be pass in each subject\n");
							else if(marks[i] > 100)
								printf("Sorry! marks can not be greater than 100");
							else
								printf("Sorry! percentage should be greater than or equal to 80 to get into EMS");
						}
					}
					else
						break;
					break;
			case 2: system("cls");
					for(i = 0; i < 5; i++)
					{
						//print a message
						printf("Enter your marks in subject %d: ",i +1);
						//store the value in a variable
						scanf("%lf",&marks[i]);
						// calculate total marks
						sum = sum + marks[i];
						if(marks[i] <= 40 || marks[i] >100)
							break;
					}
					// calculate percentage
					percentage = sum / 5;
					// check condition
					if(percentage >= 65)
					{
						printf("Congratulations! You are eligible to apply for Social Sciences");
					}	
					else
					{
						if(marks[i] <= 40)
							printf("Sorry! you should be pass in each subject\n");
						else if(marks[i] > 100)
							printf("Sorry! marks can not be greater than 100");
						else
							printf("Sorry! percentage should be greater than or equal to 65 to get into Social Sciences");
					}
					break;
			case 3: system("cls");
					// for loop to get marks in each subject
					for(i = 0; i < 5; i++)
					{
						//print a message
						printf("Enter your marks in subject %d: ",i +1);
						//store the value in a variable
						scanf("%lf",&marks[i]);
						// calculate total marks
						sum = sum + marks[i];
						if(marks[i] <= 40 || marks[i] >100)
							break;
					}
					// calculate percentage
					percentage = sum / 5;
					// check condition
					if(percentage >= 50)
					{
						printf("Congratulations! You are eligible to apply for Languages");
					}
					else
					{
						if(marks[i] <= 40)
							printf("Sorry! you should be pass in each subject\n");
						else if(marks[i] > 100)
							printf("Sorry! marks can not be greater than 100");
						else
							printf("Sorry! percentage should be greater than or equal to 50 to get into Languages");
					}
					break;
		}
						
		fflush(stdin);
		//print a message
		printf("\nDo you want to continue(type Y/y): ");
		//store the value in a variable
		scanf("%c",&flag);	
	}
	system("cls");
	if(course < 1 || course > 3)
		printf("Sorry! the input should be 1, 2 or 3\n");
	else if(maths == 'N' || maths == 'n')
		printf("Sorry! mathematics is compulsory for gettin into the EMS course");
	else if(maths != 'N' || maths != 'Y' || maths != 'n' || maths != 'y')
		printf("Sorry! wrong input");
	//print a mesasage
	printf("Program has been quit");
	getch();
}
/*  main function ends */
