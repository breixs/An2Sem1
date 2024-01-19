#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
	int ch, n;
	
	printf("introduce tasta corespunzatoare variantei:");
	scanf("%d", &ch);
	printf("\nintroduce numarul:");
	scanf("%d", &n);

	if (ch = "1")
	{
		int i = 0, r;
		while (n != 0)
		{
			r = n % 10;
			i = i * 10 + r;
			n /= 10;
		}
		printf("Inversul numarului: %d", i);
		
	}
	if (ch = "2")
	{
		int x, i = 0, p = 0;
		for (i = 0; i < n; i++) 
			{
			scanf("%d", &x);
			if ((x % 2) != 0)

			continue;

			p++;
			}
			printf("nr pare= %d \n""nr impare= %d", p, n - p);
			

	}
	return 0;
}
