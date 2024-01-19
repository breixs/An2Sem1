#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void strlenFake(int sir2[], int n)
{
	int i;
	int k = 0;
	for (i = 0; i < n; i++)
		k++;

	printf("%d", k);
}

int main()
{
	int i, k = 0, n;
	char sir2[] = "student";
	n = strlen(sir2);
	printf("%d", n); printf("\n");
	
	strlenFake(sir2, n);
	return 0;

}