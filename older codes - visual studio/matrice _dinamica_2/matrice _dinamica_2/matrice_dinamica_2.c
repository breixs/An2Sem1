#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#define esteok(c)  ((c>='A' && c<='Z'))

void citire(char** m, int n)
{
	int i, j, ok=1;
	do{
		printf("matricea:\n");
	for (i = 0; i < n; i++)
		for (j = 1; j < n; j++)
		{
			*(m + i * n + 0) = 'A';
		
				getchar();
				printf("[%d][%d]", i, j);
				scanf("%c", (m + i * n + j));

				/*if (esteok(*(m + i * n + j)) == 1)
				{
					ok = 1;
					continue;
				}
				else
				{
					ok = 0;
					printf("cittire incorecta\n");
					break;
				}*/
			}
	} while (ok == 0);
}
void afisare(char** m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", *(m + i * n + j));
		}
		printf("\n");
	}
}
void diagonalaprincipala(char** m, int n)
{
	int i, j, aux;
	char v[100];
	printf("Diag princ: ");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				printf("%c", *(m + i * n + i));
			}
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				v[i]= *(m + i * n + i);
			}
		}
	printf("\nv copiat: ");
	for (i = 0; i < n; i++)
	{
		printf("%c", v[i]);
	}
	for (i = 0; i < n; i++)
		for(j=i; j<n;j++)
		{
			if (v[j] > v[i])
			{
			aux = v[j];
			v[j] = v[i];
			v[i]=aux;
			}
		}
	printf("\nv sortat desc: ");
	for (i = 0; i < n; i++)
	{
		printf("%c", v[i]);
	}
	printf("\n");
}

void colturi(char** m, int n)
{
	int i, j, css, cds, csj, cdj;
	printf("intorduceti elementele care vor inlocui colturile:");
	printf("css:");
	scanf("%c", &css);
	printf("cds:");
	scanf("%c ", &cds);
	printf("csj:");
	scanf("%c ", &csj);
	printf("cdj:");
	scanf("%c ", &cdj);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			*(m + 0 * n + 0) = css;
			*(m + 0 * n + (n-1)) = cds;
			*(m + (n-1) * n + 0) = csj;
			*(m + (n-1) * n + (n-1)) = cdj;
		}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%c", *(m + i * n + j));

		printf("\n");
	}

}

int main()
{
	char** m;
	int n=0, opt=0, i;

	printf("nr elemente");
	scanf("%d", &n);

	m = (char**)malloc(n * sizeof(char));

	if (m == NULL)
	{
		exit(0);
	}

	citire(m, n);

	
	do {
		printf("meniu:");
		printf("\n");
		printf("1:Afisarea matricei.\n");
		printf("2:Sa se copieze intr-un vector, caracterele de pe diagonala principala si sa se afișeze vectorul sortat descrescator.\n");
		printf("3:Sa se modifice toate caracterele din colturile matricei, cu un caracter dat de utilizator de la tastatura.\n");
		printf("0:iesire\n");

		printf("\nopt:");
		scanf("%d", &opt);
			

		switch (opt)
		{
		case 1:
			afisare(m, n);
			break;
		case 2:
			diagonalaprincipala(m, n);
			break;
		case 3:
			colturi(m, n);
			break;
		case 0:
			free(m);
			break;
		default:
			free(m);
			break;
		}

	} while (opt != 0);

	free(m);
	return 0;
}