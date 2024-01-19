#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define esteok(n) (n<=100) && (n>=0)

void citire(int* m, int n)
{
	int i,ok;
	do {
		for (i = 0; i < n; i++)
		{
			printf("[%d] = ", i);
			scanf("%d", (m + i));

			if (*(m + i)>=0 && *(m+i)<=100)
			{
				ok = 1;
				continue;
			}
			else
			{
				ok = 0;
				printf("citire incorecta \n");
			}
		}
	} while (ok == 0);
}

void afisare(int* m, int n)
{
	int i, j = 0, aux;
	printf("vector initial:");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(m + i));
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((*(m + i)) > (*(m + j)))
			{
				aux = *(m + i);
				*(m + i) = *(m + j);
				*(m + j) = aux;
			}

		}
	}
	printf("\n");
	printf("vector sortat cresc:");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(m + i));
	}
	 
	printf("\n");
}

void multipla(int* m, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if ((*(m + i)) == (*(m + j)))
				printf("Elemete care se repeta :%d", *(m + i));
	printf("\n");
}

void biti(int* m, int n)
{
	int i, j, bit;
	for (i = 0; i < n; i++)
		for(j=i-1; j<n; j++)
		{
			if (*(m+i)==0 || (*(m + i)) & (*(m + j))==0)
			{
				printf("%d", *(m + i));
			}
		}
}


int main()
{
	int n, opt;
	int* m;

	printf("nr de elemente:");
	scanf("%d", &n);

	m = (int*)malloc(n * sizeof(int));

	if (m == NULL)
	{
		printf("amogus");
		exit(0);
	}

	citire(m, n);

	do{
		printf("\nopt:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: 
			afisare(m, n);
			break;
		case 2:
			multipla(m, n);
			break;
		case 3:
			biti(m, n);
			break;
		case 0: 
			break;
			free(m);
			exit(0);
		default:
			break;
			free(m);
			exit(0);

		}
	
	} while (opt != 0);

	free(m);
	return 0;
}
