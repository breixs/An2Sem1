
//sa se def tipul de date abstract student ce contine: nume[20] preume[20] float: nota1, nota2, nota3.
//incarcati datele din fiesier intr-un tablou de articole. afisati tabloul.

//ordonati tabloul crescator alfabetic dupa nume folosind qsort. afisati tabloul.

//cautati o persoana in tablou folosind cautarea binara. afisati informatiile asociate persoanei cautate

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char nume[20];
	char prenume[20];
	float nota1;
	float nota2;
	float nota3;
}student;

int citire(student s[])
{
	FILE* f;
	int i = 0;
	if ((f = fopen("student.txt", "r")) == NULL)
	{
		printf("fisierul nu a fost citit");
		return -1;
	}
	while (!feof(f))
	{
		fscanf(f, "%s %s %f %f %f", s[i].nume, s[i].prenume, &s[i].nota1, &s[i].nota2, &s[i].nota3);
		i++;
	}
	return i;
}

void afisare(student s[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%s %s %f %f %f\n", s[i].nume, s[i].prenume, s[i].nota1, s[i].nota2, s[i].nota3);
}

void sortare(student s[], int n)
{
	int i, j;
	student aux;
	for (i = 0; i < n; i++)
	{
		aux = s[i];
		j = i - 1;
		while (j>=0 && strcmp(aux.nume, s[j].nume)<0)
		{
			s[j+1]=s[j];
			j = j - 1;
		}
		s[j + 1] = aux;
	}
}

int cautare_binara(student s[], int l, int d, char aux[])
{
	int m;
	while (l <= d)
	{
		m = (l + d) / 2;
		if ((strcmp(s[m].nume, aux)) == 0)
			return m;
		else if (strcmp(s[m].nume, aux) > 0)
			d = m - 1;
		else
			s = m + 1;
	}
	return -1;
}

int cautare_liniara(student s[], int n, char aux)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if ((strcmp(s[i].nume, aux)) == 0)
			return i;
	}
	return -1;
}

int main()
{
	int n, index;
	student s[10];
	char caracter;
	n = citire(s);
	afisare(s, n);
	sortare(s, n); printf("\n");
	afisare(s, n);
	printf("numele cautat:");
	scanf("%s", &caracter);
	index = cautare_binara(s, n,0, caracter);
	printf("%d", index);

	return 0;
}