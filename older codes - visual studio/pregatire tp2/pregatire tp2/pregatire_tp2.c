#include <stdio.h>
#include <math.h>
#define pi 3.14

typedef struct Figura {
	int tip;
	union dimensiuni
	{
		float sf_raza;
		int con_raza, con_h;
	}dim;
	float volum;
}fig;

int main()
{
	int putere=0, produs=0, i,j, aux;
	fig f[100];

	for (i = 0; i <= 2; i++)
	{
		scanf("%d", &f[i].tip);
		if (f[i].tip == 1)
		{
			scanf("%f", &f[i].dim.sf_raza);
			//printf("%d\n", f[i].dim.sf_raza);
			//putere = pow(f[i].dim.sf_raza, 3);
			putere = pow(f[i].dim.sf_raza, 3);
			//printf("%d\n", putere);
			f[i].volum = (4 * pi * putere) / 3;
			printf("%f %.2f\n", f[i].dim.sf_raza, f[i].volum);
		}
		else if (f[i].tip == 2)
		{
			scanf("%d %d", &f[i].dim.con_raza, &f[i].dim.con_h);
			produs = f[i].dim.con_raza * f[i].dim.con_h;
			f[i].volum = 0.33 * (3.14 * produs);
			printf("%.2f\n", f[i].volum);
		}
		else if (f[i].tip == 0)
			break;
		else
			printf("Optiune invalida");
	}
	printf("\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = i; j <= 2; j++)
		{
			if (f[i].volum > f[j].volum)
			{
				aux = f[i].volum;
				f[i].volum = f[j].volum;
				f[j].volum = aux;
			}
		}
	}
	for (i = 0; i <= 2; i++)
	{
		printf("%f %.2f ", f[i].dim.sf_raza, f[i].volum);
		printf("\n");
	}
	return 0;
}