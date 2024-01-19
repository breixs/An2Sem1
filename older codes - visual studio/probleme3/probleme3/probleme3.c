#include <stdio.h>

int main(void)
{
	int n, uc, pc, s;
	printf("n=");
	scanf("%d", &n);

	uc = n % 10;

	while (n >= 10)
	{
		n/= 10;
	}
	pc = n;

	printf("prima cifra este:%d", pc);
	printf("\n");
	printf("ultima cifra este:%d", uc); printf("\n");
	s = pc + uc;
	printf("suma:%d", s);
	return 0;


}