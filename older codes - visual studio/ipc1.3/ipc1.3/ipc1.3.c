#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire(int** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("[%d][%d] = ", i, j);
			scanf("%d ", &m[i][j]);
		}
	}
}

void afisare(int** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void colturi(int** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("1: %d", m[0][0]);
			printf("2: %d", m[0][n - 1]);
			printf("3: %d", m[n - 1][0]);
			printf("4: %d", m[n - 1][n - 1]);
		}
		printf("\n");
	}
	printf("\n");
}


int main()
{
	int n, i, opt;
	int** m;

	printf("nr elemente");
	scanf("%d", &n);

	m = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		m[i] = (int*)malloc(n * sizeof(int));

	if(m == NULL)
	{
		printf("amogus");
		exit(0);
	}

	citire(m, n);

	do {
		printf("opt:");
		scanf("%d", &opt);

		switch(opt) {
		case 1:
			afisare(m, n);
			break;
		case 2:
			colturi(m, n);
			break;
		case 0:
			exit(0);
			free(m);
			break;
		}
	} while (opt != 0);

	free(m);
	return 0;
}