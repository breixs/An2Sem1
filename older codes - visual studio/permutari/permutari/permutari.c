#include <stdio.h>

int st[100], n;
int validare(int k)
{
	int i, ok = 1;
	for (i = 1; i <= k-1; i++)
	{
		if (st[k] == st[i])
			ok = 0;
	}
	return ok;
}
int afisare(int k)
{
	for (int i = 1; i <= k; i++)
		printf("%d ", st[i]);
	printf("\n");
}
void backtrack(int k)
{
	for (int i = 1; i <= n; i++)
	{
		st[k] = i;
		if (validare(k))
			if (k == n)
				afisare(k);
			else
				backtrack(k + 1);
	}
}
int main()
{
	printf("n=");
	scanf("%d", &n);
	backtrack(1);
	return 0;
}