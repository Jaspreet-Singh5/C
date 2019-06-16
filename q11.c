#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

double menu(int);
struct Node * insertB(struct Node *, int);
struct Node * insertE(struct Node *, int);
struct Node * insertN(struct Node *, int, int);
int search(struct Node*, int );
void print(struct Node *);
double validNum();
double validVal(int i);
double validValNI();
double validPos();
void line();

main() {
	struct Node *head;
	int opt=0, n, i, x, val;
	int pos;
	head=NULL;
	struct Node *temp1;
	int count=0;
	
	line();
	printf("Program to implement singly linked list creation and insertion");
	line();
	
	while(1) {
		int count=0;
		
		opt=(int)menu(opt);
	
		switch(opt) {
			case 1: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					
					head=insertB(head,x);
				}
				print(head);
			break;
			
			case 2: 
				n=(int)validNum();
				line();
								
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					
					head=insertE(head,x);
				}
				print(head);
			break;
			
			case 3: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					pos=(int)validPos();
					
					count=0;
					temp1=head;
					while(temp1 != NULL) {  
						count++;
						temp1 = temp1->next;
					}
					
					if(pos <= 0 || pos > count && !(pos == count+1)) {
						line();
						printf("Position is out of range");
						line();
					}
					if(pos <= 0 || pos > count && !(pos == count+1))
						continue;
						
					head=insertN(head,x,pos);
				}
				print(head);
			break;
			
			case 4: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					val=(int)validValNI();
					
					int pos = search(head,val);
					
					if(pos != -1)
						insertN(head,x,pos+2);
						
					else {
						line();
						printf("Value not found");
						line();
					}
				}
				print(head);
			break;
			
			case 5: 
				exit(1);
			break;
			
			default:
				line();
				printf("Wrong input!!");
				line();
		}
	}	
}

// main menu
double menu(int opt2){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf("\n\n");
	line();
	printf(" Choose one of the following options");
	line();
	printf("1. Insert a node at the begnning\n");
	printf("2. Insert a node at the end\n");
	printf("3. Insert a node at the nth position\n");
	printf("4. Insert a node after a given value\n");
	printf("5. Exit\n");
	line();
	if(!(opt2==1||opt2==3||opt2==4)){
		printf("Selected option: ");	
	}
	while (opt1 < 1 || opt1>5)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	if(opt2==1||opt2==3||opt2==4){
					printf("Selected option: ");
				}
				else
					printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 0)
                printf("Error! Please enter a POSITIVE number: ");
            
	    	else if(opt1>5){
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
    
	line();	
	printf("Enter the number of nodes you want to insert: ");
	
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


// int validation
double validVal(int i){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	line();	
	printf("Enter the value of node no.%d: ",i+1);
	
	while (opt1==-1)
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
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

// int validation
double validValNI(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	line();	
	printf("Enter the value of node after which you want to insert: ");
	
	while (opt1==-1)
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
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

// int validation
double validPos(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	line();	
	printf("Enter the position where you want insert node: ");
	
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

struct Node * insertB(struct Node *head, int x) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	temp->next=head;
	head=temp;
	
	return head;
}

struct Node * insertE(struct Node *head, int x) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	
	if(head==NULL) {
		temp->next=head;
		head=temp;
		
		return head;
	}
	
	struct Node *temp1=head;
	
	while(temp1->next != NULL) {     // to get the current end node
		temp1 = temp1->next;
	}
	
	temp1->next=temp;
	temp->next=NULL;
	
	return head;
}
struct Node * insertN(struct Node *head, int x, int n) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	
	if(n==1) {
		temp->next=head;
		head=temp;
		
		return head;	
	}
	
	int i;
	struct Node *temp1=head;
	for(i=0;i<n-2;i++) { // to get (n-1)th node
		temp1=temp1->next;
	}
		
	struct Node *temp2=temp1->next; // nth node
	temp1->next=temp;
	temp->next=temp2;
	
	return head;
}



/* Checks whether the value x is present in linked list */
int search(struct Node* head, int x) 
{ 
	int pos=0;
	
    struct Node *temp = head;  
    while (temp != NULL) 
    { 
        if (temp->data == x) 
            return pos; 
        
		++pos;
		temp = temp->next;		 
    } 
    return -1; 
} 

void print(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}

// line
void line(){
	int i;
	printf("\n");
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}
