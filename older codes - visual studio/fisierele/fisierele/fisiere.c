#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int luna, an;
}data;

typedef enum evidenta{in_magazie, expus, vandut}evidenta;

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
	if ((f = fopen("C:\\Users\\paulb\\source\\repos\\fisierele test2.txt", "r")) == NULL)
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
	for (i = 0; i <n; i++)
		printf("%s %d %d %d %d", c[i].nume, c[i].stare, c[i].pret, c[i].garantie.luna, c[i].garantie.an);

}

int main()
{
	int n;
	echipament c[100];
	n=citire(c);
	printf("%d", n);
	afisare(c, n);
	return 0;
}


