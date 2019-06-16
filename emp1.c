#include <stdio.h>
#include <string.h>
#include <windows.h>

void read();
void add();
	
int i, no, salary, flag,checkno,opt; 
char name[30], designation[30], dept[30]; 

main()
{
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf(" Program to Create a employee file to store five records having empno,empname,designation,department and salary.\n");
	printf(" Display the contents of the file.Search using fseek and modify the contents of the file.\n");
	printf("--------------------------------------------------------------------------------------------------------------\n\n\n");
		
	
	printf("---------------------------- \n");
  	printf("1. Add \n");
  	printf("2. Read \n");
  	printf("3. Exit \n");
  	printf("---------------------------- \n");
  	printf("Selected option: ");
  	scanf("%d", &opt);
  	printf("---------------------------- \n");
	  
	switch(opt)
	{
		case 1:
			add();
			break;
		case 2:
			read();
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			printf("Wrong Input!");
			getch();
	}
		
			
	
	
	
		
		return 0;
}


void add()
{
	FILE *fp;
	fp = fopen("employee.txt", "a");
	
	
	
	for(i=0;i<5;i++)
	{
		system("cls");
		printf("---------------------------\n");
		printf(" Enter the Employee details\n");
		printf("---------------------------\n\n");
		printf("----------------------- Employee %d ----------------------------------------------------\n",i+1);
			
		printf("No.: ");
		scanf("%d", &no);
		fflush(stdin);
		printf("Name: ");
		gets(name);
		fflush(stdin);
		printf("Designation: ");
		gets(designation);
		fflush(stdin);
		printf("Department: ");
		gets(dept);
		fflush(stdin);
		printf("Salary: ");
		scanf("%d",&salary);
		printf("---------------------------------------------------------------------------------------\n");
		fprintf(fp,"%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);
	}
	
	fclose(fp);
}

void read()
{
	FILE *fpr;

	system("cls");
	fflush(stdin);
	fpr = fopen("employee.txt", "r");
	
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("                                     Employee details\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n\n");
	printf(" Emp. no.	  Emp. name		         Emp. designation	           Emp. dept.	            Emp. salary\n");
		
	while(!feof(fpr))
	{
		fscanf(fpr,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
		printf("%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);
	}
	printf("-----------------------------------------------------------------------------------------------------------------\n\n");
	getch();
	fclose(fpr);
}

