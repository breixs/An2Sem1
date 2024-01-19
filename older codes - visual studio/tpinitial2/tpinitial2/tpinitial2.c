#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_anagram(char* s1, char* s2)
{
	int i, j, a, b=0;
	for (i = 0; i < 5; i++)
	{
		a = 0;
		for (j = 0; j < 5; j++)
		{
			if (s1[i] == s2[j])
			{
				a = 1;
				break;
			}
			else
				a=0;
		}
		if (a == 0)
		{
			b == 1;
			break;
		}
	}
	if (b == 1)
		printf("nu e angrama");
	else
		printf("angrama");
}

int main()
{
	int i;
	char* s1;
	s1 = (char*)malloc(5 * sizeof(char));

	for (i = 0; i < 5; i++)
	{
		scanf("%c", &s1[i]);
		getchar();
	}
	
	for (i = 0; i < 5; i++)
		printf("%c ", s1[i]);

	free(s1);
	return 0;
	
}