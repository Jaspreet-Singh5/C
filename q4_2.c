#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ** allocate(int,int);
int ** getRandom(int,int);
void deallocate2D(int**,int);
void inputValues(int **,int,int);
void printValues(int **,int,int);
void line();
int ** createSparse(int **,int,int,int **,int *);
void search(int **,int,int);
int ** convert(int **,int,int,int,int **);
int ** transpo(int **,int,int **);
char * repeatCheck(char *);


main(){
	int **s, opt1, nRows, nCols, **c, i, j,k=0, count=0, **r, temp , **transpose,x,flag[4];
	
	for(i=0;i<4;i++)
		flag[i]=0;
		
	do{
		system("cls");
		line();
		printf("Choose one of the following options\n");
		line();
		printf("1. Input a matrix\n2. Search\n3. Convert and Print\n4. Transpose\n5. Random input\n6. Exit\n");
		line();
		printf("Selected option: ");
		scanf("%d",&opt1);
		line();
		
		switch(opt1){
			case 1:
					if(flag[0])
						deallocate2D(s,nRows);
					
					if(flag[1])	
						deallocate2D(c,k);
					
					if(flag[2])
						deallocate2D(r,nRows);
					
					if(flag[3])	
						deallocate2D(transpose,3);
					
					do{
						line();
						printf("Enter the number of rows: ");
						scanf("%d",&nRows);
						printf("Enter the number of columns: ");
						scanf("%d",&nCols);
						line();	
						
						if(nRows<=0 || nCols<=0){
							line();
							printf("Wrong input!\n");
							line();
						}
					}
					while(nRows<=0 || nCols<=0);
					
					
					do{
						s=allocate(nRows,nCols);
					
						printf("\n\n");
						
						inputValues(s,nRows,nCols);	
				
						k=0;
						c=createSparse(s,nRows,nCols,c,&k);
						
						if(k>(nRows*nCols)/2){
							line();
							printf("Not a sparse matrix!\n");
							line();
						}
					}
					while(k>(nRows*nCols)/2);
					
					printValues(s,nRows,nCols);
					
			
					flag[0]=1;
					flag[1]=1;
					for(i=2;i<4;i++)
						flag[i]=0;				
					
					
					break;
					
			case 2:
				if(flag[0]){
					printf("Enter the element to searched: ");
					scanf("%d",&x);
					search(c,k,x);	
				}
				else{
					line();
					printf("No matrix found!\n");
					line();
				}
				
				break;
				
			case 3:
				if(flag[0]){
					r= convert(r,nRows,nCols,k,c);	
					printf("\n");
					printValues(r,nRows,nCols);
					printf("\n\n");
					printValues(c,k,3);
					
					flag[2]=1;	
				}
				else{
					line();
					printf("No matrix found!\n");
					line();
				}
				break;
			
			case 4:
				if(flag[1]){
					transpose= transpo(transpose,k,c);
					printValues(transpose,3,k);
					
					flag[3]=1;
				}
				else{
					line();
					printf("No matrix found!\n");
					line();
				}
				break;
				
			case 5:
				if(flag[0])
					deallocate2D(s,nRows);
				
				if(flag[1])	
					deallocate2D(c,k);
				
				if(flag[2])
					deallocate2D(r,nRows);
				
				if(flag[3])	
					deallocate2D(transpose,3);
					
				line();
				printf("Enter the number of rows: ");
				scanf("%d",&nRows);
				printf("Enter the number of columns: ");
				scanf("%d",&nCols);
				line();
				s=getRandom(nRows,nCols);
				
				printf("\n\n");
				
				printValues(s,nRows,nCols);
				
				k=0;
				c=createSparse(s,nRows,nCols,c,&k);
				
				flag[0]=1;
				flag[1]=1;
				for(i=2;i<4;i++)
					flag[i]=0;				
				
				
				break;
								
			case 6:
				exit(0);
				break;	
			default:
				line();
				printf("Wrong input!\n");
				line();
		}
		getch();
		
		
	}
	while(opt1!=6);
		
	deallocate2D(r,nRows);
	deallocate2D(s,nRows);
	deallocate2D(c,k);
	deallocate2D(transpose,3);
}

int ** allocate(int nRows, int nCols){
	
	int i;
	int **p;
	
	p=(int **)calloc(nRows,sizeof(int *));
	
	if(p==NULL)
		exit(0);
	
	for(i=0;i<nRows;i++){
		*(p+i)=(int *)calloc(nCols,sizeof(int));
	}
	
	return p;
}

int ** getRandom(int nRows, int nCols){
	
	int i,n=0;
	int pos[2];
	int **p;
	
	p=(int **)calloc(nRows,sizeof(int *));
	
	if(p==NULL)
		exit(0);
	
	for(i=0;i<nRows;i++){
		*(p+i)=(int *)calloc(nCols,sizeof(int));
	}
	
	srand(time(0));
	
	n = rand() % ( (nRows*nCols)/2 - 1 + 1) + 1; // ( U - l + 1 ) + l;
	
	for(i=0;i<n;){
		pos[0] = rand() % ( (nRows-1) - 0 + 1) + 0; // ( U - l + 1 ) + l
		pos[1] = rand() % ( (nCols-1) - 0 + 1) + 0; // ( U - l + 1 ) + l
		
		if(p[pos[0]][pos[1]] == 0){
			p[pos[0]][pos[1]] = rand() % ( 1000 - 1 + 1) + 1; // ( U - l + 1 ) + l
			i++;	
		}
	}
	
	return p;
}

void inputValues(int **p,int nRows,int nCols){
	int i,j;
	
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			printf("Enter the %d row %d column element: ",i,j);
			scanf("%d",&p[i][j]);
		}
	}	
}

void printValues(int **p,int nRows,int nCols){
	int i,j;
	
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			printf("%6d",p[i][j]);
		}
		printf("\n");
	}	
}

int ** createSparse(int **p, int nRows, int nCols, int **q,int *k){
	int i,j,count=0;
	
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			if(p[i][j]!=0){
				if(count==0){
					q=allocate(1,3);
					count++;
				}
				else{
						q=(int **)realloc(q,(*k+1)*sizeof(int *));
						
						*(q+*k)=(int *)calloc(3,sizeof(int));		
				}
				
				q[*k][0]=i;
				q[*k][1]=j;
				q[*k][2]=p[i][j];
				++*k;
			}
		}
	}
	printf("\n\n");
	 
	return q;
}

// search
void search(int **c,int k,int x){
	int i=0,flag=0;
	
	for(i=0;i<k;i++){
		if(c[i][2] == x){
			line();
			printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
			line();
			flag=1;
			break;
		}
	}
	
	if(flag==0){
		line();
		printf("Element not found.\n");
		line();
	}
}

int ** convert(int **r,int nRows,int nCols,int k,int **c){
	int pos[2],i;
	
	r = allocate(nRows,nCols);
	
	for(i=0;i<k;i++){
		pos[1]=c[i][0];
		pos[2]=c[i][1];
		
		r[pos[1]][pos[2]] = c[i][2];
	}
	
	return r;
}

// to find transpose
int ** transpo(int **transpose,int k,int **c){
	int i,j;
	
	transpose = allocate(3,k); 
	
	for(i=0;i<k;i++){
		for(j=0;j<3;j++){
			transpose[j][i]=c[i][j];
		}
	}
	
	return transpose;
}

//deallocate a 2D array
void deallocate2D(int** arr2D,int rows)
{
    int i;

    for(i=0;i<rows;i++)
    {
        free(arr2D[i]);
    }

    free(arr2D);
}  

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
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
