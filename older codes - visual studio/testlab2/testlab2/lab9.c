#include <stdio.h>
int Ad(int L, int l)
{
	int Ad;
	Ad = L * l;
	return Ad;
}
int main(void) 
{
	int opt, a, L, l;
	do {
		scanf("%d", &opt);
		switch(opt)
		{
		case 1:
			scanf("%d", &L);
			scanf("%d", &l);
			printf("%d", Ad(L, l));
		}
	} while (opt != 0);
	



}