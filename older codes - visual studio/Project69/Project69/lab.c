#include <stdio.h>

int main(void)
{
	float a, b, c;
	char ch;

	printf("\nmeniu:");
	scanf('%c' & ch);

	if (ch == 1)
	{
		printf("Introdu 2 numere intregi:");

		scanf('%d' &a);
		scanf('%d' &b);
		a + b = c;
		printf("suma: %d", &c);

	}
	else if (ch == 2)
	{
		a - b = c;
		printf("diferenta: %d" &c);

	}
	else if (ch == 3)
	{
		a * b = c;
		printf("produs: %d" &c);

	}
	else if (ch == 4)
	{
		a / b = c;
		printf("impartire: %d" &c);

	}
	return 0;

}
