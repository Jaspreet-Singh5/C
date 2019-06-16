#include <stdio.h>
#include <stdlib.h>

void search(int, int, int, int **);
//void insert(int num, int n1, int *p);
//void del(int x, int n1, int *p);
int ** getElements2(int, int, int **);
int menu();
void line();
void printAll(int, int, int **);

main(){
	int **p, opt1=0, rows=0, cols=0, x, num, i=0, j=0;
	
	line();
	printf(" Program to insert, delete or search an element in an array\n");
	line();
	
	printf("Enter the number of rows: ");
	scanf("%d",&rows);
	printf("Enter the number of cols: ");
	scanf("%d",&cols);
	line();
	// validation
	if(rows <= 0 || cols <= 0){
		printf("Number of elements can not be zero or less than zero\nExiting the program");
		exit(1);
	}
		
	p = getElements2(rows, cols, p);
	
	printAll(rows, cols, p);
	
	opt1 = menu();
	
	switch(opt1)
	{
		// search
		case 1:
				line();
				printf("Enter the element  to be searched: ");
				scanf("%d",&x);
				line();
				
				search(x, rows, cols, p);
				break;
//		
//		// insert
//		case 2:
//				line();
//				printf("Enter the number to be inserted: ");
//				scanf("%d",&num);
//				line();
//				
//				insert(num, n1, p);
//				break;	
//		
//		// delete		
//		case 3:	
//				line();
//				printf("Enter the element  to be deleted: ");
//				scanf("%d",&x);
//				line();
//				
//				del(x, n1, p);
//				break;
//		
//		default:
//				line();
//				printf("Wrong input!!\nExiting the program");
//				exit(1);
//				line();		
	}
//	
	free(p);
}

// get elements
int ** getElements2(int rows, int cols, int **p){
	
	int i,j;
	
	p = (int **)calloc(rows, sizeof(int));
	
	for(i=0;i<rows;i++){
		*(p+i) = (int *)calloc(cols, sizeof(int));	
	}
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(0);
	}
	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("Enter the element p[%d][%d]: ",i,j);
			scanf("%d",(*(p+i)+j));	
		}
	}
	line();
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
void search(int x,int rows, int cols, int *p){
	
	int i, j, flag=0, countRow=0, k; countCol=0, **spos, n2=2;
	
	// iterete through each element
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			// if the searched element is found
			if(p[i][j] == x){
				// set the flag 
				flag=1;
				
				// for the first element position
				if(count==0){
					// allocate the space
					spos = (int **)calloc(1, sizeof(int));
					for(k=0; k)
					// assign the row value
					*(spos+count) = i;
					*(spos+count) = i;
					// validation for pointer
					if(spos == NULL){
						line();
						printf("Unable to allocate the space\nExiting the program");
						exit(1);
						line();
					}
					
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
						exit(1);
						line();
					}
					
					n2++;
					*(spos+count) = i;
					count++;
				}
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
		printf("No element found!");
		exit(1);
		line();
	}
	
	free(spos);
}

//// insert
//void insert(int num, int n1, int *p){
//	int opt2, x, i, j;
//	
//	line();
//	printf("Choose the position: \n");
//	printf("1. After 2.Before 3. Any\n");
//	line();
//	printf("Selected position: ");
//	scanf("%d",&opt2);
//	line();
//	
//	// for inserting element after or before	
//	if(opt2==1 || opt2==2){
//		line();
//		printf("Enter the element  to be searched: ");
//		scanf("%d",&x);
//		line();
//		// iterate through each element
//		for(i=0;i<n1;i++){
//			// if element found
//			if(p[i] == x){
//				// swap the elements forward upto the position just next to the searched element
// 				for(j=n1+1;j>i+1;j--){
//					p[j] = p[j-1]; 
//				}
//				
//				// for inserting element after the searched element
//				if(opt2==1)
//					p[i+1] = num; // insert the given element
//					
//				// for inserting element before the searched element
//				else if(opt2==2){
//					// swap the searched element forward also 
//					p[i+1] = p[i];
//					// insert the given element
//					p[i] = num;
//					break;
//				}
//			}
//		}
//	}
//	
//	// for inserting element at any given position
//	else if(opt2==3)
//	{
//		line();
//		printf("Enter the position: ");
//		scanf("%d",&x);
//		line();
//		
//		if(x<=0 || x>=n1){
//			line();
//			printf("Wrong input!!");
//			exit(1);
//			line();
//		}
//		
//		// iterate through each element
//		for(i=0;i<n1;i++){
//			// if the given element found
//			if(i == x){
//				// swap all the elements forward
//				for(j=n1+1;j>x;j--){
//					p[j] = p[j-1]; 
//				}
//				
//				// insert the given element
//				p[x] = num;
//				break;
//			}
//		}
//	}
//	
//	else{
//		line();
//		printf("Wrong input!!");
//		exit(1);
//		line();
//	}
//	
//	printAll(n1+1, p);
//}
//
//// delete
//void del(int x, int n1, int *p){
//	
//	int i, j;
//	// iterate through each element 
//	for(i=0;i<n1;i++){
//		// if element found
//		if(p[i] == x){
//			// swap all the elements backward
//			for(j=i;j<n1-1;j++){
//				p[j] = p[j+1]; 
//			}
//			break;
//		}
//	}
//	
//	printAll(n1-1, p);
//}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

// to print all elements
void printAll(int rows, int cols, int **p){
	int i,j;
	line();
	// print all the elements		
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	line();
}
