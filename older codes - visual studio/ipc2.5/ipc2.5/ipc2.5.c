#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citire(char** sir, int n)
{
	int i;
	char *nume;
	nume = (char*)malloc(sizeof(char) * 20);

	for (i = 0; i < n; i++)
	{
		printf("numele:");
		getchar();
		scanf("%s", nume);

		sir[i] = (char*)malloc(sizeof(char)*strlen(nume) + 1);
		strcpy(sir[i], nume);
	}
}

void afisare(char** sir, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf(" %s ", *(sir+i));
}
void sortare(char** sir, int n)
{
	int i, j;
	char* aux;
	aux = (char*)malloc(sizeof(char)*20);
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (strlen(*(sir+i)) > strlen(*(sir+j)))
			{
				strcpy(aux,*(sir + i));
				strcpy(*(sir+i), *(sir + j));
				strcpy(*(sir + i), aux);
			}
		}
		
	}
	afisare(sir, n);
}

void vocala(char** sir, int n)
{
	int i,j,k=0;
	char v[20];
	//v = (char*)malloc(sizeof(char) * 20);
	for (i = 0; i < n; i++)
	{
			if ((sir[i] == 'a'))
			{
				v[k]==sir[i];
				k++;
				break;
			}
	}
	for (i = 0; i < k; i++)
		printf("%c", v[i]);

}

int main()
{
	int n, opt;
	char** sir;

	printf("nr elemente:");
	scanf("%d", &n);

	sir = (char**)malloc(n * sizeof(char));

	if (sir == NULL)
	{
		printf("amogus");
		exit(0);
	}
	citire(sir, n);

	do {
		printf("opt:");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1: 
			sortare(sir, n);
			break;
		case 2:
			vocala(sir, n);
		case 0:
			break;
		}

	} while (opt != 0);
	free(sir);
	exit(0);
	return 0;
}
