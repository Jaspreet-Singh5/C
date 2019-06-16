#include<stdio.h>

void line();
double validNum();

void main()
{
	int i,a=1,h=2,n;
	int total, bed[50], food[50], xservices[50], ventilation[50], oxygen[50], med[50], days[50], fees[50], type1[50];
	char pname[50][50], dname[50][50], disease[50][50];
	
	line();
	printf("	Hospital Management System	   \n"); 
	line();
	printf("\n\n");	
	printf("\n TOTAL NUMBER OF PATIENTS: ");
	n=validNum();
	
	for(i=0;i<n;i++)
	{
		if(a==1)
		{
			printf("processing %d......! \n", i+1);
			a++;
		}
		
		if(h>1)
		{
			if(i+2<=n)
			{
				printf("\n processing %d.....! \n",i+2);
			}
			printf("\n Process %d Enters Critical section", i+1);
			
			printf("\n\n");
			printf("Patient no.%d Information\n",i+1);
			line();	
			printf("Enter the name of patient: ");
			scanf("%s",&pname[i][50]);
			printf("Enter the name of the doctor assigned: ");
			scanf("%s",&dname[i][50]);
			printf("Enter the name of the disease: ");
			scanf("%s",&disease[i][50]);
			printf("Enter the no. of days taken for the treatment: "); 		scanf("%d",&days[i]);
			printf("Enter the charges of bed for each day: ");
			scanf("%d",&bed[i]);
			printf("Enter the charges of food for each day: ");
			scanf("%d",&food[i]);
			printf("Choose the type of room alloted:- 1. Normal	2. ICU	"); 
			scanf("%d",&type1[i]);
	
			xservices[i]=0;
			ventilation[i]=0;
			oxygen[i]=0;
	
			if ( type1[i] == 1 )
			{
				printf("Enter the charges of extra services for each day: ");
			scanf("%d",&xservices[i]);
			}
	
			else if ( type1[i] == 2 )
			{
				printf("Enter the charges of extra services for each day: ");
				scanf("%d",&xservices[i]);
				printf("Enter the charges of ventilator: "); 			scanf("%d",&ventilation[i]);
				printf("Enter the charges of oxygen (optional): "); 			scanf("%d",&oxygen[i]);
			}
			
			else
				printf("\nWrong input!\n");
					
			printf("Enter the charges of medicines for each day: ");
			scanf("%d",&med[i]);
			printf("Enter the fees of doctor: ");
			scanf("%d",&fees[i]);
			line();
			
			printf("\n Process %d Leaves Critical section", i+1);
			printf("\n\n");
		
			total = ( bed[i] + food[i] + xservices[i] + ventilation[i] + oxygen[i] + med[i] ) * days[i] + fees[i];
			
			fflush(stdin);
			line();	
			printf("			Bill");
			line();	
			printf("Patient Name: %s\n",pname[i+1]);
			printf("Doctor Assigned: %s\n",dname[i+1]);
			printf("Disease: %s\n",disease[i+1]);
	
			if ( type1[i] == 1 )
			{
				printf("Type: Normal\n");
			}
			
			else if ( type1[i] == 2 )
				printf("Type: ICU\n");
	
			else
				printf("Wrong input!\n");
			
	
			printf("Total amount to be paid: %d",total);
			line();
		}
		h+1;
	}
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

void line() {
	printf("\n");
	printf("\n======================================================\n");
	printf("\n\n");
}

