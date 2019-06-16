// Program to implement selection sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int * getElements(int, int *);
int * getRandomElements(int, int *);
double menu();
void line();
void printAll(int, int *);
void print(int, int *);
void selectionSort(int, int *, int *, int *);
void frequency(int, int *);
int * delDuplicate(int *, int *);


main(){
	
	int *p, opt1, n1, conCheck=0, numOper=0, flag[2]={0,0};
	int opt2;
	
	line();
	printf(" Program to implement selection sort\n");
	line();
	
	do{
		opt2=(int) menu();
	
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
			
			// selection sort
			case 2:
				if(flag[0]){
					selectionSort(n1,p,&conCheck,&numOper);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// number of operations performed
			case 3:
				if(flag[0]&&flag[1]){
					line();
					printf("No. of conditions checked: %d\n",conCheck);
					printf("No. of operation performed: %d\n",numOper);
					line();	
				}
				
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// to count the frequency
			case 4:
				if(flag[0]){
					frequency(n1, p);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			// to delete the duplicates
			case 5:
				if(flag[0]){
					p=delDuplicate(&n1, p);
					print(n1,p);
					flag[1]=1;
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
	while(opt2!=6);
	
		
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
	printf("1. Read and display the input\n");
	printf("2. Display array elements after each iteration of selection sort\n");
	printf("3. Calculate the number of condition checks and swaps performed\n");
	printf("4. Frequency of each element after sorting\n");
	printf("5. Display the unique elements by deleting duplicates\n");
	printf("6. Exit\n");
	line();
	again1:
	printf("Selected option: ");
	while (opt1 < 0 || opt1>6)
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

// delete
int * delDuplicate(int *n1, int *p){
	int i, j, k;
	
	// iterate through each element
	for(i=0;i<*n1;i++){
		// iterate through all the elements after it
		for(j=i+1;j<*n1;j++){
			if(p[j] == p[i]){
				--*n1;
				// swap all the elements backward
				for(k=j;k<*n1;k++){
					p[k] = p[k+1]; 
				}
				p=(int *)realloc(p,*n1*sizeof(int));
			}
		}
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

// selection sort
void selectionSort(int n1, int *p, int *conCheck, int *numOper){
	int i, j, min=0, temp[n1], tempSwap=0;
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	printf("Previous state of array: \n");
	print(n1,temp);
	line();
	
	
	for(i=0;i<n1-1;i++){
		min=i;
		
		line();
		printf("Iteration no.%d\n",i+1);
		line();
		
		for(j=i+1;j<n1;j++){
			if(temp[j]<temp[min]){
				*conCheck=*conCheck+1;
				min=j;
			}	
		}
		
		tempSwap=temp[min];
		temp[min]=temp[i];
		temp[i]=tempSwap;
		
		
		
		print(n1,temp);
			
		*numOper=*numOper+1;
		
		printf("\n");
		line();
		printf("\n");
	}
}

// to count the frequency
void frequency(int n1, int *p){
	int count=0, i, j, k;
	
	int min=0, temp[n1], tempSwap=0;
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	printf("Previous state of array: \n");
	print(n1,temp);
	line();
	
	
	for(i=0;i<n1-1;i++){
		min=i;
		
		for(j=i+1;j<n1;j++){
			if(temp[j]<temp[min]){
				min=j;
			}	
		}
		
		tempSwap=temp[min];
		temp[min]=temp[i];
		temp[i]=tempSwap;
		
		
		
		print(n1,temp);
			
		printf("\n");
		line();
		printf("\n");
	}
	
	printf("\n");
	line();
	printf("Frequency of each element after sorting\n");
	printf("Element      =     Frequency\n");
	line();
	
	for(i=0;i<n1;i++){
		count=1;		
		for(j=i+1;j<n1;j++){
			if(temp[i]==temp[j]){
				++count;
				
				n1=n1-1;
				// swap all the elements backward
				for(k=i;k<n1;k++){
					temp[k] = temp[k+1]; 
				}
				
			}			
		}
		printf("%d           =     %d\n",temp[i],count);
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
