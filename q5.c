// Program to implement insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int * getElements(int, int *);
int * getRandomElements(int, int *);
int menu();
void line();
void printAll(int, int *);
void print(int, int *);
void insertionSort(int, int *, int *, int *);
void insertionSortSwap(int, int *, int *, int *);
void insertionSortOdd(int, int *, int *, int *);

main(){
	int *p, opt1, opt2, n1, conCheck=0, numOper=0, flag[2]={0,0};
	
	line();
	printf(" Program to implement insertion sort\n");
	line();
	
	do{
		opt2=menu();
	
		switch(opt2){
			// read input
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
			
			// insertion sort
			case 2:
				if(flag[0]){
					insertionSort(n1,p,&conCheck,&numOper);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// insertion sort using swapping
			case 3:
				if(flag[0]){
					insertionSortSwap(n1,p,&conCheck,&numOper);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// insertion sort in descending order for odd positioned numbers only
			case 4:
				if(flag[0]){
					insertionSortOdd(n1,p,&conCheck,&numOper);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// number of operations performed
			case 5:
				if(flag[0]&&flag[1]){
					line();
					printf("No. of conditions checked: %d\n",conCheck);
					printf("No. of operation performed(shift + insertion in case of shifting and swap in case of swapping): %d\n",numOper);
					line();	
				}
				
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			case 6:
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
	while(opt1!=6);
	
		
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
		printf("Enter the element p[%d]: ",i);
		scanf("%d",p+i);
	}
	line();
	return p;
}

// get random elements
int * getRandomElements(int n1, int *p){
	
	int i,j,min,max,randNum;
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
		
		for(j=0;j<i;j++){
			if(p[i] == p[j]){
				goto again6;
			}
		}
	}
	
	return p;
}

//menu
int menu(){
	int opt1;
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Read and display the input\n");
	printf("2. Display array elements after each iteration of insertion sort(shifting and inserting)\n");
	printf("3. Display array elements after each iteration of insertion sort(swapping)\n");
	printf("4. Display array elements after each iteration of insertion sort(shifting and inserting)(descending order for only positioned numbers)\n");
	printf("5. Calculate the number of condition checks, insertions, shifts and swaps performed\n");
	printf("6. Exit\n");
	line();
	
	do{
		printf("Selected option: ");
		scanf("%d",&opt1);
		line();
		printf("\n");	
		
		if(opt1<1 || opt1>6){
			line();
			printf("Wrong input!\n");
			line();
		}
	}
	while(opt1<1 || opt1>6);
	
	return opt1;
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

// insertion sort shifting and inserting
void insertionSort(int n1, int *p, int *conCheck, int *numOper){
	int i, value, hole, temp[n1];
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	for(i=1;i<n1;i++){
		value=temp[i];
		hole=i;
		
		line();
		printf("Iteration no.%d\n",i);
		line();
		printf("Previous state of array: \n");
		print(n1,temp);
		line();
		
		while(hole>0 && temp[hole-1]>value){
			temp[hole]=temp[hole-1];
			--hole;
			
			print(n1,temp);
			
			*conCheck=*conCheck+1;
			*numOper=*numOper+1;
		}
		*conCheck=*conCheck+1;
		temp[hole]=value;
		*numOper=*numOper+1;
		
		line();
		
		printf("Final state of array: \n");
		print(n1,temp);
		line();
		
		printf("\n");
		line();
		printf("\n");
	}
}

// insertion sort swapping
void insertionSortSwap(int n1, int *p, int *conCheck, int *numOper){
	int i, value, hole, temp[n1], tempSwap;
	
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	for(i=1;i<n1;i++){
		value=temp[i];
		hole=i;
		
		line();
		printf("Iteration no.%d\n",i);
		line();
		printf("Previous state of array: \n");
		print(n1,temp);
		line();
		
		while(hole>0 && temp[hole-1]>value){
			tempSwap=temp[hole];
			temp[hole]=temp[hole-1];
			temp[hole-1]=tempSwap;
			--hole;
			
			print(n1,temp);
			
			*conCheck=*conCheck+1;
			*numOper=*numOper+3;
		}
		*conCheck=*conCheck+1;
		
		line();
		
		printf("Final state of array: \n");
		print(n1,temp);
		line();
		
		printf("\n");
		line();
		printf("\n");
	}
}

// insertion sort shifting and inserting in descending order for only odd positioned numbers
void insertionSortOdd(int n1, int *p, int *conCheck, int *numOper){
	int i, value, hole, temp[n1];
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	for(i=2;i<n1;i=i+2){
		value=temp[i];
		hole=i;
		
		line();
		printf("Iteration no.%d\n",i);
		line();
		printf("Previous state of array: \n");
		print(n1,temp);
		line();
		
		while(hole>0 && temp[hole-2]<value){
			temp[hole]=temp[hole-2];
			hole=hole-2;
			
			print(n1,temp);
			
			*conCheck=*conCheck+1;
			*numOper=*numOper+1;
		}
		*conCheck=*conCheck+1;
		temp[hole]=value;
		*numOper=*numOper+1;
		
		line();
		
		printf("Final state of array: \n");
		print(n1,temp);
		line();
		
		printf("\n");
		line();
		printf("\n");
	}
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
