#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 1000
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 6

int cost[][MAX_VERTEX] = {
	{0, 50, 45, 10, INF, INF},
	{INF, 0, 10, 15, INF, INF},
	{INF, INF, 0, INF, 30, INF},
	{20, INF, INF, 0, 15, INF},
	{INF, 20, 35, INF, 0, INF},
	{INF, INF, INF, INF, 3, 0},
};
int dist[][MAX_VERTEX] = { 0 };

void allcosts(int cost[][MAX_VERTEX], int distance[][MAX_VERTEX], int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			dist[i][j] = cost[i][j];
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main()
{
	int i, j;
	allcosts(cost, dist, MAX_VERTEX);
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			if (dist[i][j] < INF)
				printf("%d  ", dist[i][j]);
			else
				printf("INF  ");
		}
		printf("\n");
	}
	return 0;
}