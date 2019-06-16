#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void line();
double menu(int);
double validNum();
void fifo(int [], int);
void swap(int *x, int *y);
void sstf(int [], int);
void scan(int [], int, int, int, int, int);
int scanA(int q[], int n, int head, int totaln, int diff, int total);
void cscan(int [], int, int, int, int, int);

int main() {
	int *q, n, i, opt=0, head;
	
	line();
	printf("Program to implement various disk scheduling algorithms");
	line();
		
	while(1) {
		opt=(int)menu(opt);
		
		if(opt!=5) {
			line();
			printf("Enter the number of total number of tracks to be traversed: ");
			n=(int)validNum();
		
			q=(int *)calloc(n,sizeof(int));
			
			for(i=0;i<n;i++) {
				line();
				printf("Track no.%d seek time: ",i+1);
				q[i]=(int)validNum();
			}	
		}
		
		switch(opt) {
			case 1:
				fifo(q,n);
			break;
			
			case 2:
				sstf(q,n);
			break;
			
			case 3:
				line();
				printf("Enter the initial position of head: ");
				head=(int)validNum();

				scan(q,n,head,n,0,0);
			break;
			
			case 4:
				line();
				printf("Enter the initial position of head: ");
				head=(int)validNum();
			
				cscan(q,n,head,n,0,0);
			break;
			
			case 5:
				exit(0);
			break;
		}
	}

	return 0;
}

// main menu
double menu(int opt2) {
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf(" Choose one of the following options");
	line();
	printf("1. FIFO\n");
	printf("2. SSTF\n");
	printf("3. SCAN\n");
	printf("4. CSCAN\n");
	printf("5. Exit\n");
	line();
	if(!(0)){
		printf("Selected option: ");	
	}
	while (opt1 < 1 || opt1>5)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	if(0){
					printf("Selected option: ");
				}
				else
					printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 1)
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


void fifo(int q[], int n) {
	int i, diff=0, total=0;
	
	for(i=1;i<n;i++) {
		diff=abs(q[i]-q[i-1]);
		total += diff;	
	}
	
	line();
	for(i=0;i<n;i++) {
		printf("%d ",q[i]);	
	}
	line();

	line();
	printf("Total seek time: %d\n",total);
	printf("Avg. seek time: %.2lf",(float)total/(float)n);
	line();
} 

void sstf(int q[], int n) {
	int i, diff=0, total=0;
	int min, j;

	for(i=0;i<n-1;i++) {
		min=i;

		for(j=i+1;j<n;j++) {
			if(q[j]<q[min])
				min=j;		
		}

		swap(&q[i],&q[min]);	
	}
	
	for(i=1;i<n;i++) {
		diff = abs(q[i]-q[i-1]);
		total += diff; 	
	}
	
	line();
	for(i=0;i<n;i++) {
		printf("%d ",q[i]);	
	}
	line();

	line();
	printf("Total seek time: %d\n",total);
	printf("Avg. seek time: %.2lf",(float)total/(float)n);
	line();
} 

void scan(int q[], int n, int head, int totaln, int diff, int total) {
	int i;
	int min, j, max, queue[n+3], pos;
	
	char flag;

	queue[0]=head;	
	
	for(i=0;i<n-1;i++) {
		max=i;

		for(j=i+1;j<n;j++) {
			if(q[j]>q[max])
				max=j;		
		}

		swap(&q[i],&q[max]);	
	}

	for(i=0,j=1;i<n;i++) {
		if(q[i]<=head) {
			if(j==1)
				pos=i;
			queue[j]=q[i];
			j++;
		}
	}

	queue[j]=0;
	for(i=pos-1,j=++j;i>=0;i--,j++) {
		queue[j]=q[i];
	}
	queue[j]=999;
	
	for(i=1;i<n+3;i++) {
		diff = abs(queue[i]-queue[i-1]);
		total += diff; 	
	}
	
	line();
	for(i=0;i<n;i++) {
		printf("%d ",q[i]);	
	}
	line();	

	line();
	for(i=0;i<n+3;i++) {
		printf("%d ",queue[i]);	
	}
	line();
	
	line();
	printf("Are there any new locations?(Y/N) ");
	scanf("\n");
	scanf("%c",&flag);
	line();
		
	if(flag=='Y') {
		line();
		printf("Enter the number of total number of tracks to be traversed: ");
		scanf("%d",&n);
		line();
		
		free(q);
		q=(int *)calloc(n,sizeof(int));
		
		for(i=0;i<n;i++) {
			line();
			printf("Track no.%d seek time: ",i+1);
			scanf("%d",&q[i]);
			line();
		}
		
		totaln+=n;
		
		total=scanA(q,n,head,totaln,diff,total);
	}	
	
	
	line();
	printf("Total seek time: %d\n",total);
	printf("Avg. seek time: %.2lf",(float)total/(float)totaln);
	line();
} 

int scanA(int q[], int n, int head, int totaln, int diff, int total) {
	int i;
	int min, j, max, queue[n+3], pos;
	
	char flag;

	queue[0]=999;	
	
	for(i=0;i<n-1;i++) {
		max=i;

		for(j=i+1;j<n;j++) {
			if(q[j]>q[max])
				max=j;		
		}

		swap(&q[i],&q[max]);	
	}

	for(i=0,j=1;i<n;i++) {
		if(q[i]>head) {
			queue[j]=q[i];
			j++;
		}
		else {
			pos=i;
			break;
		}
	}

	queue[j]=0;
	for(i=n,j=j;i>=pos;i--,j++) {
		queue[j]=q[i];
	}
	queue[j]=head;
	
	for(i=1;i<n+3;i++) {
		diff = abs(queue[i]-queue[i-1]);
		total += diff; 	
	}
	
	line();
	for(i=0;i<n;i++) {
		printf("%d ",q[i]);	
	}
	line();	

	line();
	for(i=0;i<n+3;i++) {
		printf("%d ",queue[i]);	
	}
	line();
	
	line();
	printf("Are there any new locations?(Y/N) ");
	scanf("\n");
	scanf("%c",&flag);
	line();
	
	if(flag=='Y') {
		line();
		printf("Enter the number of total number of tracks to be traversed: ");
		scanf("%d",&n);
		line();
		
		free(q);
		q=(int *)calloc(n,sizeof(int));
		
		for(i=0;i<n;i++) {
			line();
			printf("Track no.%d seek time: ",i+1);
			scanf("%d",&q[i]);
			line();
		}
		
		totaln+=n;
		
		total=scanA(q,n,head,totaln,diff,total);
	}
	
	return total;
}

void cscan(int q[], int n, int head, int totaln, int diff, int total) {
	int i;
	int min, j, max, queue[n+3], pos;
	
	char flag;

	queue[0]=head;	
	
	for(i=0;i<n-1;i++) {
		max=i;

		for(j=i+1;j<n;j++) {
			if(q[j]>q[max])
				max=j;		
		}

		swap(&q[i],&q[max]);	
	}

	for(i=0,j=1;i<n;i++) {
		if(q[i]<=head) {
			if(j==1)
				pos=i;
			queue[j]=q[i];
			j++;
		}
	}

	queue[j]=0;
	for(i=pos-1,j=++j;i>=0;i--,j++) {
		queue[j]=q[i];
	}
	queue[j]=999;
	
	for(i=1;i<n+3;i++) {
		diff = abs(queue[i]-queue[i-1]);
		total += diff; 	
	}
	
	line();
	for(i=0;i<n;i++) {
		printf("%d ",q[i]);	
	}
	line();	

	line();
	for(i=0;i<n+3;i++) {
		printf("%d ",queue[i]);	
	}
	line();
	
	line();
	printf("Are there any new locations?(Y/N) ");
	scanf("\n");
	scanf("%c",&flag);
	line();
		
	if(flag=='Y') {
		line();
		printf("Enter the number of total number of tracks to be traversed: ");
		scanf("%d",&n);
		line();
		
		free(q);
		q=(int *)calloc(n,sizeof(int));
		
		for(i=0;i<n;i++) {
			line();
			printf("Track no.%d seek time: ",i+1);
			scanf("%d",&q[i]);
			line();
		}
		
		totaln+=n;
		
		cscan(q,n,head,totaln,diff,total);
	}	
	
	
	line();
	printf("Total seek time: %d\n",total);
	printf("Avg. seek time: %.2lf",(float)total/(float)totaln);
	line();
} 

// int validation
double validNum(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	while (opt1<1 || opt1>999)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	
				printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 1)
                printf("Error! Please enter a POSITIVE number: ");
            else if (opt1 > 999)
                printf("Error! Please enter a smaller number: ");
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

void line() {
	printf("\n");
	printf("\n======================================================\n");
	printf("\n\n");
}

void swap(int *x, int *y) {
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
}


