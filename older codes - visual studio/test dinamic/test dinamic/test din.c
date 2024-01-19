#include<stdio.h>
#include<stdlib.h>


void citire(int* M, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == 2) {
			*(M + i) = *(M + 0) + *(M + 1);
			continue;
		}
		if (i == 3) {
			*(M + i) = *(M + 0) + *(M + 1) + *(M + 2);
			continue;
		}
		do {
			printf("M[%d]: ", i + 1);
			scanf("%d", (M + i));
		} while (!poz(*(M + i)));
	}
}


void afisare(int* M, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", *(M + i));

}


int poz(int var)
{
	int ok = 1;
	if (var >= 0)
		ok = 1;
	else
		ok = 0;

	return ok;
}


void sortare(int* M, int n)
{
	int i, j, aux;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (*(M + i) > *(M + j))
			{
				aux = *(M + i);
				*(M + i) = *(M + j);
				*(M + j) = aux;

			}

		}

	}

}


void element_sters(int* M, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		printf("%d ", *(M + i));

}


void biti(int* M, int n)
{
	int i, j, nr, k, contor;
	for (i = 0; i < n; i++)
	{
		contor = 0;
		nr = *(M + i);
		for (j = 31; j >= 0; j--)
		{
			k = (nr >> j) & 1;
			if (k == 1)
				contor++;
		}

		if (contor == 1)
			printf("%d ", *(M + i));

	}


}



int main()
{
	int optiune, n;
	int* M;


	printf("dati numarul de elemente din multime: ");
	scanf("%d", &n);


	M = (int*)malloc(n * sizeof(int));


	if (M == NULL)
	{
		printf("eroare de alocare");
		exit(0);
	}

	citire(M, n);


	do
	{
		printf("\n|0.iesire");
		printf("\n|1.afisare");
		printf("\n|2.stergere");
		printf("\n|3.putere 2\n");

		printf("optiunea selectata este: \n");
		scanf("%d", &optiune);

		switch (optiune)
		{
		case 0:free(M);
			exit(0);
			break;
		case 1:sortare(M, n);
			afisare(M, n);
			break;
		case 2:element_sters(M, n);
			break;
		case 3:biti(M, n);
			break;
		default:printf("optiune gresita \n");
			break;
		}
	} while (1);


	return 0;
}