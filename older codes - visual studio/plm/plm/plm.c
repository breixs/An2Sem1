#include <stdio.h>

int main()
{
	int a, b, opt;
	printf("a= ");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("Optiunea:");
	scanf("%d", &opt);
	switch (opt)
	{
	case 1: printf("%d", a + b);
		break;
	case 2: printf("%d", a - b);
		break;
	case 3: printf("%d", a * b);
		break;
	case 4: printf("%d", a / b);


	}

	return 0;
}

		

