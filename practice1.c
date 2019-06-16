// Program to create an array (A) of n elements. 
// Generate 3 new arrays (B, C & D) of n elements having different combination of array (A) elements

#include <stdio.h>
#include <stdlib.h>

int * getElements(int n1, int *p);
void line();
void printAll(int n, int *p);
int menu();
int * getRandom(int, int *, int *);

main(){
	int *p, n, i, opt, *q, *r, *s;
	
	line();
	printf("Enter the no. of elements of array A: ");
	scanf("%d",&n);
	line();
	
	p = getElements(n, p);
	
	printAll(n, p);
	
	q = getRandom(n, q, p);
	r = getRandom(n, r, p);
	s = getRandom(n, s, p);
	
	printAll(n, q);
	printAll(n, r);
	printAll(n, s);
	
	free(p);
	free(q);
	free(r);
	free(s);
}

// get elements
int * getElements(int n, int *p){
	
	int i;
	
	p = (int *)calloc(n, sizeof(int));
	
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(1);
	}
	
	for(i=0;i<n;i++){
		printf("Enter the element p[%d]: ",i);
		scanf("%d",p+i);
	}
	line();
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

int * getRandom(int n, int *q, int *p){
	int i, randPos;
	
	q = (int *)calloc(n, sizeof(int));
	
	for(i=0;i<n;i++){
		again:
		randPos = rand() % ( (n-1) - 0 + 1) + 0;
		q[i] = p[randPos];
	}
	
	return q;
}


