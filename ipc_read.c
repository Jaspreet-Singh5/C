//IPC shared memory read
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 


//using namespace std; 

  

int main() 
{ 
	
    // ftok to generate unique key 

    key_t key = ftok("shmfile",65); 

  

    // shmget returns an identifier in shmid 

    int shmid = shmget(key,1024,0666|IPC_CREAT); 

  

    // shmat to attach to shared memory 

    char *str = (char*) shmat(shmid,(void*)0,0); 

  

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

    //detach from shared memory  

    shmdt(str);  //destroying the memory

    // destroy the shared memory 

    shmctl(shmid,IPC_RMID,NULL); 

   return 0; 
} 

