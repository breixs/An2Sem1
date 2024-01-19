#include <stdio.h>
//se citesc n,m de la tastaura, sa se afiseze primii n multiplii a lui n
int main()
{
	int n, m, i;
	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", & m);
	for ( i = 1; i <= n; i++)
	{
		printf("%d ", i * m);
	}

	return 0;
}
