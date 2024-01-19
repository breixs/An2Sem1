#include<stdio.h>
#include<stdlib.h>

int main()
{
	int opt, n, i, j, v[100][100];
	
	do
	{
		printf("\n optiunea:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
		
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					printf("%d\t", v[i][j]);
			
			}
			break;
		
		case 2:
		
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i == j)
						printf("%d\t", v[i][i]);

			}
			break;
		
		case 3:
		
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i == j)
						printf("%d\t", v[i][n - 1 - i]);

			}
			break;

		
		case 4:
		
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i < j)
						printf("%d\t", v[i][i]);

			}
			break;
		
		case 5: 
		

			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i > j)
						printf("%d\t", v[i][n - 1 - i]);

			}
			break;
		
		case 6:
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i+ j < n - i)
						printf("%d\t", v[i][n - 1 - i]);
				
			}
			break;
		
		case 7:
			printf("n=");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &v[i][j]);

			for (i = 0; i < n; i++)
			{
				printf("\n");

				for (j = 0; j < n; j++)
					if (i + j > n - i)
						printf("%d\t", v[i][n - 1 - i]);

			}
			break;
		
		case 0:
			break;
		
		}

	} while (opt != 0);

	return 0;
}
