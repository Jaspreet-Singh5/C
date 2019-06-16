#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node * getNew(int);
struct Node * insertB(struct Node *,int);
void print(struct Node *);
void revPrint(struct Node *);

main() {
	struct Node *head=NULL;
	
	head=insertB(head,2);
	head=insertB(head,5);
	head=insertB(head,7);
	
	print(head);	
	printf("\n");
	revPrint(head);
}

struct Node * getNew(int x) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	newNode->data=x;
	newNode->prev=NULL;
	newNode->next=NULL;
	
	return newNode;
}

struct Node * insertB(struct Node *head,int x) {
	struct Node *newNode=getNew(x);
	
	if(head==NULL) {
		head=newNode;
		return head;
	}
	
	head->prev=newNode;
	newNode->next=head;
	head=newNode;
	
	return head;
}

void revPrint(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1->next != NULL) {
		temp1=temp1->next;
	}
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->prev;
	}
}

void print(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}
