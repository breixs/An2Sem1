#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v[] = { 7, -5, 4, 3, -9, 2, -8 };
	int* p;
	int contor=0, i;
	p = v;
	for (i=0;i<7;i++)
	{
		if (*p < 0)
			contor++;
		p++;
	}
		printf("in vector sunt %d elemente negative", contor);

	return 0;
}