#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* f_in;
	int n=15, i, contor=0, j;
	char c, num[10];
	printf("numele cautat:\n");
	scanf("%s", &num);
	if ((f_in = fopen("nume.txt", "r")) == NULL)
	{
		printf("amogus");
		return -1;
	}
	while (!feof(f_in))
	{
		for (i = 0; i < n; i++)
		{
			c = fgetc(f_in);
			if (c == EOF)
				break;
			else
			{
				for (j = 0; j < strlen(num); j++)
				{
					if (c == num[j])
					{
						putchar(c);
						contor++;
					}
				}
			}
	
		}
	}
	printf("\n%d", contor);
	fclose(f_in);
	return 0;
}