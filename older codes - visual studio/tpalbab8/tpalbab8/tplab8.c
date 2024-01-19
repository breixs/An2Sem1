#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* f_in;
	FILE* f_out;
	int nr, i, n=0;
	if ((f_in = fopen("in.txt", "r")) == NULL) 
	{
		printf("amogus");
		return -1;
	}
	if ((f_out = fopen("out.txt", "w")) == NULL)
	{
		printf("amogus");
		fclose(f_in);
		return -1;
	}
	/*while (!feof(f_in)) {
		fscanf(f_in, "%d", &nr);
		n++;
	}*/
	//printf("%d\n", n);
	while((fscanf(f_in, "%d", &nr))!=EOF)
	{
		if (nr < 1000)
			nr = nr + 0.15 * nr;
		printf("%d\n", nr);
		fprintf(f_out,"%d\n", nr);
	}
	fclose(f_in);
	fclose(f_out);
	return 0;
}