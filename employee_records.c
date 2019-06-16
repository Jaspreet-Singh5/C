#include <stdio.h>
#include <string.h>
#include <windows.h>

main()
{
	FILE *fp;
	FILE *fpr;
	FILE *fpr2;
	FILE *fpm;
	FILE *fpw;
	
	int i, no, salary, flag,checkno,opt; 
	char name[30], designation[30], dept[30]; 
	
	fp = fopen("employee.txt", "a");
	
	if(fp == NULL)
	{
		return 1;
	}
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf(" Program to Create a employee file to store five records having empno,empname,designation,department and salary.\n");
	printf(" Display the contents of the file.Search using fseek and modify the contents of the file.\n");
	printf("--------------------------------------------------------------------------------------------------------------\n\n\n");
		
	
	printf("---------------------------- \n");
  	printf("1. Add \n");
  	printf("2. Write \n");
  	printf("3. Search \n");
  	printf("4. Modify \n");
  	printf("---------------------------- \n");
  	printf("Selected option: ");
  	scanf("%d", &opt);
  	printf("---------------------------- \n");
	  
	for(i=0;i<0;i++)
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
	
	system("cls");
	fflush(stdin);
	fpr = fopen("employee.txt", "r");
	if(fpr == NULL)
	{
		return 1;
	}
	
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
			
	system("cls");
	fflush(stdin);
	fseek(fpr,0,0);
	printf("---------------------------\n");
	printf(" 		Search\n");
	printf("---------------------------\n\n");
		
	printf("---------------------------\n");
	printf("Enter the desired employee no.: ");
	scanf("%d", &checkno);
	printf("---------------------------\n\n");	
	flag = 0;
	while(!feof(fpr))
	{
		fscanf(fpr,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
		if(checkno == no)
		{
			printf("-----------------------------------------------------------------------------------------------------------------\n");
			printf("                                     Employee details\n");
			printf("-----------------------------------------------------------------------------------------------------------------\n\n");
			printf(" Emp. no.	  Emp. name		         Emp. designation	           Emp. dept.	            Emp. salary\n");
	
			printf("%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);
			printf("-----------------------------------------------------------------------------------------------------------------\n\n");
			
			flag =  1;		
		}
	}
	
	if(!flag)
	{
		printf("--------------------------\n");
		printf("	Record not found");
		printf("--------------------------\n");
	}
	getch();	
	
	system("cls");
	fflush(stdin);
	rewind(fpr);
	fpm = fopen("replica.txt","w");
	
	printf("---------------------------\n");
	printf(" 		Modify\n");
	printf("---------------------------\n\n");
		
	printf("---------------------------\n");
	printf("Enter the desired employee no.: ");
	scanf("%d", &checkno);
	printf("---------------------------\n\n");	
	
	flag = 0; 
	while(!feof(fpr))
	{
		fscanf(fpr,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
		if(checkno != no)
		{
			fprintf(fpm,"%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);	
		}
		else
		{
			system("cls");
			printf("---------------------------\n");
			printf(" Enter the Employee details\n");
			printf("---------------------------\n\n");
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

			fprintf(fpm,"%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);
	
			flag =1;
		}
	}
	
	if(!flag)
	{
		printf("----------------------------\n");
		printf("	Record not found");
		printf("----------------------------\n");
		
	}
		
	getch();
	
	fclose(fp);
	fclose(fpr);
	fclose(fpm);

	fpr2 = fopen("replica.txt","r");
	fpw = fopen("employee.txt","w");
	while(!feof(fpr2))
	{
		fscanf(fpr2,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
		fprintf(fpw,"%10d| %-30s| %-30s| %-30s| %10d\n",no,name,designation,dept,salary);	
	}
	fclose(fpr2);
	fclose(fpw);
		
		return 0;
}
