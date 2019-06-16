// Program to implement selectiono sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * getElements(int, int *);
char ** getNames(int, char **);
int * getRandomElements(int, int *);
double menu();
void line();
void printAll(int, int *);
void printNames(int, char **);
void print(int, int *);
int * quickSort(int *, int, int);
char ** quickSortString(char **, int, int);
int partition(int *, int, int);
int partitionString(char **, int, int);
int randomizedPartition(int *, int, int);
int randomizedPartitionString(char **, int, int);
void swap(int *a, int *b);
void printQuick(int, int, int *);
void printQuickString(int, int, char **);


main(){
	
	int *p, opt1, n1, flag[4]={0,0,0,0};
	int opt2, times=0;
	char **names;
	
	line();
	printf(" Program to implement quick sort\n");
	line();
	
	do{		
		opt2=(int) menu();
	
		switch(opt2){
			// read integer input
			case 1:
					do{
						printf("Enter the number of elements: ");
						scanf("%d",&n1);
						line();
						
						// validation
						if(n1 <= 0){
							printf("Number of elements can not be zero or less than zero\n");
							line();
						}
					}
					while(n1<=0);
					
					do{
						line();
						printf("Choose one of the following options\n");
						line();
						printf("1.Manual input 2.Random input\n");
						line();
						printf("Selected option: ");
						scanf("%d", &opt1);
						line();
						
						if(opt1==1){
							p = getElements(n1, p);
							printAll(n1,p);	
						}
							
						else if(opt1==2){
								p = getRandomElements(n1, p);
								printAll(n1,p);
						}
						
						else{
							line();
							printf("Wrong input!\n");
							line();
						}
					}
					while(opt1!=1 && opt1!=2);
					
					flag[0]=1;
					flag[1]=0;
			break;	
			
			// read names
			case 2:
					do{
						printf("Enter the number of names: ");
						scanf("%d",&n1);
						line();
						
						// validation
						if(n1 <= 0){
							printf("Number of elements can not be zero or less than zero\n");
							line();
						}
					}
					while(n1<=0);
					
					names = getNames(n1, names);
					printNames(n1, names);
					
					flag[2]=1;
					flag[3]=0;
			break;
			
			// quick sort for int
			case 3:
				if(flag[0]){
					printAll(n1,p);
					p=quickSort(p, 0, n1-1);
					printAll(n1,p);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// quick sort for string
			case 4:
				if(flag[2]){
					names=quickSortString(names, 0, n1-1);
					printNames(n1,names);
					flag[3]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			case 5:
				line();
				printf("Exiting out of the program \n");
				exit(1);
				line();
			break;
			
			default:
				line();
				printf("Wrong input!\n");
				line();
			break;	
		}
	}
	while(opt2!=5);
}

// get elements
int * getElements(int n1, int *p){
	
	int i,j;
	
	p = (int *)calloc(n1, sizeof(int));
	
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(0);
	}
	
	for(i=0;i<n1;i++){
		again6:
		printf("Enter the element p[%d]: ",i);
		scanf("%d",p+i);
	}
	line();
	return p;
}

// get names
char ** getNames(int n1, char **names){
	
	int i;
	
	names=(char **)calloc(n1,sizeof(char *));
	
	if(names==NULL)
		exit(0);
	
	for(i=0;i<n1;i++){
		*(names+i)=(char *)calloc(50,sizeof(char));
	}
	
	// validation for pointer
	if(names == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(0);
	}
	
	for(i=0;i<n1;i++){
		fflush(stdin);
		printf("Enter the name%d: ",i+1);
		gets(names[i]);
	}
	line();
	return names;
}

// get random elements
int * getRandomElements(int n1, int *p){
	
	int i,min,max,randNum;
	p = (int *)calloc(n1, sizeof(int));
	
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(0);
	}
	again12:
	line();
	printf("Enter the min. value: ");
	scanf("%d",&min);
	line();
	
	line();
	printf("Enter the max. value: ");
	scanf("%d",&max);
	line();
	
	if(min>max){
		line();
		printf("Wrong input!!\n");
		goto again12;
		line();
	}
	
	srand(time(0));
	for(i=0;i<n1;i++){
		again6:
		randNum = rand() % (max-min+1) + min;
		p[i] = randNum;	
	}
	
	return p;
}

//menu
double menu(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Read and display the input (int)\n");
	printf("2. Read and display the input (string)\n");
	printf("3. Display array elements after each iteration of quick sort\n");
	printf("4. Sort array of N names in alphabetical order using quick sort with intermediate output\n");
	printf("5. Exit\n");
	line();
	again1:
	printf("Selected option: ");
	while (opt1 < 1 || opt1>5)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
        
			if (n != 1) // if badc captured an extraneous char
            {	
            	printf("Error! Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 0)
                printf("Error! Please enter a POSITIVE number: ");
            
	    	else if(opt1>6){
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

void swap(int *a, int *b){
	int tempSwap;
	
	tempSwap=*a;
	*a=*b;
	*b=tempSwap;
}

// randomized partition
int randomizedPartition(int *temp, int start, int end){
	int pIndex, tempSwap;
	
	srand(time(0));
	pIndex=rand() % (end-start+1) + start;
	
	printf("\nSwap:	");
	printf("a = %d\tb = %d\n",temp[pIndex],temp[end]);		
	swap(&temp[pIndex],&temp[end]);
	
	partition(temp,start,end);
}

// randomized partition for string
int randomizedPartitionString(char **temp, int start, int end){
	int pIndex;
	char tempSwap[50];
	
	srand(time(0));
	pIndex=rand() % (end-start+1) + start;
	
	printf("\nSwap:	");
	printf("a = %s\tb = %s\n",temp[pIndex],temp[end]);		
	strcpy(tempSwap,temp[pIndex]);
	strcpy(temp[pIndex],temp[end]);
	strcpy(temp[end],tempSwap);
	
	partitionString(temp,start,end);
}

// partition
int partition(int *temp, int start, int end){
	int pivot, pIndex, i, tempSwap;
	
	pivot=temp[end];
	pIndex=start;
	
	for(i=start; i<end; i++){
		if(temp[i]<=pivot){
			
			printf("\npivot: %d, pIndex: %d\n",pivot,pIndex);
			printQuick(start,end,temp);
			swap(&temp[i],&temp[pIndex]);
			
			++pIndex;
		}
	}
	
	swap(&temp[pIndex],&temp[end]);

	return pIndex;
}

// partition for string
int partitionString(char **temp, int start, int end){
	char tempSwap[50];
	int pIndex, i;
	char pivot;
	int j=0;
	
	pivot=temp[end][0];
	pIndex=start;
	
	for(i=start; i<end; i++){
		if(temp[i][0]<pivot){
			printf("\npivot: %c, pIndex: %d\n",pivot,pIndex);
			printQuickString(start,end,temp);
			
			strcpy(tempSwap,temp[i]);
			strcpy(temp[i],temp[pIndex]);
			strcpy(temp[pIndex],tempSwap);
			
			++pIndex;
		}
	}
	
	strcpy(tempSwap,temp[pIndex]);
	strcpy(temp[pIndex],temp[end]);
	strcpy(temp[end],tempSwap);
	
	return pIndex;
}

// quick sort
int * quickSort(int *p, int start, int end){
	int i, j, pIndex;
	
	if(start<end){
		printf("\nStart: %d, End: %d\n",start,end);
		printQuick(start,end,p);
		pIndex=randomizedPartition(p,start,end);
		quickSort(p,start,pIndex-1);
		quickSort(p,pIndex+1,end);
	}
	
	return p;
}

// quick sort for string
char ** quickSortString(char **p, int start, int end){
	int i, j, pIndex;
	
	if(start<end){
		printf("\nStart: %d, End: %d\n",start,end);
		printQuickString(start,end,p);
		
		pIndex=randomizedPartitionString(p,start,end);
		quickSortString(p,start,pIndex-1);
		quickSortString(p,pIndex+1,end);
	}
	
	return p;
}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

// to print all elements
void printAll(int n, int *p){
	int i;
	line();
	// print all the elements		
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	line();
}

// to print all names
void printNames(int n, char **names){
	int i;
	line();
	// print all the elements		
	for(i=0;i<n;i++){
		printf("%s ",names[i]);
	}
	printf("\n");
	line();
}

// to print elements
void print(int n, int *p){
	int i;
	printf("\n");
	// print all the elements		
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}

// to print all elements during quick sort
void printQuick(int start, int end, int *p){
	int i;
	line();
	// print all the elements		
	for(i=start;i<end+1;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	line();
}

// to print all elements during quick sort of string
void printQuickString(int start, int end, char **p){
	int i;
	line();
	// print all the elements		
	for(i=start;i<end+1;i++){
		printf("%s ",p[i]);
	}
	printf("\n");
	line();
}



