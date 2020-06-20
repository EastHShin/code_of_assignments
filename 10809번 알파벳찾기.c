#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char word[101];
	scanf("%s", word);
	int length = strlen(word);
	for (int i = 97; i <= 122; i++)
	{
		int empty = -1;
		for (int j = 0; j < length; j++)
		{
			if (i == word[j])
			{
				empty = j;
				break;
			}
		}
		printf("%d ", empty);
	}
	
	return 0;
}