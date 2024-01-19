#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int main()
{
	int v[MAX], n, i, opt, p = 1;
	printf("nr. de elemente ale vectorului: ");
	scanf("%d", n);
	while (1)
	{
		printf("0.iesire\n");
		printf("1.citire vector\n");
		printf("2.afisare vector\n");
		printf("3.afisare elemente de pe pozitii pare\n");
		printf("4.afisare produs elemente impare\n");
		printf("optiunea dvs este: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1:
			for (i = 0; i < n; i++)
			{
				printf("v[%d]= ", i);
				scanf("%d", v[i]);
			}
			break;
		case 2:
			for (i = 0; i < n; i++)
				printf("%d", v[i]);
			printf("\n");
			break;
		case 3:
			for (i = 0; i < n; i++)
			{
				if (i % 2 == 0)
					printf("%d", v[i]);
			}
			break;
		case 4:
			for (i = 0; i < n; i++)
			{
				if (v[i] % 2 != 0)
					p = p * v[i];
			}
			printf("%d", p);
			break;
		default:
			printf("optiune gresita\n");
			break;
		}
	}



	system("pause");
	return 0;
}


