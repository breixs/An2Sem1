#include <stdio.h>
#define MAX 100
int segmente[];
int segment_urma;

int backtracking(int d, int n, int segment_urma, int segment_curent)
{
	if (n == 0)
		return 1;

	int count = 0;

	for (int i = segment_urma + 1; i <= d - segment_curent; i++)
	{
		if(segment_curent<1)
			count += backtracking(d, n - 1, i, segment_curent);
	}
	return count;
}


int main()
{
	int d, n, sol;
	printf("lungimea dreptei");
	scanf("%d", &d);

	printf("nr de segmente");
	scanf("%d", &n);

	sol = backtracking(d, n, 0, 0);

	printf("%d", sol);

	return 0;
}
