#include <stdio.h>
#include <stdlib.h>

struct bstNode {
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

struct queue {
	struct bstNode * data;
	struct queue *next;
};

void line();
void enQueueLL(struct bstNode *);
void printLL();
void deQueueLL();

struct bstNode * insertNode(struct bstNode *, int);
struct bstNode * getNewNode(int);
int search(struct bstNode *, int);
void levelOrderT(struct bstNode *);
void preOrderT(struct bstNode *);
void inOrderT(struct bstNode *);
void postOrderT(struct bstNode *);
struct bstNode * deleteNode(struct bstNode *, int);
struct bstNode * findMin(struct bstNode *);

struct queue *front=NULL;
struct queue *rear=NULL;

int main() {
	struct bstNode *root=NULL;	// to create an empty tree
	
	root=insertNode(root,6);
	root=insertNode(root,8);
	root=insertNode(root,2);
	root=insertNode(root,8);
	root=insertNode(root,3);
	root=insertNode(root,9);
	root=insertNode(root,10);
	root=insertNode(root,1);
	
	line();
	printf("Search result: %d",search(root,10));
	line();
	
	line();
	printf("Level Order traversal: ");
	levelOrderT(root);
	line();
	
	line();
	printf("Preorder traversal: ");
	preOrderT(root);
	line();
	
	line();
	printf("Inorder traversal: ");
	inOrderT(root);
	line();
	
	line();
	printf("Postorder traversal: ");
	postOrderT(root);
	line();
	
	root=deleteNode(root,2);
	
	line();
	printf("Level Order traversal(delete): ");
	levelOrderT(root);
	line();
	
	
	return 0;
}

struct bstNode * getNewNode(int data) {
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	
	newNode->data = data;
	newNode->left=newNode->right=NULL;
	
	return newNode;
}

struct bstNode * insertNode(struct bstNode *root, int data) {
	if(root == NULL) // tree is empty
		root = getNewNode(data);
	
	else if(data <= root->data)
		root->left = insertNode(root->left,data);
		
	else
		root->right = insertNode(root->right,data);
		
	return root;
}

int search(struct bstNode *root, int data) {
	if(root == NULL)
		return 0;
	else if(root->data == data)
		return 1;
	else if(data <= root->data)
		return search(root->left,data);
	else
		return search(root->right,data); 	
}

void enQueueLL(struct bstNode *x) {
	struct queue *temp=(struct queue *)malloc(sizeof(struct queue));
	
	temp->data=x;
	temp->next=NULL;
	
	if(front==NULL & rear==NULL) {
		front=rear=temp;
		return;
	}
		
	rear->next=temp;
	rear=temp;
}

void deQueueLL() {
	struct queue *temp=front;
		
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

void printLL() {
	struct queue *temp1=front;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}

void levelOrderT(struct bstNode *root) {
	if (root == NULL)
		return;
	
	struct queue Q;
	
	enQueueLL(root);
	
	while(! (front == NULL) ) {
		struct bstNode *current = front->data;
		
		printf("%d ",current->data);
		
		if(current->left != NULL)
			enQueueLL(current->left);
		if(current->right != NULL)
			enQueueLL(current->right);
		
		deQueueLL();
	}
}

void preOrderT(struct bstNode *root) {
	if (root == NULL)
		return;
	printf("%d ",root->data);
	preOrderT(root->left);
	preOrderT(root->right);
}

void inOrderT(struct bstNode *root) {
	if (root == NULL)
		return;
	inOrderT(root->left);
	printf("%d ",root->data);
	inOrderT(root->right);
}

void postOrderT(struct bstNode *root) {
	if (root == NULL)
		return;
	postOrderT(root->left);
	postOrderT(root->right);
	printf("%d ",root->data);
}

struct bstNode * deleteNode(struct bstNode *root, int data) {
	if(root == NULL)
		return root;
	else if(data < root->data)
		root->left = deleteNode(root->left,data);
	else if(data > root->data)
		root->right = deleteNode(root->right,data);
	else {
		if(root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
			return root;
		}
		
		else if(root->left == NULL) {
			struct bstNode *temp = root;
			root=root->right;
			free(temp);
		}
		
		else if(root->right == NULL) {
			struct bstNode *temp = root;
			root=root->left;
			free(temp);
		}		
		else {
			struct bstNode *temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	
	return root;
}

struct bstNode * findMin(struct bstNode *root) {
	if(root == NULL) 
		return;
	else if(root->left == NULL)
		return root;
	
	return findMin(root->left);
}

// int validation
double validNum(){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	while (opt1<1)
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
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
}

// line
void line() { 
	int i;
	printf("\n");
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

