#include <stdio.h>

/*int main()
{
	//3.5
	int i, v[] = { 7, -5, 4, 3, -9, 2, -8 };
	int* p;
	int* n = &v[7];
	int* min = &v[0];
	p = v;
	for (p; p < n; p++)
		if (*p < *min)
			*min = *p;
	printf("%d ", *min);
	return 0;
}*/
/*int main()
{
//3.5 test fara pointeri
	int i, v[] = { 7, -5, 4, 3, -9, 2, -8 };
	int min = v[0];
	for (i = 0; i < 7; i++)
	{
		if (v[i] < min)
			min=v[i];
	}
		printf("%d", min);
	return 0;
}*/
int main()
{
	//3.6
	int n, i, j, v[10];
	int* p, aux, *q;
	p = v;

	do {
		printf("n=");
		scanf("%d", &n);
	} while (n > 10);

	for (i = 0; i < n;i++) {
		scanf("%d", p);
		p++;
	}
	p = v;
	printf("vect normal: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("\n");

	for (p = v; p < v + n - 1; p++) 
		for (q = p + 1; q < v + n; q++) 
			if (*p < *q) 
			{
				aux=*p;
				*p= *q;
				*q = aux;
			}
	p = v;
	printf("\nvect sortat desc: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;
	}
	return 0;

}