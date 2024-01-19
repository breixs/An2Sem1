#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char nume[30];
	int cantitate;
	float pret;

}Leguma;

void citeste(Leguma* l, int* n)
{
    char num[30]; float p; int c, i, ok = 0;
    printf("Introduceti numele legumei: "); scanf("%s", num);
    printf("Introduceti pretul legumei: "); scanf("%f", &p);
    printf("Introduceti cantitatea: "); scanf("%d", &c);
    for (i = 0; i <= n; i++)
        if (strcmp((l + i)->nume, num) == 0)
        {
            ok = 1;
            (l + i)->cantitate = (l + i)->cantitate + c;
            (l + i)->pret = p;
            break;
        }
    if (ok == 0)
    {
        (n)++;
        strcpy((l + *n)->nume, num);
        (l + *n)->pret = p;
        (l + *n)->cantitate = c;
    }
}

void afiseaza(Leguma* l, int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        printf("Nume produs: %s\n", (l + i)->nume);
        afisareNume((l + i)->nume);
        printf("Cantitate: %d\n", (l + i)->cantitate);
        printf("Pret: %f\n\n", (l + i)->pret);
    }
}

void ordonare(Leguma* l, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (strcmp((l + i)->nume, (l + j)->nume) > 0)
            {
                Leguma aux;
                aux = *(l + i);
                *(l + i) = *(l + j);
                *(l + j) = aux;
            }
}

void transformare(Leguma* l, int n)
{
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j < strlen((l + i)->nume); j++)
            if ((l + i)->nume[j] == 'a' || (l + i)->nume[j] == 'e' || (l + i)->nume[j] == 'i' || (l + i)->nume[j] == 'o' || (l + i)->nume[j] == 'u')
                (l + i)->nume[j] = (l + i)->nume[j] - ('a' - 'A');//32
}

void stergere(Leguma* l, int* n)
{
    int k = 0, i, j;
    char num[30];
    printf("Introduceti leguma pe care vreti sa o stergeti: "); scanf("%s", num);
    for (i = 0; i <= *n - k; i++)
        if (strcmp((l + i)->nume, num) == 0)
        {
            k++;
            for (j = i; j < *n - k; j++)
                *(l + j) = *(l + j + 1);
            i--;
        }
    *n = *n - k;
}

int main()
{

	Leguma l[100];
	int n = -1, opt;
	do {

		printf("meniu:\n");
		printf("introduceti opt:\n");
		scanf("%d", &opt);

		switch (opt) 
		{
			case 1:
				citire(l, &n) || (citire(&l[0], &n));
                break;
            case 2:
                afiseaza(l, n);
                break;
            case 0:
                break;


        }

	} while (opt != 0);
    return 0;
}