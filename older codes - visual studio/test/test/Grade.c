#include<stdio.h>

int main(void);
{
	float cl, fh;
	char ch;

	printf("\n\n Pentru Convertire Din Celsius In Fahrenheit Apasa Tasta c");
	printf("\n\n Pentru Convertire Din Fahrenheit In Celsius Apasa Tasta f");
	printf("\n\n Introduce Tasta:");
		scanf("%c", &ch);
	{

		if ((ch == 'c') || (ch == 'C'));

		printf("\n\n Introduce Temperatura In Celsius:");
		scanf("%f", &cl);
		fh = (cl * 1.8000) + 32;
		printf("\n\n Rezultat : %.2f", fh);
	}
		{

			else if ((ch == 'f')) || (ch == 'F');

			printf("\n\n Introduce Temperatura In Fahrenheit: ");
			scanf("%f", &fh);
			cl = (fh - 32) / 1.8000;
			printf("\n\n Rezultat:%f", cl);
			
		}

			{
				else
				printf("Alegere Nevalida");
			}

	return0;
}