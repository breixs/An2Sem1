#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Espressor{

	char brand[30];
	int nr_functii;
	float pret;
}esp;


void citeste(esp* e, int* n) 
{
    
    char brnd[30]; float p; int nr, i;

    printf("Introduceti brand: "); scanf("%s", brnd);
    printf("Introduceti pretul: "); scanf("%f",&p);
    printf("Introduceti nr functii: "); scanf("%d", &nr);

    (*n)++;
    strcpy((e + *n)->brand, brnd);
    (e + *n)->pret = p;
    (e + *n)->nr_functii = nr;
}

void afisare(esp* e, int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        printf("%s\n", (e + i)->brand);
        printf("%f\n", (e + i)->pret);
        printf("%d\n\n", (e + i)->nr_functii);
    }

}

int main() 
{
    int n=-1, opt;
    esp e[100];

    do {

        printf("meniu \n");
        printf("alege opt \n");
        scanf("%d", &opt);
         
        switch (opt)
        {
        case 1:
            citeste(e, &n);
            break;

        case 2:
            afisare(e, n);
            break;

        case 0:
            break;
        }

    } while (opt!= 0);

    return 0;
}

