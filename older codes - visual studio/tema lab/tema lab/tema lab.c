#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	 double a, b, c, d, x1, x2;
	printf("valoarea lui a=");
	scanf("%lf", &a);
	printf("valoarea lui b=");
	scanf("%lf", &b);
	printf("valoare lui c=");
	scanf("%lf", &c);
	printf("\n %lf %lf %lf", a, b, c);
	d = (pow(b,2)) - (4 * (a * c));
	printf("\n %lf", d);
	printf("\n %lf", sqrt(d));
		if (d < 0)
		{
			printf("ecuatia nu are solutii reale");
		}
		if (d > 0)
		{
			x1 = ((-b) + sqrt(d)) / (2 * a);
			x2 = ((-b) - sqrt(d)) / (2 * a);
			printf("\n x1=%lf", x1);
			printf("\n x2=%lf", x2);
		}
		if (d == 0)
		{
			x1 = ( - b) / (2 * a);
			printf("rezultatul este:%lf", x1);
		}
	
	return 0;
}






