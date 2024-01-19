#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bar {
	char nume[20];
	char cod[20];
	int pret;
}B;

void citire(B* bautura, int* n)
{
	(*n)++;

	printf("nume:");
	scanf("%s", (bautura + *n)->nume);
	printf("cod:");
	scanf("%s", (bautura + *n)->cod);
	printf("pret:");
	scanf("%d", &(bautura + *n)->pret);

}


void afisare(B* bautura, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n %s\n %d", (bautura + i)->nume, (bautura + i)->cod, (bautura + i)->pret);
}

int main()
{
	int n = -1, opt;
	B bautura[100];

	do {

		printf("opt:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			citire(bautura, &n);
			break;
		case 2:
			afisare(bautura, n);
		case 0:
			break;
		default:
			break;
		}

	} while (opt != 0);
}

void nujcoaie(B* bautura, int n)
{
}
