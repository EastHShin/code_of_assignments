#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B, C;
	int res;
	char str_res[11] = { 0 };
	int count = 0;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	res = A * B * C;
	sprintf(str_res, "%d", res);
	for (int i = '0'; i<='9'; i++)
	{
		for (int j = 0; str_res[j] != NULL; j++)
		{
			if (i == str_res[j])
				count += 1;
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}