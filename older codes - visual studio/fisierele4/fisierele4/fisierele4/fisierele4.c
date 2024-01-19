#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int luna, an;
}data;

typedef enum evidenta { in_magazie, expus, vandut }evidenta;

typedef struct echipament {
	char nume[30];
	int pret;
	evidenta stare;
	data garantie;
}echipament;

int citire(echipament c[])
{
	FILE* f;
	int i = 0;
	if ((f = fopen("evidentele.txt", "r"))==NULL)
	{
		printf("amogus");
		return -1;
	}
	while (!feof(f))
	{
		fscanf(f, "%s %d %d %d %d", c[i].nume, &c[i].stare, &c[i].pret, &c[i].garantie.luna, &c[i].garantie.an);
		i++;
	}
	fclose(f);
	return i;
}

void afisare(echipament c[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s %d %d %d %d\n", c[i].nume, c[i].stare, c[i].pret, c[i].garantie.luna, c[i].garantie.an);
	}
	printf("%d", i);
}

////void sortare_selectie(echipament c[], int n)
////{
////	int i, j, min_pos;
////	echipament aux;
////
////	for (i = 0; i < n - 1; i++)
////	{
////		min_pos = i;//indexul celui mai mic caracter
////		for (j = i + 1; j < n; j++)
////			if (strcmp(aux.nume, c[j].nume) < 0)
////				min_pos = j;
////		if (min_pos != i)
////		{
////			echipament tmp = c[i];
////			c[j] = c[min_pos];
////			c[min_pos] = tmp;
////		}
////	}
////}

void sortare_insertie(echipament c[], int n) {
	int i, j;
	echipament aux;
	for (i = 0; i < n; i++)
	{
		aux = c[i];
		j = i - 1;

		while (j >= 0 && strcmp(aux.nume, c[j].nume) < 0)
		{
			c[j + 1] = c[j];
			j = j - 1;
		}
		c[j+1] = aux; 
	}
}

int cautare_binara(echipament c[], int s, int d, char aux[])
{
	int m;
	while (s <= d)
	{
		m = (s + d) / 2;
		if (strcmp(c[m].nume, aux) == 0)
			return m;
		else if (strcmp(c[m].nume, aux) > 0)
			d = m - 1;
		else
			s = m + 1;
	}
	return -1;
}

int main()
{
	int n, index;
	char car[20];
	echipament c[20];
	n = citire(c);
	printf("%d", n);
	afisare(c, n);
	printf("\n");
	sortare_insertie(c, n); 
	afisare(c, n);
	printf("caracterul cautat:");
	scanf("%s", &car);
	printf("%s", car);
	index = cautare_binara(c, 0, n, car);
	printf("\n%d", index+1);

	return 0;
}