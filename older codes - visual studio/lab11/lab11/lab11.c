#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct student
{
	char titlu[50], autor[50], domeniul[50];
	int an, nrPag;

} Carte;

void citire(Carte* st, char* u, int *nr) {
	(*u)++;
	printf("Dati titlul cartii: ");
	scanf("%s", (st + *u)->titlu);
	printf("Dati autorul: ");
	scanf("%s", (st + *u)->autor);
	printf("Dati domeniul: ");
	scanf("%s", (st + *u)->domeniul);
	printf("Dati anul aparitiei: ");
	scanf("%d", &((st + *nr))->an);
	printf("Dati nr de pag: ");
	scanf("%d", &((st + *nr))->nrPag);
}

void afisare(Carte* st, char* u, int* nr, char domeniul, char* dom)
{
	scanf("%s", &domeniul);
	printf("\n%5s", (st + *u)->domeniul);
}

void cautare_titlu(Carte* st, int *nr, char tit[50])
{
	int i;
	for (i = 0; i <= (*nr); i++)
		if (strcmp((st + i)->titlu, tit) == 0)
			afisare(st, i);
}
void cautare_grupa(Carte* st, int* nr, int a)
{
	int i;
	for (i = 0; i <= (*nr); i++)
		if ((st + i)->an == a)
			afisare(st, i);
}

void stergere(Carte* st, int* nr, char tit[50])
{
	int k = 0, i, j;
	for (i = 0; i <= (*nr - k); i++)
		if (strcmp((st + i)->titlu, tit) == 0)
		{
			k++;
			for (j = i; j <= (*nr - k); j++)
				*(st + j) = *(st + j + 1);
			i--;
		}
	*nr = *nr - k;
}


int main() {

	Carte st[100];
	int opt,nr=-1, i, j;
	do {
		printf("\n1. Adaugarea unei carti\n");
		printf("2. Afisarea cartilor dintr-un domeniu citit de la tastatura\n");
		printf("3. Afisarea tuturor studentilor de la o anumita facultate\n");
		printf("4. Afisarea tuturor studentilor dintr-o anumita grupa\n");
		printf("5. Cautarea unui student dupa nume\n");
		printf("6. Stergerea unui student dupa nume\n");
		printf("7. Sortarea studentilor dupa nume\n");
		printf("0. Exit \n");
		printf("Dati optiunea \n"); scanf("%d", &opt);
		switch (opt) {
		case 1:
			citire(&st[0], &nr);
			break;
		case 2:
			for (i = 0; i <= n; i++)


}

