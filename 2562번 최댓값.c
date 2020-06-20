#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Num 9
int main()
{
	int integer[Num];
	int max = -1;
	int max_index;
	for (int i = 0; i < Num; i++)
		scanf("%d", &integer[i]);
	for (int i = 0; i < Num; i++)
	{
		if (integer[i] > max)
		{
			max = integer[i];
			max_index = i+1;
		}

	}
	printf("%d\n%d", max, max_index);
	return 0;
}