#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#define citire(a) gets(a)
#define scrie(a) printf("%s", a)

/*int main()
{
	char* ptr;
	char s[300], max[300] = "";
	citire(s);
	s[strlen(s) - 1] = '\0';
	ptr = strtok(s, " ");
	while (ptr != NULL)
	{
		if(strlen(ptr) > strlen(max))
			strcpy(max, ptr);
		ptr = strtok(NULL, " ");
	}
	scrie(max);
	return 0;
}*/

#define max 10000
int main()
{
	int v[max], i, n, j;
	v[0] = v[1] = 0;
	for (i = 2; i < max; i++)
		v[i] = 1;
	for (i = 2; i * i < max; i++)
		if (v[i] == 1)
			for (j = i; j * i < max; j++)
				v[i * j] = 0;
	do 
	{
		scanf ("%d", &n);
	} while (n != 0);
}