#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

	char nume[30];
	int varsta;
	float mediaGenerala;

}Elev;

void citeste(Elev* l, int* n) {
	
	char nume[30]; int i, v, okn = 0, okv=0;
	printf("Introduceti numele elevului: "); scanf("%s", nume);
	printf("Introduceti varsta elevului: "); scanf("%d", &v);

	for (i = 0; i <= n; i++)
	{
		if (((l + 0) >= 'A') && ((l + 0) <= 'Z'))
			okn = 1;
		else
			okn = 0;
	}

	for (i = 0; i <= n; i++)
	{
		if ((v >= 8) && (v <= 17))
			okv = 1;
		else
			okv = 0;
	}

	if ((okn == 0) || (okv==0))
	{
		printf("Introduceti numele elevului: "); scanf("%s", nume);
		printf("Introduceti varsta elevului: "); scanf("%d", &v);

	}


}

void afiseaza(Elev* l, int* n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		printf("Nume elev: %s\n", (l + i)->nume);
		printf("varsta: %d\n", (l + i)->varsta);
		printf("media: %f\n\n", (l + i)->mediaGenerala);
	}

}

int main()
{
	Elev l[100];
	int opt, n;
	do 
	{
		printf("opt\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			citeste(l, &n);
			break;

		case 2:
			afiseaza(l, &n);
			break;

		case 0:
			break;
		}
	} while (opt != 0);

	return 0;

}