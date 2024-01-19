#include <stdio.h>

int main()
{
	int n = 3;
	FILE* f;
	f = fopen("wtf.bin", "wb");
	fwrite(&n, sizeof(int), 1, f);
	fclose(f);
	return 0;
}