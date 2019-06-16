#include <stdio.h>
#include <stdlib.h>

struct Node {
	int eVertex;
	struct Node *next;
};

void DFS(int, int *, struct Node **);
void line();
void print(struct Node *);

int main() {
	int n1, n2, i, sVertex, eVertex, *visited;
	struct Node **v;
	
	// 1. get the number of vertices
	printf("Enter the number of vertices: ");
	scanf("%d", &n1);
	
 	// 2. create a dynamic array for n1 vertices
	v=(struct Node **)malloc(n1 * sizeof(struct Node *));
	// Set the value of each head to null
	for(i = 0; i < n1; i++)
		v[i] = NULL;
	
	// 3. get the number of edges
	printf("Enter the number of edges: ");
	scanf("%d", &n2);
	
	// 4. Make connections in the graph
	for(i = 0; i < n2; i++) {
		printf("Enter the value of vertices for edge no.%d: ",i+1);
		scanf("%d",&sVertex);
		scanf("%d",&eVertex);
		
		// 1. Allocate space for an edge
		struct Node *edge;
		edge = (struct Node *)malloc(sizeof(struct Node));
		
		// 2. Set the value of end vertex
		edge->eVertex = eVertex;
		
		// 3. Set the value of next variable of edge
		edge->next = NULL;
		
		if (v[sVertex - 1] == NULL) {
			v[sVertex - 1] = edge;
			continue;
		}
		
		// 4. Declare a variable to store the value of first node of resp. vertex
		struct Node *temp1 = v[sVertex - 1];
		
		// 5. Get the current node
		while(temp1->next != NULL)
			temp1 = temp1->next;
		
		// 6. Set the value of current end node 
		temp1->next = edge;
	}
	
	for(i = 0; i < n1; i++) {
		line();
		printf("\nVertex no. %d: ",i+1);
		print(v[i]);
		printf("\n");
	}
	
	// Allocate memory for an array to track visited items
	visited = (int *)calloc(n1, sizeof(int));
	
	DFS(1,visited,v);
	return 0;
}

// =====================
// DFS Traversal
// =====================

void DFS(int i, int *visited, struct Node *v[])
{
    struct Node *p;
   	
	printf("\n%d",i);
    p=v[i-1];
    visited[i-1]=1;
    while(p!=NULL)
    {
      	i=p->eVertex;
       
	   	if(!visited[i-1])
            DFS(i,visited,v);
        p=p->next;
    }
}

void print(struct Node *head) {
	struct Node *temp1=head;
	
	while(temp1 != NULL) {
		printf("%d ",temp1->eVertex);
		
		if(temp1->next != NULL)
			printf("-> ");
		temp1=temp1->next;
	}
}

// line
void line(){
	int i;
	printf("\n");
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}
