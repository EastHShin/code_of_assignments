#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Operand_Num 10
int remainder(int x)
{
	return x % 42;
}
int main()
{
	int operand[Operand_Num];
	int res[Operand_Num];
	int count = 0;
	for (int i = 0; i < Operand_Num; i++)
		scanf("%d", &operand[i]);
	for (int i = 0; i < Operand_Num; i++)
		res[i] = remainder(operand[i]);
	for (int i = 0; i < Operand_Num; i++)
	{
		if (res[i] == 43)
			continue;
		for (int j = i + 1; j < Operand_Num; j++)
		{
			if (res[i] == res[j])
			{
				res[j] = 43;	//나머지로 나올수 없는 수를 대입
			}	
		}
		count++;
	}
	printf("%d", count);
	
	return 0;
}