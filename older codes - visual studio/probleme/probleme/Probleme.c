#include <stdio.h>

int main(void)
{
	//Considerăm un șir X cu n elemente întregi. 
	//Să se elimine din șir toate elementele pare.

	int n, v[100], i, j;
	printf("n=");
	scanf("%d", n);
	for (i = 0; i < n; i++)
		if (v[i] % 2 == 0) {
			for (j = i; j < n - 1; j++)
				v[i] = v[i + 1];
		}
	printf("%d", v[i]);

	return 0;
}