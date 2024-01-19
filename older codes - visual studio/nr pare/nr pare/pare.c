#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, x, i=0, p=0;
	printf("nr=");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if ((x % 2) != 0)
		
		continue;
		
		p++;
	}
	printf("nr pare= %d \n""nr impare= %d", p, n - p);
	return 0;
}