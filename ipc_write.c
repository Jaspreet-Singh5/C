//IPC shared memory write
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include<string.h>

//using namespace std; 

  

int main() 
{ 

    // ftok to generate unique key 

    key_t key = ftok("shmfile",65); 

  

    // shmget returns an identifier in shmid 

    int shmid = shmget(key,1024,0666|IPC_CREAT); 

  

    // shmat to attach to shared memory 

    char *str = (char*) shmat(shmid,(void*)0,0); 

  

    int num;
	int i, total, bed[50], food[50], xservices[50], ventilation[50], oxygen[50], med[50], days[50], fees[50], type1[50];
	char pname[50][50], dname[50][50], disease[50][50];

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
      

    //detach from shared memory  

    shmdt(str); 

    return 0; 
} 
