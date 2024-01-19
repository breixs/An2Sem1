#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void functie(int* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", *(v+i));
}

int main()
{
	int i, n;
	int* v;

	printf("n=");
	scanf("%d", &n);

	v = (int*)malloc(n * sizeof(int));

	if (v == NULL)
	{
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		printf("[%d] = ", i);
		scanf(" %d", (v + i));
	}

	functie(v, n);

	free(v);
	return 0;
}