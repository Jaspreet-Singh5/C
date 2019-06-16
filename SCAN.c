#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void line();
void swap(int *x, int *y);
void scan(int [], int, int, int, int, int);
int scanA(int q[], int n, int head, int totaln, int diff, int total);

int main() {
	int *q, n, i, head;
	
	line();
	printf("Enter the number of total number of tracks to be traversed: ");
	scanf("%d",&n);
	line();
	
	line();
	printf("Enter the initial position of head: ");
	scanf("%d",&head);
	line();	

	q=(int *)calloc(n,sizeof(int));
	
	for(i=0;i<n;i++) {
		line();
		printf("Track no.%d seek time: ",i+1);
		scanf("%d",&q[i]);
		line();
	}

	scan(q,n,head,n,0,0);
	
	return 0;
}

void swap(int *x, int *y) {
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
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

void line() {
	printf("\n");
	printf("\n======================================================\n");
	printf("\n\n");
}
