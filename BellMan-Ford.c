#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define INF 1000
#define MAX_VERTEX 6
#define source 0
int length[][MAX_VERTEX] = {
	{0, 10, INF, 20, INF, INF},
	{INF, 0, 60, INF, INF, INF},
	{INF, INF, 0, INF, -30, 20},
	{INF, 20, INF, 0, 30, INF},
	{INF, INF, INF, INF, 0, 10},
	{INF, INF, INF, INF, INF, 0}
};
int dist[MAX_VERTEX];

void BellmanFord(int n, int v) {
	int i, k, u, j;
	for (i = 0; i < n; i++)
		dist[i] = length[v][i];		//initialize dist

	for (k = 2; k <= (n - 1); k++) {
		for (u = 0; u < n; u++) {
			if (u == v)
				continue;
			for (i = 0; i < n; i++) {
				if (length[i][u] < INF) {
					if (dist[u] > dist[i] + length[i][u])
						dist[u] = dist[i] + length[i][u];
				}
			}

		}
	}
}

int main()
{	
	int destination;
	BellmanFord(MAX_VERTEX, source);
	printf("���� vertex�� �Է��ϼ���: ");
	scanf("%d", &destination);

	printf("Vertex %d������ Vertex %d������ shrotest path�� ���̴� %d�Դϴ�.\n", 
		source, destination, dist[destination]);
	return 0;
}