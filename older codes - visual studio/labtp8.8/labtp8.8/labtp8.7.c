#include <stdio.h>
#include <string.h>

int main()
{
	FILE* f_in;
	FILE* f_out;
	FILE* append;
	char c[30];
	int n=5;

	if ((f_in = fopen("in.txt", "r")) == NULL)
	{
		printf("amogus");
		return -1;
	}
	if((f_out = fopen("out.txt", "w")) == NULL)
	{
		printf("amogus");
		fclose(f_out);
		return -1;
	}
	/*while ((fgets(c, 200, f_in) != NULL))
	{
		fputs(c, f_out);
	}*/
	while (!feof(f_in))
	{
		fprintf("%c", 34);
		fgets(c, 30, f_in);
		fputs(c, f_out);
		fprintf("%c", 34);

		//fprintf(f_out, "%c", 34);
	}
	//fclose(f_out);
	/*if ((append = fopen("out.txt", "a")) == NULL)
	{
		printf("amogus");
		fclose(append);
		return -1;
	}
	while (!feof(append))
	{
		while(n<=5)
		{
			for (int i = 0; i < n; i++)
			{
				fprintf(append, "%c", 34);
				fprintf(append, "%c", 34);
				n++;
			}
		}
	}*/
	/*printf("%d", n);
	for (int j = 0; j < n; j++)
	{
		//fputc(f_out, 34);
		fputs(c, f_out);
		//fputc(f_out, 34); fprintf(f_out, "\n");
	}*/
	fclose(f_in);
	fclose(f_out);
	//fclose(append);
	return 0;

}