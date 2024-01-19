#include <stdio.h>
#include <stdlib.h>

int cautareLiniara(char* v, int n, char caracter)
{
	int i=0;
	/*while (v[i] != numar && i<n)
		i++;

	return i;
	*/
	for (i = 0; i < n; i++)
		if (caracter == v[i])
			return i;

	return -1;
 }

int main()
{
	char *v, *t;
	int n, index, i, vieti=5, j;
	char car, temp;

	printf("n=");
	scanf("%d", &n);

	v = (char*)malloc(n * sizeof(char));
	t = (char*)malloc(n * sizeof(char));


	for (i = 0; i < n; i++)
	{
		scanf(" %c", &v[i]);
	}

	do {
		printf("char cautat= ");
		scanf(" %c", &car);

		index = cautareLiniara(v, n, car);
		//printf("%d", index);

		if (index == -1) {
			printf("nr nu exista");
			vieti--;
		}
		else
		{
			do{
				switch (index) {
				case 0: 
					printf("carcaterul cautat %c se afla pe pozitia %d", car, index); printf('\n');
					for(j=0;j<n;j++)
						*(t+0) = car;
					break;
				case 1:
					printf("carcaterul cautat %c se afla pe pozitia %d", car, index); printf('\n');
					for (j = 0; j < n; j++)
						t[1] = car;
					break;
				case 2:
					printf("carcaterul cautat %c se afla pe pozitia %d", car, index); printf('\n');
					for (j = 0; j < n; j++)
						t[2] = car;
					break;
				case 3:
					printf("carcaterul cautat %c se afla pe pozitia %d", car, index); printf('\n');
					for (j = 0; j < n; j++)
						t[3] = car;
					break;
				case 4:
					printf("carcaterul cautat %c se afla pe pozitia %d", car, index + 1); printf('\n');
					for (j = 0; j < n; j++)
						t[4] = car;
					break;
				
				}
			} while (t[j] == v[i]);
		}
		if ((t[j] == v[i]))
			break;
	} while (vieti != 0);

	if (vieti == 0)
	{
		printf("\njocul s-a terminat");
	}
	for (j = 0; j < n; j++)
		printf("%c", t[j]);

	return 0;
}