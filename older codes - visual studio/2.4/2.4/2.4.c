#include <stdio.h>
#include <stdlib.h>


void citeste(int **v, int n)
{
	int i, j;
	for(i=0;i<n;i++)
		for (j = 0; j < n;j++)
		{
			printf("[%d][%d] =", i, j);
			scanf("%d", (v+i*v+j);
		}

}
void afisare(int** v, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", v[i][j]);
		}
		printf("\n");
	}
}
void suma(int *v, int n)
{
	int i, j, suma;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i < j)
			{
				if ((i % 2 == 0) && (j % 2 == 0))
					suma = v[i] + v[j];
			}
		}
	printf("%d", suma);
}

int main()
{
	int n;
	int* v;
	v = (int**)malloc(n * sizeof(int*));
	printf("n=");
	scanf("%d", &n);

	citeste(v, n);
	afisare(v, n);


}