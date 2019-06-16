#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 20 

struct patient {
	int bed, food, xservices, ventilation, oxygen, med, days, fees, type1;
	char name[MAX_LIMIT], dname[MAX_LIMIT], pname[MAX_LIMIT], disease[MAX_LIMIT];
};

void line();
double menu(int);
double validNum();
int wait(int);
int signal(int);

struct patient * getDetails(struct patient *, int, int *, int *, int *);
struct patient * printBill(int *,struct patient [], int *, int *, int *);

main() {
	int mutex=1, empty=10, full=0, num=1;
	int opt = 0; 
	struct patient *p;
	
	line();
	printf("Program to solve producer consumer problem using mutex");
	line();
	
	while(1) {
		opt = menu(opt);
	
		switch(opt) {
			case 1:
				if((mutex==1)&&(empty!=0)) {
					if(num==1) {
						p = (struct patient *)calloc(++num, sizeof(struct patient));
					}
					else 
						p = (struct patient *)realloc(p,++num*sizeof(struct patient));
					
					p=getDetails(p,num-1,&mutex,&empty,&full);	
				}
 				else {
 						line();
 						printf("Buffer is full!!");
						line();		
				 }
			break;
			
			case 2:	
				if((mutex==1)&&(full!=0))
					p=printBill(&num,p,&mutex,&empty,&full);
				else {
					line();
					printf("Buffer is empty!!");
					line();		
				}
			break;
			
			case 3:
				exit(0);
			break;
		}	
	}
	
}

// main menu
double menu(int opt2) {
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf(" Choose one of the following options");
	line();
	printf("1. Enter the details\n");
	printf("2. Get the details\n");
	printf("5. Exit\n");
	line();
	if(!(0)){
		printf("Selected option: ");	
	}
	while (opt1 < 1 || opt1>3)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	if(0){
					printf("Selected option: ");
				}
				else
					printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 1)
                printf("Error! Please enter a POSITIVE number: ");
            
	    	else if(opt1>3){
	    		line();
	    		printf("Wrong input!!\n");
	    		line();
	    	}
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

// int validation
double validNum(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	while (opt1<1 || opt1>999)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	
				printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 1)
                printf("Error! Please enter a POSITIVE number: ");
            else if (opt1 > 999)
                printf("Error! Please enter a smaller number: ");
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

int wait(int s)
{
	return (--s);
}
 
int signal(int s)
{
	return(++s);
}

struct patient * getDetails(struct patient *p, int i, int *mutex, int *empty, int *full) {
	int total;
	
	*mutex=wait(*mutex);
	*empty=wait(*empty);
	
	line();
	printf("	Hospital Management System	   \n"); 
	line();
	printf("\n\n");	
	
	printf("\n\n");
	line();	
	printf("Patient Information\n");
	line();	
	
	printf("Enter the name of patient: ");
	fgets(p[i].name, MAX_LIMIT, stdin); 
	printf("Enter the name of the doctor assigned: ");
	fgets(p[i].dname, MAX_LIMIT, stdin); 
	printf("Enter the name of the disease: ");
	fgets(p[i].disease, MAX_LIMIT, stdin); 
	printf("Enter the no. of days taken for the treatment: "); 		
	scanf("%d",&p[i].days);
	printf("Enter the charges of bed for each day: ");
	scanf("%d",&p[i].bed);
	printf("Enter the charges of food for each day: ");
	scanf("%d",&p[i].food);
	printf("Choose the type of room alloted:- 1. Normal	2. ICU	"); 
	scanf("%d",&p[i].type1);

	p[i].xservices=0;
	p[i].ventilation=0;
	p[i].oxygen=0;

	if ( p[i].type1 == 1 )
	{
		printf("Enter the charges of extra services for each day: ");
	scanf("%d",&p[i].xservices);
	}

	else if ( p[i].type1 == 2 )
	{
		printf("Enter the charges of extra services for each day: ");
		scanf("%d",&p[i].xservices);
		printf("Enter the charges of ventilator: "); 			scanf("%d",&p[i].ventilation);
		printf("Enter the charges of oxygen (optional): "); 			scanf("%d",&p[i].oxygen);
	}
	
	else
		printf("\nWrong input!\n");
			
	printf("Enter the charges of medicines for each day: ");
	scanf("%d",&p[i].med);
	printf("Enter the fees of doctor: ");
	scanf("%d",&p[i].fees);
	line();

	*mutex=signal(*mutex);
	*full=signal(*full);
	
	return p;
}

struct patient * printBill(int *i,struct patient p[], int *mutex, int *empty, int *full) {
	int total;
	
	*mutex=wait(*mutex);
	*full=wait(*full);
	
	printf("\n\n");
		
	total = ( p[*i-1].bed + p[*i-1].food + p[*i-1].xservices + p[*i-1].ventilation + p[*i-1].oxygen + p[*i-1].med ) * p[*i-1].days 
	+ p[*i-1].fees;
	
	fflush(stdin);
	line();	
	printf("			Bill");
	line();	
	printf("Patient Name: %s \n", p[*i-1].name);
	printf("Doctor Assigned: %s\n", p[*i-1].dname);
	printf("Disease: %s\n", p[*i-1].disease);

	if ( p[*i-1].type1 == 1 )
	{
		printf("Type: Normal\n");
	}
	
	else if ( p[*i-1].type1 == 2 )
		printf("Type: ICU\n");

	else
		printf("Wrong input!\n");
	

	printf("Total amount to be paid: %d",total);
	line();
	
	*i = *i - 1;
	p = (struct patient *)realloc(p,*i * sizeof(struct patient));
	
	*empty=signal(*empty);
	*mutex=signal(*mutex);
	
	return p; 
}

void line() {
	printf("\n");
	printf("\n======================================================\n");
	printf("\n\n");
}

