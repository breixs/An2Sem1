#include <stdio.h>
// Să se scrie un program în C care citește de la tastatură un şir de numere încheiat cu numărul 0 şi afișează maximul dintre numerele introduse
int main()
{
	int n, p = 1;
	printf("n=");
	scanf("%d", &n);
	while (n != 0)
	{
		if (n % 2 == 0)
		p = p * (n % 10);
		n = n / 10;
		printf("%d", p);
	}
	return 0;
}