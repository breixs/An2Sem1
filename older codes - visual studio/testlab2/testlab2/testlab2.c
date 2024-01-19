#include <stdio.h>

int main(void) {

	int n, a[100][100], s = 0, i, j, k, sd=0,aux;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
			printf("Matricea este:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d\t", a[i][j]);
			printf("\n");
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			s = s + a[i][j];
	printf("Suma: %d", s); printf("\n");
	for (i = 0; i < n; i++)
		sd = sd + a[i][i];
	printf("Suma de pe diag princip: %d", sd);
	/*
	Suma elem. diag. princip. metoda 2:
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if(i==j)
				sd=sd+a[i][j];
	printf("Suma de pe diag princip: %d", sd);
	*/
	for (i = 0; i < n-1; i++)
		for(k=i+1;k<n;k++)
		if (a[0][i] > a[0][k])
		{
			aux = a[0][k];
			a[0][k] = a[0][i];
			a[0][i] = aux;
		}
	printf("\n"); printf("Matricea cu prima linie ordonata:"); printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	return 0;
}