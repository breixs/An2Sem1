#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int n;
int obiecte[MAX_N];
int cutie;
int solutie[MAX_N];
int top_solutie[MAX_N];
int top_fill=0;

void backtracking(int idx, int curent_fill)
{
	if (curent_fill > top_fill)
	{
		top_fill = curent_fill;
		for (int i = 0; i < idx; i++)
			top_solutie[i] = solutie[i];
	}

	if (idx >= n)
	{
		return;
	}
	backtracking(idx + 1, curent_fill);

	if (curent_fill + obiecte[idx] <= cutie)
	{
		solutie[idx] = 1;
		backtracking(idx + 1, curent_fill + obiecte[idx]);
		solutie[idx] = 0;
	}
}

int main()
{
	printf("nr obiecte:");
	scanf("%d", &n);

	printf("volumul obiectelor");
	for (int i = 0; i < n; i++)
		scanf("%d", &obiecte[i]);

	printf("volumul cutiei");
	scanf("%d", &cutie);

	backtracking(0, 0);

	printf("Obiectele care trebuie adaugate in cutie pentru umplerea optima:\n");
	for (int i = 0; i < n; i++) {
		if (top_solutie[i] == 1) 
			printf("%d\n", obiecte[i]);
		
	}

	return 0;
}
