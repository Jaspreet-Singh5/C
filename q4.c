	#include <stdio.h>
	#include <stdlib.h>
	
	int ** allocate(int,int);
	void inputValues(int **,int,int);
	void printValues(int **,int,int);
	
	main(){
		int **s, nRows, nCols, **c, i, j,k=0, count=0, **r,pos[2], temp , **transpose;
		
		printf("Enter the number of rows: ");
		scanf("%d",&nRows);
		printf("Enter the number of columns: ");
		scanf("%d",&nCols);
		
		s=allocate(nRows,nCols);
		
		inputValues(s,nRows,nCols);
		
		printValues(s,nRows,nCols);
		
		for(i=0;i<nRows;i++){
			for(j=0;j<nCols;j++){
				if(s[i][j]!=0){
					if(count==0){
						c=allocate(1,3);
						count++;
					}
					else{
							c=(int **)realloc(c,(k+1)*sizeof(int));
							
							*(c+k)=(int *)calloc(3,sizeof(int));		
					}
					
					c[k][0]=i;
					c[k][1]=j;
					c[k][2]=s[i][j];
					++k;
				}
			}
		}
		printf("\n\n");
		printValues(c,k,3);
		
		r=allocate(nRows,nCols);
		
		for(i=0;i<k;i++){
			pos[1]=c[i][0];
			pos[2]=c[i][1];
			
			r[pos[1]][pos[2]] = c[i][2];
		}
		
		printf("\n\n");
		printValues(r,nRows,nCols);
		
		
		transpose=allocate(3,k); 
		for(i=0;i<k;i++){
			for(j=0;j<3;j++){
				transpose[j][i]=c[i][j];
			}
		}
		
		printf("\n\n");
		printValues(transpose,3,k);
		free(c);
		free(s);
	}
	
	int ** allocate(int nRows, int nCols){
		
		int i;
		int **p;
		
		p=(int **)calloc(nRows,sizeof(int));
		
		if(p==NULL)
			exit(0);
		
		for(i=0;i<nRows;i++){
			*(p+i)=(int *)calloc(nCols,sizeof(int));
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
