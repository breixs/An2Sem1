
//sa se def tipul de date abstract student ce contine: nume[20] preume[20] float: nota1, nota2, nota3.
//incarcati datele din fiesier intr-un tablou de articole. afisati tabloul.

//ordonati tabloul crescator alfabetic dupa nume folosind qsort. afisati tabloul.

//cautati o persoana in tablou folosind cautarea binara. afisati informatiile asociate persoanei cautate

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Studenti {
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
	if (f = fopen("studenti.txt", "r") == NULL)
	{
		printf("fisierul nu a fost citit");
		return -1;
	}
	while (!feof(f))
	{
		fscanf(f , "%s %s %f %f %f", s[i].nume, s[i].prenume, &s[i].nota1, &s[i].nota2, &s[i].nota3);
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

int main()
{
	int n, index;
	student s[10];
	char caracter;
	n = citire(s);
	afisare(s, n);
	return 0;
}