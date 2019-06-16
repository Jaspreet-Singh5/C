// Program to implement merge sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * getElements(int, int *);
int * getRandomElements(int, int *);
int * allocate(int, int *);
double menu(int);
void line();
void printAll(int, int *);
void print(int, int *);
int * mergeSort(int *, int, int *);
void merge(int *, int *, int *, int, int, int *);
void insertionSort(int, int *, int *, int *);
void selectionSort(int, int *, int *, int *);

main(){
	
	int *p, opt1, n1, flag[4]={0,0,0,0};
	int opt2=0, comp=0, k=0, opt3=0;
	char **names;
	int *bestCase, *avgCase, *worstCase, *compar;
	int i, times, iteration=0;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    double num=-1;
	
	bestCase=allocate(8,bestCase);
	avgCase=allocate(8,avgCase);
	worstCase=allocate(8,worstCase);
	
	for(i=0;i<=7;i++)
		bestCase[i]=i;
		
	*(avgCase+0)=2;
	*(avgCase+1)=4;
	*(avgCase+2)=1;
	*(avgCase+3)=3;
	*(avgCase+4)=0;
	*(avgCase+5)=7;
	*(avgCase+6)=5;
	*(avgCase+7)=6;
	
	worstCase[0]=4;
	worstCase[1]=0;
	worstCase[2]=6;
	worstCase[3]=2;
	worstCase[4]=5;
	worstCase[5]=1;
	worstCase[6]=7;
	worstCase[7]=3;
	
	
	line();
	printf(" Program to implement merge sort\n");
	line();
	
	do{		
		int conCheck=0, numOper=0;
		opt2=(int) menu(opt2);
		num=-1;
		
		switch(opt2){
			// read integer input
			case 1:
					printf("Enter the number of elements: ");
					while (num < 0 || (int) num == 0)
				    {	cp = fgets(input, sizeof(input), stdin);
				        if (cp == input)
				        {
				            n = sscanf(input, "%lf %c", &num, &badc);
				            if (n != 1) // if badc captured an extraneous char
				            {
				                printf("Error! Please enter a number:");
				                num = -1;
				            }
				            else if (num < 0 || (int) num == 0)
				                printf("Error! Please enter a POSITIVE number:");
				        }
				    }
					n1=(int) num;
				
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
					comp=0;
			break;	
			
			// merge sort
			case 2:
				if(flag[0]){
					printf("\nInitial State: \n");
					printAll(n1,p);
					p=mergeSort(p,n1,&comp);
					printf("\nFinal State: \n");
					printAll(n1,p);
					printf("\nTotal number of comparisons: %d\n",comp);
					flag[1]=1;
				}
					
				else{
					line();
					printf("No input found!\n");
					line();	
				}
			break;
			
			case 3:
				do{
					line();
					printf("Choose one of the following options\n");
					line();
					printf("1. Best Case	 2. Average Case		3. Worst Case\n");
					line();
					printf("Selected option: ");
					scanf("%d", &opt3);
					line();
					
					if(opt3==1){
						comp=0;
						line();
						printf("	Best Case \n");
						line();
						printf("\nInitial State: \n");
						printAll(8,bestCase);
						bestCase=mergeSort(bestCase,8,&comp);
						printf("\nFinal State: \n");
						printAll(8,bestCase);
						printf("\nTotal number of comparisons: %d\n",comp);	
					}
						
					else if(opt3==2){
						comp=0;
						line();
						printf("	Average Case \n");
						line();
						printf("\nInitial State: \n");
						printAll(8,avgCase);
						avgCase=mergeSort(avgCase,8,&comp);
						printf("\nFinal State: \n");
						printAll(8,avgCase);
						printf("\nTotal number of comparisons: %d\n",comp);
					}
					
					else if(opt3==3){
						comp=0;
						line();
						printf("	Worst Case \n");
						line();
						printf("\nInitial State: \n");
						printAll(8,worstCase);
						worstCase=mergeSort(worstCase,8,&comp);
						printf("\nFinal State: \n");
						printAll(8,worstCase);
						printf("\nTotal number of comparisons: %d\n",comp);
					}
					
					else{
						line();
						printf("Wrong input!\n");
						line();
					}
				}
				while(opt1!=1 && opt1!=2);
				
			break;
			
			// comparison of selection and insertion sort
			case 4:
				for(i=0,times=100;i<10;i++,times=times+100){
					line();
					printf("For n=%d\n",times);
					line();
					compar = getRandomElements(times, compar);
					
					insertionSort(times,compar,&conCheck,&numOper);
					
					line();
					printf("	Insertion Sort\n");
					line();
					printf("No. of conditions checked: %d\n",conCheck);
					printf("No. of operation performed(shift + insertion): %d\n",numOper);
					line();
					
					selectionSort(times,compar,&conCheck,&numOper);
					
					line();
					printf("	Selection Sort\n");
					line();
					printf("No. of conditions checked: %d\n",conCheck);
					printf("No. of operation performed(swaps): %d\n",numOper);
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
		++iteration;
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
		randNum = rand() % (max-min+1) + min;
		p[i] = randNum;	
	}
	
	return p;
}

// allocate an array
int * allocate(int n1, int *p){
	
	int i,j;
	
	p = (int *)calloc(n1, sizeof(int));
	
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(0);
	}
	
	return p;
}


//menu
double menu(int opt2){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Read and display the input\n");
	printf("2. Display array elements after each iteration of merge sort\n");
	printf("3. Display the performance (comparisons) of merge sort for best case,\n   average case and worst case\n");
	printf("4. Take any two sorting algorithms and run them on random data for \n   n= 100, 200,... , 1000 and compare their running times or performances\n");
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
            {	if((opt2==1||opt2==3||opt2==4)){
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

// merge sort
int * mergeSort(int *p, int n, int *comp){
	
	int mid, *left, *right, i, j;
	
	if(n>1){
		mid=n/2;
		printf("\nMid: %d\n",mid);
		left=allocate(mid,left);
		right=allocate(n-mid,right);
		
		for(i=0;i<mid;i++){
			left[i]=p[i];
		}
		
		for(i=mid;i<n;i++){
			right[i-mid]=p[i];
		}
		
		printf("Left array: \n");
		printAll(mid,left);
		
		printf("Right array: \n");
		printAll(n-mid,right);
		
		mergeSort(left,mid,comp);
		mergeSort(right,n-mid,comp);
		
	merge(left,right,p,mid,n-mid,comp);	 
    }
	
	return p;
}

// merge
void merge(int *l, int *r, int *p, int nL, int nR, int *comp){
	int i=0,j=0,k=0;
	
	while(i<nL && j<nR){
		if(l[i]<=r[j]){
			p[k]=l[i];
			i++;
		}
		else{
			p[k]=r[j];
			j++;
		}
		k++;
		*comp=*comp+1;
	}
	
	while(i<nL){
		p[k]=l[i];
		i++;
		k++;
	}
	
	while(j<nR){
		p[k]=r[j];
		j++;
		k++;
	}
	
	printf("\nMerged Array: \n");
	printAll(k,p);
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
		
		while(hole>0 && temp[hole-1]>value){
			temp[hole]=temp[hole-1];
			--hole;
			
			*conCheck=*conCheck+1;
			*numOper=*numOper+1;
		}
		*conCheck=*conCheck+1;
		temp[hole]=value;
		*numOper=*numOper+1;
	}
}

// selection sort
void selectionSort(int n1, int *p, int *conCheck, int *numOper){
	int i, j, min=0, temp[n1], tempSwap=0;
	
	for(i=0;i<n1;i++){
		temp[i]=p[i];
	}
	
	for(i=0;i<n1-1;i++){
		min=i;
		
		for(j=i+1;j<n1;j++){
			if(temp[j]<temp[min]){
				*conCheck=*conCheck+1;
				min=j;
			}	
		}
		
		tempSwap=temp[min];
		temp[min]=temp[i];
		temp[i]=tempSwap;
		
		*numOper=*numOper+3;
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

// print elements
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


