#include <stdio.h>
#include <stdlib.h>

void afisare(int* m, int n)
{
	int i, aux = 0;
	for (i = 0; i < n; i++)
	{
		aux = m[i];
		m[i] = m[i + 1];
		m[i + 1] = aux;
	}
	for (i = 0; i < n; i++)
		printf("%d", *(m+i));
}
void stergere(int* m, int n)
{
	int i;
	for (i = 0; i < n-1; i++)
	{
	
	printf("%d", *(m + i));

}

int main()
{
	int n, i, ok = 0;
	int opt;
	int* m;
	printf("dimensiunea vectorului:");
	scanf("%d", &n);

	m = (int*)malloc(n * sizeof(int));
	if (m == NULL)
	{
		exit(0);
	}

	//citire + validare 
	
	for (i = 0; i < n; i++)
	{
		printf("m[%d]", i + 1);
		scanf("%d", (m+i));
		/*if (m[i] > 0)
			ok = 1;
		else
		{
			ok = 0;
			free(m);
		}*/
	}
	
	/*for (i = 0; i < n; i++)
	{
		m[3] = m[1] + m[2];
		m[4] = m[2] + m[3];
	}*/
	printf("\n");
	//meniu
	do {


		printf("1: Afișarea elementelor mulțimii în ordine crescătoare.\n");
		printf("2: Să se șteargă ultimul element din mulțime, apoi să se afișeze restul elementelor din vector\n");
		printf("0: iesire");
		printf("Dati Optiunea");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			afisare(m, n);
			break;
		case 2:
			stergere(m, n);
			break;

		case 0: break;
		}

	} while (1);
	free(m);
	return 0;
}
