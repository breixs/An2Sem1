#include <stdio.h>

int main(void)
{
	int  i, v[200], n=1, opt, p = 1;
	do
	{
		printf("Meniu\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			scanf("%d", &v[i]);
			break;

		case 2:
			for (i = 0; i < n; i++)
				printf("%d", v[i]);
			break;

		case 3:
			for (i = 0; i < n; i += 2)
				printf("%d", v[i]);
			break;
		case 4:
			for (i = 0; i < n; i++)
				if (v[i] % 2 == 1)
					p *= v[i];
			printf("%d", v[i]);
			break;
		default:
			printf("optiune gresita");
			break;
		}
	} while (opt < 5);
}