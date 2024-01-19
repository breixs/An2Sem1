#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Parc
{
	char marca[20];
	char tara[20];
	int pret;
}P;

void citeste(P* masina, int* n)
{
	(*n)++;

	printf("marca masina: ");
	scanf("%s", (masina + *n)->marca);
	getchar();
	printf("tara masina: ");
	scanf("%s", (masina + *n)->tara);
	getchar();
	(masina + *n)->pret = 10 * strlen((masina + *n)->marca) + strlen((masina + *n)->tara);
}

void afiseaza(P* masina, int n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		printf("marca:%s\n tara:%s\n pret:%d dabloons\n", (masina + i)->marca, (masina + i)->tara, (masina + i)->pret);
	}
}

void vocale(P* masina, int n)
{
	int i=0, contor=0;
	char* v;
	v = (char)malloc(sizeof(char) * 20);
	strcpy(v, (masina + i)->tara);
	getchar();
	for (i = 0; i <= n; i++)
	{
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				contor++;
		printf("%d", contor);

		if (contor > 2)
		{
			printf("%d", contor);
			printf("marca:%s\n tara:%s\n pret:%d dabloons\n", (masina + i)->marca, (masina + i)->tara, (masina + i)->pret);
		}
	}
	free(v);
}

int main()
{
	int n = -1, opt;
	P masina[100];
	do {
		printf("opt:");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1: 
			citeste(masina, &n);
			break;
		case 2: 
			afiseaza(masina, n);
			break;
		case 3:
			vocale(masina, n);
			break;
		case 0: break;
		}
	} while (opt != 0);
	return 0;
}