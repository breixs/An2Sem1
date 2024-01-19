#include <stdio.h>
#include <stdlib.h>

void sortare(int v[], int n)
{
	int i, j, aux;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);


}

int cautare_liniara(int v[], int n, int nr)
{
	int i;
	for (i = 0; i < n; i++)
		if (nr == v[i])
			return i;
	return -1;
}

int tehnica_fanionului(int v[], int n, int nr)
{
	int i=0;
	for (i = 0; i < n + 1; i++)
	{
		v[n] = nr;
		while (v[i] != nr)
			i++;
		return i;
	}
	return -1;

}

int cautare_binara(int v[], int n, int nr)
{
	int s=0, d=n-1, m;
	while (s <= d) {
		m = (s + d) / 2;
		if (v[m] == nr)
			return m;
		else if (v[m] > nr)
			d = m - 1;
		else
			s = m + 1;
	}
	return -1;


}

int cautare_interpolara(int v[], int n, int nr)
{
	int s, d, m = -1;
	s = 0; d = n - 1;
	if (nr >= v[s] && nr <= v[d]) {
		do {
			m = s + (nr - v[s]) * (d - s) / (v[d] - v[s]);
			if (nr > v[m]) 
				s = m + 1;
			else 
				d = m - 1;
		} while (v[m] != nr && s < d && nr <= v[d] && nr >= v[s] && v[d] != v[s]);
	}
	return m;
}

int main()
{
	int n=7, nr, index, opt ;
	int v[] = { 2, 3, 8, 5, 10, 88, 43, -1 };

	printf("introdu nr cautat:");
	scanf("%d", &nr);

	do {
		printf("opt=");
		scanf("%d", &opt);
		switch(opt)
		{
		case 1:
			index = cautare_liniara(v, n, nr);
			if (index != -1)
				printf("\nnumarul %d se afla pe pozitia %d\n", nr, index+1); 
			else
				printf("\nnr nu exista\n");
			break;
		case 2:
			index = tehnica_fanionului(v, n, nr);
			if (index != -1)
				printf("\nnumarul %d se afla pe pozitia %d\n", nr, index+1);
			else
				printf("\nnr nu exista\n");
			break;
		case 3:
			index = cautare_binara(v, n, nr);
			if (index != -1)
				printf("\nnumarul %d se afla pe pozitia %d\n", nr, index + 1);
			else
				printf("\nnr nu exista\n");
			break;
		case 4:
			sortare(v, n);
			index = cautare_interpolara(v, n, nr);
			if (index != -1)
				printf("\nnumarul %d se afla pe pozitia %d\n", nr, index + 1);
			else
				printf("\nnr nu exista\n");
			break;
		case 0:
			break;
		default:
			break;
		}

	} while (opt != 0);

	return 0;

}