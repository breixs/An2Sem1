#include <stdio.h>

int main(void)
{
	int n, i, j, v[100][100];
	printf("nr de elemente:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &v[i][j]);

	for (i = 0; i < n; i++)
	{
		printf("\n");
			for (j = 0; j < n; j++)
				printf("%d\t", v[i][j]);
	}

	return 0;
}

/*int main(void) {

	int n, i, j, v[100][100];

	printf("nr de elemente:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &v[i][j]);

	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			if (i == j)
				printf("diagaonala principala: %d", v[i][j]);
	} 
	return 0;
}*/