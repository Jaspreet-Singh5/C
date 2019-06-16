#include <stdio.h>
#include <stdlib.h>

int isEmpty (int, int);
int * enQueue(int, int *, int *, int *, int *);
void print(int [], int, int,int);
void deQueue(int *, int *, int *,int *);
int * arrCopy(int *,int *, int *, int);

main() {
	int front=-1, rear=-1, *arr,size=50;
	arr=(int *)malloc(size*sizeof(int));
	
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(3,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	
	arr=enQueue(1232,arr,&front,&rear,&size);
	arr=enQueue(5233,arr,&front,&rear,&size);
	arr=enQueue(2346,arr,&front,&rear,&size);
	arr=enQueue(532,arr,&front,&rear,&size);
	arr=enQueue(236,arr,&front,&rear,&size);
	
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(3,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(3,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	arr=enQueue(2,arr,&front,&rear,&size);
	arr=enQueue(6,arr,&front,&rear,&size);
	
	print(arr,front,rear,size);
	
	printf("\n");
	deQueue(arr,&front,&rear,&size);
	print(arr,front,rear,size);
	
	printf("\n");
	printf("Front: %d",arr[front]);
	
	printf("\n");
	deQueue(arr,&front,&rear,&size);
	print(arr,front,rear,size);
	
	printf("\n");
	printf("Front: %d\n",arr[front]);
	
	arr=enQueue(1232,arr,&front,&rear,&size);
	arr=enQueue(5233,arr,&front,&rear,&size);
	arr=enQueue(2346,arr,&front,&rear,&size);
	arr=enQueue(532,arr,&front,&rear,&size);
	arr=enQueue(236,arr,&front,&rear,&size);
	print(arr,front,rear,size);
		
}

int isEmpty(int front, int rear) {
	if(front == -1 && rear == -1)
		return 1;
	else 
		return 0;
}

int * enQueue(int x, int *arr, int *front, int *rear, int *size) {	
	if(isEmpty(*front,*rear)) {
		*front=0;
		*rear=0;
	}
	
	else {
		*rear=(*rear+1)%(*size);
	}
	
	arr[*rear]=x;
	
	return arr;
}

void deQueue(int *arr, int *front, int *rear,int *size) {
	if(isEmpty(*front,*rear)) {
		printf("Queue is Empty!!");
		return;
	}
	else if (*front == *rear)
		*front = *rear = -1;
	
	else
		*front=(*front+1)%(*size);
}       


void print(int *arr, int front, int rear, int size) {
	int i;
	
	for(i=front;i!=rear;i=(i+1)%size) 
		printf("%d ",arr[i]);
}
