#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void afisare(char** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c\n", *(m+i*n+j));
		}
		printf("\n");
	}
}

void diagonala(char** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((i+j)==(n-1))
				printf("%c\n", *(m + i * n + j));

		}
		printf("\n");
	}

}

void biti(char** m, int n)
{
	int i, j, k, contor=0, l[20];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			l[20] = (m + i * n + j);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 31; j >= 0; j--)
		{
			k = (l[i] > j) & 1;
			contor++;
		}
		if (contor == 1)
			printf("%c", l[i]);
	}
}

int main()
{
	int i, j, opt, n;
	char** m;

	printf("n:");
	scanf("%d", &n);

	m = (char**)malloc(n * sizeof(char*));

	if (m == NULL)
	{
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("[%d][%d] = ", i,j);
			scanf(" %c", (m+i*n+j));
		}
	}

	do {
		printf("opt:");
		scanf("%d", &opt);
		
		switch (opt)
		{
		case 1:
			afisare(m, n);
			break;
		case 2:
			diagonala(m, n);
			break;
		case 3:
			biti(m, n);
			break;
		case 0:
			free(m);
			exit(0);
			break;
		}
	} while (opt != 0);
	free(m);
	return 0;

}