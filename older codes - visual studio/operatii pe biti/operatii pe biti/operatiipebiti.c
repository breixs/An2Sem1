#include <stdio.h>

int main()
{
	int a, b, i;
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);

	/*for (i = 7; i >= 0; i--)
	{
		if (i == b)
			printf("%d", (a>>i) |1);
		else
			printf("%d", (a>>i) &1);
	}*/
	for (i = 8; i >= 0; i--)
	{
		printf("%d", (a >> i)&1);
	}
	printf("\n");
	/*for (i = 8; i >= 0; i--)
	{
		printf("%d", (a >> i) & 1 | (i==b));
	}*/

	a = a | (1 << b); //setare pe 1
	//a = a & ~(1 << b); //setare pe 0

	for (i = 8; i >= 0; i--) {
		printf("%d", (a >> i) & 1);
	}
	return 0;
}