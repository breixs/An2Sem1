#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int v[10], n, i, aux=0, sortat=0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("v[%d]", i);
		scanf("%d", &v[i]);
	}
	while (!sortat)
	{
		sortat = 1;
		for (i=0; i<n; i++)
		{
			if (v[i] < v[i+1])
			{
				aux = v[i+1];
				v[i+1] = v[i];
				v[i] = aux;
				sortat = 0;
			}
			
		}
	}
	for (i = 0; i < n; i++)
		printf("%d", v[i]);

	return 0;
}