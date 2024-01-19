#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CautareLiniara(char T[], int n, char P[], int m)
{
	int i, j, k;
	i = 0; j = 0;
	while (i <= n-m+1) { //sau(i<n)
		k = i;
		j = 0;
		while (j < m)
		{
			if (T[k] != P[j])
				break;
			j++;
			k++;
		}
		if (j == m)
			return i;
		else
			i++;
	}
	return -1;
}

void TP(char P[], int m, int F[]) //TP=tabela prefixe
{
	int i=1, j=0;
	F[0] = 0;
	while (i < m) {
		if (P[i] == P[j])
		{
			F[i] = j + 1;
			i++;
			j++;
		}
		else
			if (j > 0)
				j = F[j - 1];
			else
			{
				F[i] = 0;
				i++;
			}
	}
}

int KMP(char T[], int n, char P[], int m, int F[])
{
	int i=0, j=0;
	TP(P, m, F);
	while (i < n)
	{
		if (T[i] == P[j])
		{
			if (j == m - 1)
				return i - j;
			i++; j++;
		}
		else 
		{
			if (j > 0)
				j = F[j - 1];
			else
				i++;
		}
	}
	return -1;
}

int BM(char T[], int n, char P[], int m)
{
	int d[256];
	int i, j, k;
	for (i = 0; i < 256; i++)
		d[i] = m;
	for (i = 0; i < m-1; i++)
		d[P[i]] = m - i;
	i = m-1; j = m-1;
	while (i<n)
	{
		k = i; j = m - 1;
		while (j >= 0)
		{
			if (T[k] != P[j])
				break;
			k--; j--;
		}
		if (j == -1) 
			return k + 1;
		i = i + d[T[i]]-1;
	}
	return -1;
}

int main()
{
	char T[50] = "abababcad";
	char P[20] = "abcad";
	int m, n;
	int F[20], i;
	m = strlen(P);
	n = strlen(T);
	int poz = CautareLiniara(T, n, P, m);
	printf("pozCL=%d\n", poz);
	TP(P, m, F);
	for (i = 0; i < m; i++)
	{
		printf("%d", F[i]);
	}
	printf("\n");
	poz = KMP(T, n, P, m, F);
	printf("KMP=%d\n", poz);
	poz = BM(T, n, P, m);
	printf("%d\n", poz);
	return 0;
}