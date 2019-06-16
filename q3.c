#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void linearSearch(int, int, int *);
void linearSearchSentinel(int, int, int *);
void binarySearch(int [],int,int);
int * getElements(int, int *);




int * getRandomElements(int, int *);
int menu();
void line();
void printAll(int, int *);
char * repeatCheck(char *);

main(){
	char *pos;
	int *p, n1=0, opt5=0;
	
	printf("Enter the number of elements: ");
	scanf("%d",&n1);
	line();
	again1:
	// validation
	if(n1 <= 0){
		printf("Number of elements can not be zero or less than zero\n");
		line();
		printf("Enter the number of elements: ");
		scanf("%d",&n1);
		line();
		goto again1;
	}
	again24:
	line();
	printf("Choose one of the following options\n");
	line();
	printf("1.Manual input 2.Random input\n");
	line();
	printf("Selected option: ");
	scanf("%d", &opt5);
	line();
	
	if(opt5==1)
		p = getElements(n1, p);
	else if(opt5==2)
		p = getRandomElements(n1, p);
	else{
		line();
		printf("Wrong input!!\n");
		line();
		goto again24;
	}
	
	do{
		int opt1=0, x, num, i=0, j=0,count=0,temp=0,index=0;
		
		system("cls");
		line();
		printf(" Program to implement linear search, linear search(sentinel) and binary search\n");
		line();
		
		printAll(n1,p);
		
		again2:
		opt1 = menu();
		
		line();
		printf("Enter the element  to be searched: ");
		scanf("%d",&x);
		line();
		
		switch(opt1)
		{
			// linear search
			case 1:
					linearSearch(x, n1, p);
					break;
			
			// linear search(Sentinel)
			case 2:
					linearSearchSentinel(x, n1, p);
					break;
			
			// binary search
			case 3:
					binarySearch(p, n1, x);
					break;
			
			default:
					line();
					printf("Wrong input!!\n");
					goto again2;
					line();		
		}
		
		getch();
	
		pos = repeatCheck(pos);
	}
	while(pos);
	free(p);
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
	again25:
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Linear Search\n");
	printf("2. Linear Search(Sentinel)\n");
	printf("3. Binary Search\n");
	line();
	printf("Selected option: ");
	scanf("%d",&opt1);
	line();
	printf("\n");
	
	if(opt1<1||opt1>3){
		line();
		printf("Wrong input!\n");
		line();
		goto again25;
	}
	return opt1;
}

// linear search
void linearSearch(int x,int n1, int *p){
	
	int i, flag=0, count=0, *spos, n2=2;
	
	// iterete through each element
	for(i=0;i<n1;i++){
		// if the searched element is found
		if(p[i] == x){
			// set the flag 
			flag=1;
			
			// for the first element position
			if(count==0){
				// allocate the space
				spos = (int *)calloc(1, sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to allocate the space\nExiting the program");
					exit(0);
					line();
				}
				// assign the value
				*(spos+count) = i;
				// increase the value of count
				count++;
			}
			
			else{
				// reallocate the space
				spos = (int *)realloc(spos,  n2*sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to reallocate the space\nExiting the program");
					exit(0);
					line();
				}
				
				n2++;
				*(spos+count) = i;
				count++;
			}
		}
	}
	
	// if any element found
	if(flag){
		line();
		printf("Element found!\n");
		printf("Total occurances: %d",count);
		printf("\nPositon no.(s): ");
		for(i=0; i<count; i++)
		{
			printf("%d ",*(spos+i));
		}
		printf("\n");
		line();
	}
	
	else{
		line();
		printf("No element found!\n");
		line();
	}
}

// linear search(Sentinel)
void linearSearchSentinel(int x,int n1, int *p){
	
	int i, count=0, *spos, n2=2;
	
	// iterete through each element
	for(i=0;i<n1;i++){
		// if the searched element is found
		if(p[i] == x){

			// for the first element position
			if(count==0){
				// allocate the space
				spos = (int *)calloc(1, sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to allocate the space\nExiting the program");
					exit(0);
					line();
				}
				// assign the value
				*(spos+count) = i;
				// increase the value of count
				count++;
			}
			
			else{
				// reallocate the space
				spos = (int *)realloc(spos,  n2*sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to reallocate the space\nExiting the program");
					exit(0);
					line();
				}
				
				n2++;
				*(spos+count) = i;
				count++;
			}
		}
	}
	
	// if any element found
	if(count>0){
		line();
		printf("Element found!\n");
		printf("Total occurances: %d",count);
		printf("\nPositon no.(s): ");
		for(i=0; i<count; i++)
		{
			printf("%d ",*(spos+i));
		}
		printf("\n");
		line();
	}
	
	else{
		line();
		printf("No element found!\n");
		line();
	}
	
	free(spos);
}

void binarySearch(int A[],int n,int x){
	int low=0, high=n-1, mid, count=0, *spos,i,j,n2=2;
	 
   	for (i = 0; i < n-1; i++){
   		// Last i elements are already in place    
    	for (j = 0; j < n-i-1; j++){
    		if (A[j] > A[j+1]){
        		 int temp = A[j];  
				  A[j] = A[j+1];
				  A[j+1] = temp;
		   }	
		}  		
	}	
	
	while(low<=high){
		mid=low+(high-low)/2; //to prevent low+high overflow
		if(A[mid]==x){
			count++;
			
			for(i=mid;i>=0;i--){
				if(A[i-1]==A[i])
					count++;
				else 
					break;
			}	
			for(i=mid;i<n;i++){
				if(A[i]==A[i+1])
					count++;
				else
					break;
			}
			break;
		}
		else if(x<A[mid])
			high=mid-1;
		else
			low=mid+1;	
	}	
	
	// if any element found
	if(count>=1){
		line();
		printf("Element found!\n");
		printf("Total occurances: %d",count);
		printf("\n");
		line();
	}
	
	else{
		line();
		printf("No element found!\n");
		line();
	}
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

// repeat
char * repeatCheck(char *pos){
	char flag[10];
	system("cls");
	fflush(stdin);
	line();
	printf("Main Menu\n");
	line();
	printf("---------------------------------------------------\n");
	printf("Do you want to continue? ");
	gets(flag);
	printf("---------------------------------------------------");
	
	pos = strchr(strupr(flag), 'Y');
	return pos;
}
