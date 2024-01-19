#include <stdio.h>
#include <stdlib.h>

typedef struct numere {
	int num, rez;
}nr;

void adaugare(nr* m, int* n)
{
	int numar;
	printf("introduceti numarul");
	scanf("%d", &numar);
	(*n)++;
	(m + *n)->num = numar;
}
void afisare(nr* m, int n)
{
	int i;
	for (i = 0; i <= n; i++)
		printf("%d\n", (m + i)->num);
}

void binary(nr* m, int n)
{
	int i,j,aux=0;
	for (j = 0; j <= n; j++) 
	{
		for (i = 31; i >= 0; i--)
		{
			printf("%d", ((m+j)->num >> i) & 1);
		}
		printf("\n");
	}
}
void contorizare(nr* m, int n)
{
	int i, j, aux=0, k=0;
	for (j = 0; j <= n; j++)
	{
		for (i = 31; i >= 0; i--)
		{
			if (((m+j)->num >> i) & 1)
				k++;
		}
		printf("%d\n", k);
		k = 0;
	}
}

void impar(nr* m, int n)
{
	int i, j, k = 0;
	int aux=0;
	FILE* f;
	FILE* out;
	for (j = 0; j <= n; j++)
	{
		for (i = 31; i >= 0; i--)
		{
			if (((m + j)->num >> i) & 1)
				k++;
		}
		if (k % 2 != 0)
		{
			f=fopen("numere.bin", "wb");
			if (f == NULL)
			{
				printf("amogus");
				return -1;
			}
			size_t el_w=fwrite(&(m + j)->num, sizeof(nr), 1, f);
			fclose(f);
			if (el_w == 0) {
				printf("mogus");
				return -1;
			}
			f = fopen("numere.bin", "rb");
			if (f == NULL)
			{
				printf("amogus");
				return -1;
			}
			size_t el_r = fread(&aux, sizeof(int), 1, f);
			fclose(f);
			if (el_r == 0) {
				printf("mogus");
				return -1;
			}
			printf("%d\n", aux);
		}
		k = 0;
	}
}

int main()
{
	/*int n, rez;
	printf("n=");
	scanf("%d", &n);
	printf("binar:");
	binary(n);
	rez = contorizare(n);
	printf("\n%d", rez);
	return 0;*/
	int n = -1, opt;
	nr m[100];
	do {
		printf("opt=");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: adaugare(m, &n);
			break;
		case 2: afisare(m, n);
			break;
		case 3: binary(m, n);
			break;
		case 4:
			 contorizare(m, n);
			 break;
		case 5: impar(m, n);
			break;
		case 0:
			break;
		}
	} while (opt != 0 || opt>=6);
	return 0;
}