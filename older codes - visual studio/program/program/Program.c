#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, i, j=1;
	printf("n=");
	scanf("%d", &n);
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			j = 0;
			break;
		}
	}
	if (n <= 1)
		j = 0;
	if (j==0)
		printf("nr nu e prim");
	else
		printf("nr e prim");
	
	return 0;
}