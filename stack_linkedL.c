#include <stdio.h>
	#include <stdlib.h>
	
	struct Node {
		int data;
		struct Node *next;
	};
	
	struct Node * push(int,struct Node *);
	void print(struct Node *);
	struct Node * pop(struct Node *);
	int getTop(struct Node *);

main() {
	struct Node *head=NULL;

	head=push(2,head);
	head=push(4,head);
	head=push(6,head);
	head=push(8,head);
	print(head);
	
	printf("\n");
	head=pop(head);
	print(head);
	
	printf("\n");
	printf("%d",getTop(head));
	
	printf("\n");
	head=pop(head);
	print(head);
	
	printf("\n");
	printf("%d",getTop(head));	
}

struct Node * push(int x,struct Node *head) {
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	
	temp->data=x;
	temp->next=head;
	head=temp;
	
	return head;
}

struct Node * pop(struct Node *head) {
	if(head == NULL) {
		printf("\nStack is empty!!\n");
		return;
	}
	struct Node *temp=head;
	head=temp->next;
	free(temp);
	
	return head;
}

int getTop(struct Node *head) {
	return head->data;
}

void print(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}
