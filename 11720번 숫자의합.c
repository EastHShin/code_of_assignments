/*
	���� 11729�� ������ �� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int sum = 0;
	char number[100];
	scanf("%d", &N);
	scanf("%s", number);
	
	for(int i=0; i<N; i++)
	{
		sum += number[i] - 48;
	}
	printf("%d", sum);
	return 0;
}