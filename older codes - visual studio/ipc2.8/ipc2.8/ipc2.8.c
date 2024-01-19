#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Magazin {
	char marca[20];
	int diagonala_ecran;
	int pret;
}M;

void citire(M* telefon, int* n)
{
	(*n)++;
	printf("marca tel:");
	scanf("%s", (telefon + *n)->marca);
	printf("diag tel:");
	scanf("%d", &(telefon + *n)->diagonala_ecran);
	printf("pret tel:");
	scanf("%d", &(telefon + *n)->pret);
}
void afisare(M* telefon, int n)
{
	int i;
	for(i=0; i<=n;i++)
		printf("marca:%s\n diag:%d\n pret:%d \n", (telefon + i)->marca, (telefon + i)->diagonala_ecran, (telefon + i)->pret);
}

void sortare(M* telefon, int n)
{
	int i, j;
	M aux;
	for (i = 0; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if ((telefon + i)->pret > (telefon + j)->pret)
			{
				aux = *(telefon + i);
				*(telefon + i) = *(telefon + j);
				*(telefon + j) = aux;
			}
		}
	}
}
void reducere(M* telefon, int* n)
{
	char marca_tast[20];
	int i, reducerea;
	printf("introduceti marca:");
	for (i = 0; i < n; i++)
	{
		scanf("%s", &marca_tast[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (strcmp(marca_tast, (telefon + i)->marca) == 0)
		{
			reducerea = (telefon + i)->pret * 20 / 100;
			(telefon + i)->pret = (telefon + i)->pret - reducerea;
			printf("%d\n", (telefon + i)->pret);
			break;
		}
	}
}
void biti(M* telefon, int* n)
{
	int i, k, contor = 0, nr, j;
	for (i = 0; i < n; i++)
	{
		nr = (telefon + i)->diagonala_ecran;
		for (j = 31; j >= 0; j--)
		{
			k = (nr >> j) & 1;
			if (k == 1)
				contor++;
		}
		printf("%d", contor);
	}
	printf("\n");
}


int main()
{
	int n = -1, opt;
	M telefon[100];

	do {
		printf("opt:");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			citire(telefon, &n);
			break;
		case 2:
			sortare(telefon, n);
			afisare(telefon, n);
			break;
		case 3:
			reducere(telefon, n);
			break;
		case 4: 
			biti(telefon, n);
			break;
		case 0:
			break;
		default: 
			break;
		}
	} while (opt != 0);
	return 0;
}