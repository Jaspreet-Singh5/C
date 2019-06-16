#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void line();
double menu(int);
double validNum();
struct Node * pushLL(int,struct Node *);
void printLL(struct Node *);
struct Node * popLL(struct Node *);
int getTopLL(struct Node *);
int getCountLL(struct Node *);

void pushArr(int,int *,int *);
void printArr(int *, int *);
void popArr(int *,int *);
int getTopArr(int *,int *);

main() {
	int *arr;
	arr=(int *)calloc(20,sizeof(int));
	int top=-1;
	int opt=0;
	int n,x;
	int i;
		
	struct Node *head=NULL;

	line();
	printf("Program to implement stack using array and linked list");
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
					
					pushArr(x,arr,&top);
				}
				printArr(arr, &top);
			break;	
					
			case 2: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					popArr(arr,&top);
				}
				printArr(arr, &top);
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
					
					head=pushLL(x,head);
				}
				printLL(head);
			break;	
					
			case 4: 
				line();	
				printf("Enter the number of elements: ");
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					head=popLL(head);
				}
				printLL(head);
			break;
			
			case 5:
				printArr(arr, &top);
			break;
			
			case 6:
				printLL(head);
			break;
			
			case 7:
				exit(1);
			break;
		}
	}
	
	free(arr);
	free(head);
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
	printf("1. Push (array)\n");
	printf("2. Pop (array)\n");
	printf("3. Push (linked list)\n");
	printf("4. Pop (linked list)\n");
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
            else if (opt1 < 0)
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

void pushArr(int x,int *arr,int *top) {
	int size = sizeof(arr)/sizeof(arr[0]);
	
	if(*top == size-1) {
		arr=(int *)realloc(arr,2*size);
	}

	arr[++(*top)]=x;
}

void popArr(int *arr,int *top) {
	if(*top == -1) {
		printf("\nStack is empty!!\n");
		return;
	}
	--(*top);
}

int getTopArr(int *arr, int *top) {
	return arr[*top];
}

void printArr(int *arr, int *top) {
	int i;
	
	for(i=0;i<=*top;i++) {
		printf("%d ",arr[i]);
	}
}

struct Node * pushLL(int x,struct Node *head) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	temp->next=head;
	head=temp;
	
	return head;
}

struct Node * popLL(struct Node *head) {
	if(head == NULL) {
		printf("\nStack is empty!!\n");
		return;
	}
	struct Node *temp=head;
	head=temp->next;
	free(temp);
	
	return head;
}

int getTopLL(struct Node *head) {
	return head->data;
}

void printLL(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}

int getCountLL(struct Node *head) {
	struct Node *temp1=head;
	int count=0;
	
	while(temp1 != NULL) {  
		count++;
		temp1 = temp1->next;
	}	
	
	return count;
}

// int validation
double validNum(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	while (opt1<=0)
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
            else if (opt1 <= 0)
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

