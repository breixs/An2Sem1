#include <stdio.h>
int main()
{
	/*int v[100], i, ,n=4,aux;
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("Vectoru intial:\n");
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(v[i]>v[j])
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;

		}
	printf("\n");
	printf("Vectoru aranjat:\n");
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (v[i] > v[j])
			{
				v[j] = v[j] ^ v[i];
				v[i] = v[i] ^ v[j];
				v[j] = v[j] ^ v[i];

			}
	printf("\n");
	printf("Vectoru aranjat:\n");
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);*/

		/*int nr, i, k, cnt = 0;
		printf("Dati numarul: ");
		scanf("%d", &nr);
		for (i = 31; i >= 0; i--)
		{
			k = nr >> i;
			if (k & 1)
				cnt++;

		}

		printf("\n");
		printf("%d", cnt);

		return 0;*/
	int nr, i, k, cnt = 0;
	printf("Dati numarul: ");
	scanf("%d", &nr);
	/*for (i = 31; i >= 0; i--)
	{
		k = nr >> i;
		if (k & 1);
		else
			cnt++;

	}

	printf("\n");
	printf("%d", cnt);

	return 0;*/
	for (i = 31; i >= 0; i--)
	{
		k = nr >> i;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	if (k == 1)
		printf("par");
	else
		printf("impar");
}