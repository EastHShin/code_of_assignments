#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX_VERTEX 7
#define TRUE 1
#define FALSE 0
#define INF 1000


int cost[][MAX_VERTEX] = {
	{0, 10, 7, INF, 15, INF, INF},
	{10, 0, INF, 5, 8, INF, INF},
	{7, INF, 0, INF, 6, INF, INF},
	{INF, 5, INF, 0, 12, 6, INF},
	{15, 8, 6, 12, 0, INF, 3},
	{INF, INF, INF, 6, INF, 1},
	{INF, INF, INF, INF, 3, 1, 0}
};
int distance[MAX_VERTEX];
int found[MAX_VERTEX];
int n = MAX_VERTEX;
int stack[MAX_VERTEX];
int top = -1;
int PI[MAX_VERTEX];

void push(int n) {
	stack[++top] = n;
}
int pop() {
	if (isEmpty())
		return -1;
	return stack[top--];
}
int isEmpty() {
	if (stack[top] < 0)
		return TRUE;
	else
		return FALSE;
}

void shortestPath(int v, int cost[][MAX_VERTEX], int distance[], int n, int found[]) {
	int i, u, w;
	int j;
	for (i = 0; i < n; i++) {
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}

	found[v] = TRUE;
	distance[v] = 0;
	PI[v] = v;
	

	for (i = 0; i < (n - 2); i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		
		
		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					PI[w] = u;
				}
			}
		}
	}
}

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if ((distance[i] < min) && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

int main() {
	char s, d;
	int i;
	int path[MAX_VERTEX];
	int destination;
	printf("출발지역을 입력하세요: ");
	scanf(" %c", &s);
	printf("도착지역을 입력하세요: ");
	scanf(" %c", &d);
	s -= 65;
	d -= 65;
	destination = d;
	shortestPath(s, cost, distance, n, found);
	
	push(d);
	while (1) {
		if (PI[d] == s)
			break;
		push(PI[d]);
		d = PI[d];
	}
	push(s);
	int length = top;
	for (i = 0; i < length+1; i++) {
		path[i] = pop();
	}
	printf("Vertex %c에서 Vertex %c으로 가는 최단 경로는 ", s+65, destination+65);
	for (i = 0; i < length+1; i++) {
		printf("%c ", path[i] + 65);
	}
	printf("이며, 이 때 최단 거리는 %d입니다.\n", distance[destination]);
	return 0;
}