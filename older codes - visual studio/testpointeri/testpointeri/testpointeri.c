#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <ctype.h>

typedef struct Animal {
	char nume[30];
	int numar_exemplare, durata_de_viata;

}ani;

void citire(ani* a, int* n)
{
	char num[30]; int nrx, dur, i, ok=0;
	printf("Introduceti Numele Animalului: ");
	scanf("%s", num);
	printf("Introduceti Numarul De Exemplare: ");
	scanf("%d", &nrx);
	printf("Introduceti Durata De Viata: ");
	scanf("%d", &dur);
	/*for (i = 0; i <= n; i++)
	{
		if (((a + 0) >= 'a') && ((a + 0) <= 'z'))
			ok = 0;
		else
			ok = 1;
	}*/
	if (ok == 0) 
	{
		(*n)++;
		strcpy((a + *n)->nume, num);
		(a + *n)->numar_exemplare = nrx;
		(a + *n)->durata_de_viata = dur;
	}
}
void afisare(ani* a, int n)
{
	int i, j, aux=0;
	for (i = 0; i <= n; i++)
	{
		/*for (j = i + 1; j <= n; j++)
		{
			(a + i) = aux;
			(a + i) = (a + j);
			(a + j) = aux;*/
		printf("Numele Animalului: %s\n", (a + i)->nume);
		printf("Numarul De Exemplare: %d\n", (a + i)->numar_exemplare);
		printf("Durata De Viata: %d\n", (a + i)->durata_de_viata);
		}
	
}

void afisare_media_de_viata(ani* a, int *n)
{
	int prag = 0;
	int i;
	printf("introduceti pragul: ");
	scanf("%d", &prag);
	for (i = 0; i < n; i++)
	{
		if (prag < ((a + i)->durata_de_viata))
		{
			printf("Animalul este:%s\n", (a + i)->nume);
			printf("Cu durata de viata: %d\n", (a + i)->durata_de_viata);
		}
	}
}

void afisare_p(ani* a, int *n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		char p[101];
		strcpy(p, a[i].nume);
		for (int j = 0; j < strlen(p); j++)
		{

			if (p[j] == 'p' && j == 0)
				printf("Animalul este:%s\n", (a + i)->nume);
		}

	}
}


int main()
{
	int n = -1, opt;
	ani a[100];
	do {
		printf("Meniu\n");
		printf("Optiunea 0: Iesire \n");
		printf("Optiunea 1: Adaugarea unui animal \n");
		printf("Optiunea 2: Afisarea In Ordine Alfabetica \n");
		printf("Optiunea 3: Afiarea Animalelor cu o durata de viata mai mare decat un prag introdus de utilizator \n");
		printf("Optiunea 4: Afisarea animalelor a caror denumire incepe cu p \n");
		printf("Introduceti Optiunea: \n");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			citire(a, &n);
			break;
		case 2:
			afisare(a, n);
			break;
		case 3:
			afisare_media_de_viata(a, n);
			break;
		case 4:
			afisare_p(a, n);
			break;
		case 0:
			break;
		}
	} while (opt != 0);
	return 0;
}