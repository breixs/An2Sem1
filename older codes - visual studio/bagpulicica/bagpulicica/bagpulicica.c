//Fie un ?ir format din n nume de ??ri, date de utilizator de la tastatur?.
//Realiza?i un meniu interactiv cu urm?toarele op?iuni :
//0. Ie?ire
//1. Afi?area ??rilor în ordine invers alfabetic?.
//2. S? se copieze într - un vector primul caracter din numele ??rilor, apoi s? se afi?eze
//pe ecran.
//3. S? se afi?eze reprezentarea binar? a lungimii fiec?rei ??ri.Se vor utiliza opera?ii
//pe bi?i pentru aflarea valorilor bi?ilor.
//Observa?ii:
//-Se va utiliza alocarea dinamic? de memorie;
//-Pentru fiecare func?ionalitate se va crea o func?ie;
//-Numele ??rii este considerat citit corect dac?, are cel pu?in 3 caractere, prima
//liter? este liter? mare ?i restul sunt litere mici;
//-Prima ?ar? este dat? automat, fiind egal? cu “Franta”.
//- Problema se va rezolva folosind ?iruri de ?iruri de caractere.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int validare(char* n)
{
	int i, k = 0;
	if (!(n[0] >= 'A' && n[0] <= 'Z'))
		return 0;
	else {
		for (i = 1; i < strlen(n); i++)
			if (!(n[i] >= 'a' && n[i] <= 'z'))
				return 0;
			else k++;

	}


	if (k < 2)
		return 0;
	else return 1;
}
void citire(char** s, int n)
{
	int i;
	char* nume;
	nume = (char*)malloc(sizeof(char) * 20);
	s[0] = (char*)malloc(sizeof(char) * strlen("Franta"));
	strcpy(s[0], "Franta");
	for (i = 1; i < n; i++) {
		do {
			printf("Dati tara(%d):", i);
			getchar();
			scanf("%s", nume);
		} while (validare(nume) == 0);
		s[i] = (char*)malloc(sizeof(char) * strlen(nume) + 1);
		strcpy(s[i], nume);
	}
}
void afisare(char** s, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %s ", *(s + i));
}

void sort(char** s, int n)
{
	char* aux;
	aux = (char*)malloc(sizeof(char) * 20);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (strcmp(*(s + i), *(s + j)) == 1)
			{
				strcpy(aux, *(s + i));
				strcpy(*(s + i), *(s + j));
				strcpy(*(s + j), aux);
			}

	}
	afisare(s, n);
}
void vector(char** s, int n)
{
	int i, j, k = 0;
	char V[20];


	for (i = 0; i < n; i++) {
		for (j = 0; j < 1; j++)

			V[k] = s[i][0];
		k++;
	}
	for (i = 0; i < k; i++)
		printf(" %c ", V[i]);
}
void binar(char** s, int n)
{
	int i, j, aux, k;
	for (i = 0; i < n; i++) {
		printf("%s  ", s[i]);
		k = strlen(s[i]);
		printf(" %d ", k);
		aux = ceil(log2(k));
		for (j = aux; j >= 0; j--) {
			if ((k >> j) & 1 == 1)
				printf("1");
			else printf("0");
		}

		printf("\n");



	}
}
int main() {
	int opt, n;
	char** Tara;
	printf("Dati numarul de tari:");
	scanf("%d", &n);
	Tara = (char**)malloc(n * sizeof(char*));
	citire(Tara, n);
	while (1) {
		printf("\n0.Iesire\n");
		printf("1. Afi?area ??rilor în ordine invers alfabetic?.\n");
		printf("2. S? se copieze într - un vector primul caracter din numele ??rilor\n");
		printf("3. S? se afi?eze reprezentarea binar? a lungimii fiec?rei ??ri\n");
		printf("Dati optiunea:\n");
		scanf("%d", &opt);
		switch (opt) {
		case 0:exit(0);
			break;
		case 1:sort(Tara, n);
			break;
		case 2:
			vector(Tara, n);
			break;
		case 3: binar(Tara, n);
			break;
		}

	}
	return 0;
}