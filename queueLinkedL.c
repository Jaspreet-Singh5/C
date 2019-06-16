#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void enQueue(int);
void print();
void deQueue();
int getFront();

struct Node *front=NULL;
struct Node *rear=NULL;

main() {
	enQueue(2);
	enQueue(4);
	enQueue(6);
	enQueue(8);
	print();

	printf("\n");
	deQueue();
	print();
	
	printf("\n");
	printf("%d",getFront());
	
	printf("\n");
	deQueue();
	print();
	
	printf("\n");
	printf("%d",getFront());	
}

void enQueue(int x) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	temp->next=NULL;
	
	if(front==NULL & rear==NULL) {
		front=rear=temp;
		return;
	}
		
	rear->next=temp;
	rear=temp;
}

void deQueue() {
	struct Node *temp=front;
		
	if(front == NULL) {
		printf("\nQueue is empty!!\n");
		return;
	}
	
	if(front==rear) {
		front=rear=NULL;
	}
	else {
		front=temp->next;	
	}
	free(temp);
}

int getFront() {
	return front->data;
}

void print() {
	struct Node *temp1=front;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}
