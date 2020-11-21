#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTEX 8
#define TRUE 1
#define FALSE 0

typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
}node;

typedef struct {
	int count;
	nodePointer link;
}head;
head graph[MAX_VERTEX];

void topSort(head graph[], int n) {
	int i, j, k, top;
	nodePointer ptr;
	top = -1;

	for (i = 0; i < n; i++) {
		if (!graph[i].count) {
			graph[i].count = top;
			top = i;
		}
	}

	for (i = 0; i < n; i++) {
		
		if (top == -1) {
			printf("Network has a cycle\n");
			exit(1);
		}
		else{
			j = top;
			top = graph[top].count;
			printf("vertex %d ", j);
			for (ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if (!graph[k].count) {
					graph[k].count = top;
					top = k;
				}
			}
		}
		if(i!=n-1)
			printf(" -> ");
	}
}
nodePointer create(int vertex) {
	nodePointer p;
	nodePointer tmp = (nodePointer)malloc(sizeof(node));
	tmp->vertex = vertex;
	tmp->link = NULL;
	p = tmp;
	return p;
}
int main()
{
	int i;
	for (i = 0; i < MAX_VERTEX; i++) {
		graph[i].link = NULL;
	}
	graph[0].count = 0;
	graph[1].count = 1;
	graph[2].count = 1;
	graph[3].count = 1;
	graph[4].count = 1;
	graph[5].count = 1;
	graph[6].count = 2;
	graph[7].count = 3;
	

	graph[0].link = create(1);
	graph[1].link = create(2); graph[1].link->link = create(3); graph[1].link->link->link = create(4);
	graph[2].link = create(7);
	graph[3].link = create(6);
	graph[4].link = create(5); graph[4].link->link = create(6);
	graph[5].link = create(7);
	graph[6].link = create(7);
	
	topSort(graph, MAX_VERTEX);
	
	return 0;
}