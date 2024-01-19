#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void citire(char* m, int n) //daca esti smecher alegi 4 elemente si intoduci d, e, r
{
	int i, ok;
	do {
		for (i = 0; i < n-1; i++)
		{
			m[n-1] = 'i';
			printf("[%d] = ", i);
			scanf(" %c", (m + i));

			if (*(m + i) >= 'a' && *(m + i) <= 'z')
			{
				ok = 1;
				continue;
			}
			else {
				ok = 0;
				printf("citire incorecta\n");
				break;
			}
		}
	} while (ok == 0);
}

void afisare(char* m, int n)
{
	int i, j, aux;
	for (i = 0; i < n; i++)
		for(j=i; j<n; j++)
		{
			if (*(m + j) > *(m + i))
			{
				aux = *(m + j);
				*(m + j) = *(m + i);
				*(m + i) = aux;
			}
		}
	for (i = 0; i < n; i++)
			printf("%c", *(m + i));
}

void impar(char* m, int n) 
{
	int i;
	for (i = 0; i < n; i++)
	{
		if ((i % 2) == 0)
		{
			printf("%c", *(m + i));
		}
	}
}
void ascii_biti(char* m, int n) 
{
	int i, k = 1, sum=0, bin, rem;

	for (i = 0; i < n; i++)
		sum = sum + *(m + i);

	printf("suma in zecimal: %d", sum);
	printf("\n");

	bin = 0;
	
	while (sum != 0)
	{
		rem = sum % 2;
		sum = sum / 2;
		bin = bin + rem * k;
		k = k * 10;
	}

	printf("suma in binar: %d", bin);
}

int main()
{
	int n, opt;
	char* m;
	do{
		printf("nr de elemente:");
		scanf("%d", &n);
	} while (n > 50);
	m = (char*)malloc(n * sizeof(char));

	if (m == NULL) {
		printf("amogus");
		exit(0);
	}

	citire(m, n);

	do {
		printf("\nMeniu:\n");
		printf("0. Iesire.\n");
		printf("1. Afisarea elementelor multimii in ordine descrescatoare.\n ");
		printf("2. Sa se afiseze cuvantul format din literele de pe pozitie impara.\n");
		printf("3. Suma ASCII in binar.\n");
		printf("Alege optiunea:");
		scanf("%d", &opt);
		switch (opt) 
		{
		case 1: 
			afisare(m, n);
			break;
		case 2:
			impar(m, n);
			break;
		case 3:
			ascii_biti(m, n);
			break;
		case 0: 
			free(m);
			exit(0);
			break;
		default: 
			free(m);
			exit(0);
			break;
		}
	} while (opt != 0);

	free(m);
	return 0;
}