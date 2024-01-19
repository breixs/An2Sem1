#include <stdio.h>
#include <math.h>
//produsul cifrelor pare dintr-un numar
int main(void)
{
	int n, p=1;
	printf("n=");
	scanf("%d", &n);
	while (n != 0)
	{
		if (n % 2 == 0) //vedem daca numarul e par
			p = p * (n % 10);
		
		n = n / 10;//luam fiecare cifra pe rand a lui n si aflam produsul
		
	}

	if (p == 1)//daca nu exista numere pare, produsul va fi tot timpul 1=>nr impar
		printf("numarul nu are cifre pare");
	else
	{
		printf("%d", p);
		printf("\n");
	}
	return 0;
}