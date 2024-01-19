#include <stdio.h>

int main(void)
{
	int n, i, j;
	printf("n=");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j =1; j <= n; j++)
		
			if (i % 2 == 1)
				printf("#");
			else
				printf("*");
			printf("\n");
	}
	return 0;
}