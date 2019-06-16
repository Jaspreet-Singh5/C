#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void search(int, int, int *);
void insert(int *, int *);
void del(int *, int *);
int * getElements(int, int *);
int * getRandomElements(int, int *);
int menu();
void line();
void printAll(int, int *);
char * repeatCheck(char *);

main(){
	char *pos;
	do{
		int *p, opt1=0, opt5=0,n1=0, x, num, i=0, count=0;
		system("cls");
		line();
		printf(" Program to insert, delete or search an element in an array\n");
		line();
		
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
		else
			p = getRandomElements(n1, p);
		
		printf("\n");	
		for(i=0;i<n1;i++)
			printf("%d ",p[i]);
		printf("\n");
		line();
		
		again2:
		opt1 = menu();
		
		switch(opt1)
		{
			// search
			case 1:
					line();
					printf("Enter the element  to be searched: ");
					scanf("%d",&x);
					line();
					
					search(x, n1, p);
					break;
			
			// insert
			case 2:
					
					insert(&n1, p);
						
					break;	
			
			// delete		
			case 3:	
					del(&n1, p);
					break;
			
			default:
					line();
					printf("Wrong input!!\n");
					goto again2;
					line();		
		}
		getch();
		free(p);
		
		line();
		printf("Main menu\n");
		line();
		getch();
		
		pos = repeatCheck(pos);
	}
	while(pos);
	
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
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Search\n");
	printf("2. Insert\n");
	printf("3. Delete\n");
	line();
	printf("Selected option: ");
	scanf("%d",&opt1);
	line();
	printf("\n");
	return opt1;
}

// search
void search(int x,int n1, int *p){
	
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
	
	free(spos);
}

// insert
void insert(int *n1, int *p){
	int opt2, x, i, j, n,num, count=0,flag,flag2;
	char *pos;
	int n11;
	int firstTime=0;
	
	n11 = *n1;
	flag2=0;
		
	do{
		again3:
		flag=0;
		
		
		if(count==0){
			line();
			printf("Enter the element  to be searched: ");
			scanf("%d",&x);
			line();
			count++;	
		}
		
		line();
		printf("Choose the position: \n");
		printf("1. After 2.Before 3. Any\n");
		line();
		printf("Selected position: ");
		scanf("%d",&opt2);
		line();
		
		line();
		printf("Enter the number to be inserted: ");
		scanf("%d",&num);
		line();
		
		// for inserting element after or before	
		if(opt2==1 || opt2==2){
			
			// iterate through each element
			for(i=0;i<n11;i++){
				// if element found
				if(p[i] == x && flag==0){
					n11=n11+1;
					p = (int *)realloc(p, n11*sizeof(int));
					
					flag=1;
					
					// for inserting element after the searched element
					if(opt2==1){
					// swap the elements forward upto the position just next to the searched element
	 				for(j=n11;j>i+1;j--){
						p[j] = p[j-1]; 
					}
						p[i+1] = num; // insert the given element
					}
					
						
					// for inserting element before the searched element
					else if(opt2==2){
					
						for(j=n11;j>=i;j--){
							// swap the searched element forward also 
							p[j] = p[j-1];	
						}
						// insert the given element
						p[i] = num;
						
						break;
					}
					
				}
			}
			
			
		}
		
		// for inserting element at any given position
		else if(opt2==3)
		{
			again4:
			line();
			printf("Enter the position: ");
			scanf("%d",&x);
			line();
			
			if(x<0 || x>n11){
				line();
				printf("Wrong input!!\n");
				goto again4;
				line();
			}
			
			// iterate through each element
			for(i=0;i<n11;i++){
				// if the given element found
				if(i == x){
					n11=n11+1;
					p = (int *)realloc(p, n11*sizeof(int));
					flag=1;
					// swap all the elements forward
					for(j=n11;j>x;j--){
						p[j] = p[j-1]; 
					}
					
					// insert the given element
					p[x] = num;
					break;
				}
			}
			
		}
		
		else{
			line();
			printf("Wrong input!!\n");
			goto again3;
			line();
		}
		
		if(flag==0){
			line();
			printf("Element not found!\n");
			line();
		}
		
		printAll(n11, p);
		getch();
		
		pos = repeatCheck(pos);
		system("cls");
	}
	while(pos);
}

// delete
void del(int *n1, int *p){
	int opt2, x, i, j, k, n,num, count=0,flag,flag2,min,max;
	char *pos;
	int n11;
	int firstTime=0;
	
	n11 = *n1;
	flag2=0;
		
	do{
		again8:
		flag=0;
		
		line();
		printf("Choose any one of the following options: \n");
		printf("1. First 2.Last 3. Any 4. Duplicate elements 5. Within a given range\n");
		line();
		printf("Selected option: ");
		scanf("%d",&opt2);
		line();
		
		// for deleting first element	
		if(opt2==1){
			--n11;
			// swap all the elements backward
			for(j=0;j<n11;j++){
				p[j] = p[j+1]; 
			}
			p = (int *)realloc(p,n11*sizeof(int));
		}
		
		// for deleting first element	
		else if(opt2==2){
			--n11;
			p = (int *)realloc(p,n11*sizeof(int));
		}		
		
		// for deleting element at any given position
		else if(opt2==3)
		{
			again9:
			line();
			printf("Enter any position: ");
			scanf("%d",&x);
			line();
			
			if(x<0 || x>=n11){
				line();
				printf("Wrong input!!\n");
				goto again9;
				line();
			}
			// iterate through each element 
			for(i=0;i<n11;i++){
				// if element found
				if(i == x){
					flag=1;
					--n11;
					// swap all the elements backward
					for(j=i;j<n11;j++){
						p[j] = p[j+1]; 
					}
					p=(int *)realloc(p,n11*sizeof(int));
					break;
				}
			}
				
			
			if(flag==0){
				line();
				printf("Element not found!\n");
				line();
			}		
		}
		
		else if(opt2==4){
			
			// iterate through each element
			for(i=0;i<n11;i++){
				// iterate through all the elements after it
				for(j=i+1;j<n11;j++){
					if(p[j] == p[i]){
						--n11;
						// swap all the elements backward
						for(k=j;k<n11;k++){
							p[k] = p[k+1]; 
						}
						p=(int *)realloc(p,n11*sizeof(int));
					}
				}
			}
		}
		
		// for deleting elements within a given range
		else if(opt2==5)
		{
			again11:
			line();
			printf("Enter the min. position: ");
			scanf("%d",&min);
			line();
			
			line();
			printf("Enter the max. position: ");
			scanf("%d",&max);
			line();
			
			if(min<0 || min>=n11 || max<0 || max>=n11 || min>max){
				line();
				printf("Wrong input!!\n");
				goto again11;
				line();
			}
			
			// iterate through each element 
			for(i=min;i<=max;i++){
				--n11;
				// swap all the elements backward
				for(j=min;j<n11;j++){
					p[j] = p[j+1]; 
				}
				p=(int *)realloc(p,n11*sizeof(int));
			}
		}
		
		else{
			line();
			printf("Wrong input!!\n");
			goto again8;
			line();
		}
		
		printAll(n11, p);
		
		getch();	
		
		pos = repeatCheck(pos);
		system("cls");
	}
	while(pos);
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
	printf("---------------------------------------------------\n");
	printf("Do you want to continue? ");
	gets(flag);
	printf("---------------------------------------------------");
	
	pos = strchr(strupr(flag), 'Y');
	return pos;
}
