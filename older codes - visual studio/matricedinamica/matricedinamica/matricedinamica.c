#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire(int** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("m[%d][%d]", i, j);
			scanf("%d", (m + i * n + j));
		}
	
}
void afisare(int** m,int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", *(m + i * n + j));

		}
		printf("\n");
	}
}

int main()
{
	int n, opt;
	int** m;

	scanf("%d", &n);

	m = (int**)malloc(n * n * sizeof(int));

	citire(m, n);
	afisare(m, n);

	return 0;


}