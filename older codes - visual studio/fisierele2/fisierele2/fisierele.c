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
	if ((f = fopen("evidenta.txt", "r")) == NULL)
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
	int i;
	for (i = 0; i < n; i++)
		printf("%s %d %d %d %d\n", c[i].nume, c[i].stare, c[i].pret, c[i].garantie.luna, c[i].garantie.an);

}

void sortare(echipament v[], int n)
{
	int h[3] = { 3,2,1 };
	int i, j, k, w;
	echipament aux;
	for (w = 0; w < 3; w++)
	{
		k = h[w];
		for (i = k; i < n; i++)
		{
			aux = v[i];
			j = i - k;
			while (j >= 0 && strcmp(aux.nume, v[j].nume) < 0)
			{
				v[j + k] = v[j];
				j = j - k;
			}
			v[j + k] = aux;
		}
	}
}

void insertie(echipament c[], int n)
{
	int i, j, k;
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
		c[j + 1] = aux;
	}
}

void selectie(echipament c[], int n)
{
	int i, j, min_pos;
	echipament aux;

	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;//indexul celui mai mic caracter
		for (j = i + 1; j < n; j++)
			if (strcmp(aux.nume, c[j].nume) < 0)
				min_pos = j;
		if (min_pos != i)
		{
			echipament tmp = c[i];
			c[i] = c[min_pos];
			c[min_pos] = tmp;
		}
	}
}

int cautare_binara(echipament c[], int s, int d, char aux[])
{
	int m = (s + d) / 2;
	do {
		if (strcmp(c[m].nume, aux) < 0)
			s = m - 1;
		else
			d = m - 1;


	} while (s <= d && strcmp(c[m].nume, aux) == 0);
	return m;
}

int cauatare_liniara(echipament c[], int n, char aux[])
{
	for (int i =0 ; i < n; i++)
	{
		if (strcmp(c[i].nume, aux) == 0)
			return i;
	}
	return -1;
}

int main()
{
	int n, index, index2;
	char caracter[10];
	echipament c[100];
	n = citire(c);
	printf("%d\n", n);
	printf("nesrorat:\n"); afisare(c, n); printf("\n");
	insertie(c, n);
	printf("sortare insertie:\n"); afisare(c, n); printf("\n");
	sortare(c, n);
	printf("sortare shell:\n"); afisare(c, n); printf("\n");
	selectie(c, n);
	printf("sortare selectie\n"); afisare(c, n); printf("\n");
	printf("introduceti numele cautat:");
	scanf("%s", &caracter);
	index = cautare_binara(c, 0, n, caracter);
	printf("pozitia este:%d\n", index);
	index2 = cauatare_liniara(c, n, caracter);
	printf("%d\n", index2+1);
	return 0;
}