#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire(char** v, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			v[n - 1] = (char*)malloc((strlen('Leu') + 1));
			strcpy(v[n - 1], 'Leu');
		}
		else
		{
			printf("numele animalului:");
			scanf("%s", nume);
			getchar();
			strcpy(v[i], nume);
		}
	}
}

void afisare(char** v, int n)
{
	int i,j;
	char* aux;
	aux = (char*)malloc(25 * sizeof(char));
	for (i = 0; i < n-1; i++)
	{
		for(j=i;j<n;j++)
		{
			if (strcmp(v[i], v[j]) == 1)
			{
				strcpy(aux, v[i]);
				strcpy(v[i], v[j]);
				strcpy(v[j], aux);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%s, ", v[i]);
	}
}

void lungime(char** v, int n)
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (strlen(v[i]) > strlen(v[j]))
			{
				printf("%s, ", v[i]);
			}
			else
			{
				printf("%s ", v[j]);
			}
		}
	}
}

int main()
{
	int n,i, opt;
	char** v;

	printf("nr elemente:");
	scanf("%d", &n);
	v = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
		v[i] = (char*)malloc(25 * sizeof(char));

	if (v == NULL)
	{
		printf("amogus");
		exit(0);
	}

	citire(v, n);

	do {
		printf("opt:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			afisare(v, n);
			break;
		case 0:
			free(v);
			break;
		}


	} while (opt != 0);
	free(v);
	return 0;
}