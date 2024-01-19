#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct  DATA
{
	int luna, an;
}data;
typedef enum EVIDENTA
{
	in_magazie, expus, vandut
}evidenta;
typedef struct echipament
{
	char nume[31];
	evidenta stare;
	float pret;
	data garantie;
} echipament;
int citire(echipament c[])
{
	FILE* f;
	int i = 0;
	if (f = fopen("evidenta.txt", "rt") == NULL)
	{
		printf("Fisierul nu a fost gasit!");
		return -1;
	}
	while (!feof(f))
	{
		fscanf(f, "%s %d %f %d %d", &c[i].nume, &c[i].stare, &c[i].pret, &c[i].garantie.luna, &c[i].garantie.an);
		i++;
	}
	fclose(f);
	return i;

}
void afisare(echipament c[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s %d %f %d %d", c[i].nume, c[i].stare, c[i].pret, c[i].garantie.luna, c[i].garantie.an);
	}
}

void shell_sort(echipament a[], int n) {
	int h[3] = { 3,2,1 };
	int i, j, k, t;//t-trecere
	echipament aux;
	for (t = 0; t < 3; t++) {
		k = h[t];
		for (i = k; i < n; i++) {
			j = i - k;
			aux = a[i];
			while (j >= 0 && ((strcmp(a[i].nume, aux.nume) > 0)))
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
	}
}
int cautarea_binara(echipament c[], int s, int d, char aux)
{
	int n;
	do {
		n = (s + d) / 2;
		if (strcmp(c[n].nume, aux) < 0)
			s = n - 1;
		else
			d = n - 1;
	} while (s <= d && strcmp(c[n].nume, aux) == 0);
	return n;
}


int main()
{


	system("pause");
	return 0;
}