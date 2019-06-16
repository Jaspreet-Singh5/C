#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void line();
double menu(int);
double validNum();

int isEmptyArr (int, int);
int * enQueueArr(int, int *, int *, int *, int *);
void printArr(int [], int, int,int);
void deQueueArr(int *, int *, int *,int *);

void enQueueLL(int);
void printLL();
void deQueueLL();

struct Node *front=NULL;
struct Node *rear=NULL;

main() {
	int x,n,opt,i;
	int frontArr=-1, rearArr=-1, *arr,sizeArr=50;
	arr=(int *)malloc(sizeArr*sizeof(int));
	
	line();
	printf("Program to implement queue using array and linked list");
	line();
	
	while(1) {
		opt=(int)menu(opt);
	
		switch(opt) {
			case 1: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					line();	
					printf("Enter the value of element no.%d: ",i+1);
					x=(int)validNum();
					line();
					
					enQueueArr(x,arr,&frontArr,&rearArr,&sizeArr);
				}
				printArr(arr,frontArr,rearArr,sizeArr);
			break;	
					
			case 2: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					deQueueArr(arr,&frontArr,&rearArr,&sizeArr);
				}
				printArr(arr,frontArr,rearArr,sizeArr);
			break;
			
			case 3: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					line();	
					printf("Enter the value of element no.%d: ",i+1);
					x=(int)validNum();
					line();
					
					enQueueLL(x);
				}
				printLL();
			break;	
					
			case 4: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					deQueueLL();
				}
				printLL();
			break;
			
			case 5:
				printArr(arr,frontArr,rearArr,sizeArr);
			break;
			
			case 6:
				printLL();
			break;
			
			case 7:
				exit(1);
			break;
		}
	}
	
	free(front);
}

// main menu
double menu(int opt2) {
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf("\n\n");
	line();
	printf(" Choose one of the following options");
	line();
	printf("1. Enqueue (array)\n");
	printf("2. Dequeue (array)\n");
	printf("3. Enqueue (linked list)\n");
	printf("4. Dequeue (linked list)\n");
	printf("5. Display (array)\n");
	printf("6. Display (linked list)\n");
	printf("7. Exit\n");
	line();
	if(!(0)){
		printf("Selected option: ");	
	}
	while (opt1 < 1 || opt1>7)
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
            
	    	else if(opt1>7){
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

int isEmptyArr(int front, int rear) {
	if(front == -1 && rear == -1)
		return 1;
	else 
		return 0;
}

int * enQueueArr(int x, int *arr, int *front, int *rear, int *size) {	
	if(isEmptyArr(*front,*rear)) {
		*front=0;
		*rear=0;
	}
	else if ((*rear+1)%(*size) == *front) {
		*size=2*(*size);
		arr=(int *)realloc(arr,*size*sizeof(int));
		*rear=(*rear+1)%(*size);	
	}
	
	else {
		*rear=(*rear+1)%(*size);
	}
	
	arr[*rear]=x;
	
	return arr;
}

void deQueueArr(int *arr, int *front, int *rear,int *size) {
	if(isEmptyArr(*front,*rear)) {
		return;
	}
	else if (*front == *rear)
		*front = *rear = -1;
	
	else
		*front=(*front+1)%(*size);
}       


void printArr(int *arr, int front, int rear, int size) {
	int i;
	
	if(front == rear || front == -1 && rear == -1) {
		printf("Queue is Empty!!");
		return;
	}
	
	for(i=front;i-1!=rear;i=(i+1)%size) 
		printf("%d ",arr[i]);
}

void enQueueLL(int x) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	temp->next=NULL;
	
	if(front==NULL & rear==NULL) {
		front=rear=temp;
		return;
	}
		
	rear->next=temp;
	rear=temp;
}

void deQueueLL() {
	struct Node *temp=front;

	if(front==rear) {
		front=rear=NULL;
	}
	else {
		front=temp->next;	
	}
	free(temp);
}

void printLL() {
	struct Node *temp1=front;
	
	if(front == NULL) {
		printf("\nQueue is empty!!\n");
		return;
	}
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}

// int validation
double validNum(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	while (opt1<1)
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
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

// line
void line() { 
	int i;
	printf("\n");
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

