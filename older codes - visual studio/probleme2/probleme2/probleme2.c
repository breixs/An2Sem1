#include <stdio.h>

int main(void)
{
	//Considerăm un șir v cu n elemente întregi. 
	//Să se elimine din șir toate elementele pare.

	int n, v[100], i, j;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (j = n-1; j >= 0; j--)
		if (v[j] % 2 == 0) {
			for (i = j; i <= n-1 ; i++) 
				v[i] = v[i + 1];
				n--;
			
		}
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}