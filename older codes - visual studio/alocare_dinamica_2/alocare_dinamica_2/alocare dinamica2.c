#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define esteok(c) ((c>='a' && c<='z') || (c>='0' && c<='9'))

void citire(char* m, int n)
{
	int i, ok=1;
	do {
		printf("caractere:\n");
		for (i = 0; i < n - 1; i++)
		{
			*(m + (n - 1)) = 'e';
			
				getchar();
				scanf("%c", (m + i));
				if (esteok(*(m + i)))
				{
					ok = 1;
					continue;
				}
				else
				{
					ok = 0;
					printf("citire incorecta\n");
					break;
					
				}
		}
	} while (ok == 0);

}
void afisare(char* m, int n)
{
	int i, j, aux;

	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((*(m + j)) > (*(m + i)))
			{
				aux = *(m + j);
				*(m + j) = *(m + i);
				*(m + i) = aux;
			}

		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", *(m + i));
	}

}
void stergere(char* m, int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		printf("%c", *(m + i));
	}
}
/*int validare(char* m, int n)
{
	int i, ok=1;
	for (i = 0; i < n; i++)
	{
		if (esteok(*(m + i)))
		ok = 1;
		else
		{
			ok = 0;
			printf("citire incorecta\n");
			break;
		}
	}
}*/

int main()
{
	int n, opt=0;
	char* m;
	 do
	 {
		printf("nr de elemnte:");
		scanf("%d", &n);
	 } while (n < 6);
	m = (char*)malloc(n * sizeof(char));

	if(m == NULL)
	{
		printf("help");
		exit(0);
	}

	citire(m, n);


	do {
		printf("\nmeniu:\n");
		printf("1:desc:\n");
		printf("2:stergere primul element:\n");
		printf("0:iesire:\n");
		printf("opt:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: 
			afisare(m, n);
			break;
		case 2:
			stergere(m, n);
			break;
		case 0:
			break;
		}

	} while (opt != 0);

	free(m);
	return 0;
}
