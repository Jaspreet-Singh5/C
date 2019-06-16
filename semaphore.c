#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

void line();
sem_t sems; //predefined structure in semaphore.h

void* thread(void* arg) 
{ 
	int num;
	int i,total, bed[50], food[50], xservices[50], ventilation[50], oxygen[50], med[50], days[50], fees[50], type1[50];
	char pname[50][50], dname[50][50], disease[50][50];
	
    //wait 
    sem_wait(&sems); 
    
	printf("\nEntered..\n"); 
	
	line();
	printf("	Hospital Management System	   \n"); 
	line();
	printf("\n\n");	
	printf("Enter the number of patients: ");
	scanf("%d",&num);

	for (i=0;i<num;i++)
	{
		printf("\n\n");
		line();	
		printf("Patient Information\n");
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
	}
	
    sleep(4); 
    //signal 
    printf("\nJust Exiting...\n");
	
	i=0;

	while ( i < num )
	{
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

		i++;
	}
 
    sem_post(&sems); 
} 

int main() 
{ 
    sem_init(&sems, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&sems); 
    return 0; 
}

void line() {
	printf("\n---------------------------------------------\n");
}	
