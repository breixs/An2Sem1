#include <stdio.h>

void citeste(int m[20][20], int n)
{
	int i, j;
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			printf("[%d][%d] = ", i, j);
			scanf("%d", &m[i][j]);
		}
}


int main()
{
	int n, i, j, m[20][20];
	printf("n=");
	scanf("%d", &n);
	
	citeste(m, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}

	return 0;

}