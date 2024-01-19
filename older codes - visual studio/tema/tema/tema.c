#include <stdio.h>

int main(void)
{
	int v[1000];
	int max, min, i, k, mins, maxs;

	scanf("%d", &k);

	scanf("%d", &v[0]);

	max = v[0];

	min = v[0];

	for (i = 1; i < k; i++)
	{
		scanf("%d", &v[i]);
		if (v[i] > max) 
		{
			max = v[i];
		}
		if (v[i] < min)
		{
			min = v[i];
		}
		
	}
	maxs = mins = 0;

	for(i = 0; i < k; i++) 	
	{
		if (v[i] > min)
		{
			mins = mins + v[i];
		}
		if (v[i] < max)
		{
			maxs = maxs + v[i];

		}
	}
	printf("Optiunea 1:%d\nOptiunea 2:%d\n",mins, maxs);
	
	return 0;
}
