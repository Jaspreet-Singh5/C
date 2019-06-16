

#include <stdio.h>
#include <string.h>
#include <windows.h>

void read();
void add();
void search();
void modify();


	
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
  	printf("3. Search \n");
  	printf("4. Modify \n");
  	printf("5. Exit \n");
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
			search();
			break;
		case 4:
			modify();
			break;
		case 5:
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

void search()
{
	FILE *fps;
	
	system("cls");
	fflush(stdin);
	fps = fopen("employee.txt","r");
	printf("---------------------------\n");
	printf(" 		Search\n");
	printf("---------------------------\n\n");
		
	printf("---------------------------\n");
	printf("Enter the desired employee no.: ");
	scanf("%d", &checkno);
	printf("---------------------------\n\n");	
	flag = 0;
	while(!feof(fps))
	{
		fscanf(fps,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
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
	
}

void modify()
{
	FILE *fpr2;
	FILE *fpm;
	FILE *fpms;
	FILE *fpw;
	system("cls");
	fflush(stdin);
	
	fpms = fopen("employee.txt","r");
	
	fpm = fopen("replica.txt","w");
	
	printf("---------------------------\n");
	printf(" 		Modify\n");
	printf("---------------------------\n\n");
		
	printf("---------------------------\n");
	printf("Enter the desired employee no.: ");
	scanf("%d", &checkno);
	printf("---------------------------\n\n");	
	
	flag = 0; 
	while(!feof(fpms))
	{
		fscanf(fpms,"%d| %[^|]| %[^|]| %[^|]| %d\n",&no,&name,&designation,&dept,&salary);
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
	
	
	
}
