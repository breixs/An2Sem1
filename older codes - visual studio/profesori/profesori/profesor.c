#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Profesor
{
	char nume[30];
	int salar;
	float  grad_didactic[30];

}Profesor;

void citire(Profesor* p, int* n)
{
	char nume[30]; int i, s=0, g=0, okp = 0, oks=0;
	 {
		(*n)++;
		printf("numele profului: "); scanf("%s", &(p + *n)->nume);
		printf("salar: "); scanf("%d", &(p + *n)->salar, s);
		printf("gradul: "); scanf("%f", &(p + *n)->grad_didactic, g);

		for (i = 0; i <= n; i++)
		{
			if (((p + 0) >= 'A') && ((p + 0) <= 'Z'))
				okp = 1;
			else
				okp = 0;

			if ((s >= 2500) && (s <= 7000))
				oks = 1;
			else
				oks = 0;
		}
	} while ((oks == 0) || (okp == 0));

}

void afisare(Profesor* p, int* n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		printf("Nume prof: %s\n", (p + i)->nume);
		printf("salar: %d\n", (p + i)->salar);
		printf("grad: %s\n\n", (p + i)->grad_didactic);
	}
}



int main()
{
	Profesor p[100];
	int n;

	citire(p, &n);
	afisare(p, n);
	

	return 0;

}