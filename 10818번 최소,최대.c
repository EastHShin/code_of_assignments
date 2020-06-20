#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N;
	int max = -1000000;
	int min = 1000000;
	scanf("%d", &N);
	int* integer = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &integer[i]);
	for (int i = 0; i < N; i++)
	{
		if (integer[i] > max)
			max = integer[i];
		if (integer[i] < min)
			min = integer[i];
	}
	printf("%d %d", min, max);
	return 0;
}