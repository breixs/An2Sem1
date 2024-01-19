#include <stdio.h>
#include <string.h>

int main()
{
	char v[300], n=0, i, j;
	gets_s(v, 300);
	printf("%d", v);
	for (i = 0; i < strlen(v); i++)
		n++;
	printf("\n");
	printf("%d", n);
	return 0;
} 