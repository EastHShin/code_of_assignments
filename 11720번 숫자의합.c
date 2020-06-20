/*
	백준 11729번 숫자의 합 문제
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