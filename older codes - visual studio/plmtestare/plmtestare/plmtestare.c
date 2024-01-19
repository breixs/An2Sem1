#include <stdio.h>
#include <stdlib.h>

typedef struct filme {
    char nume_film[10];
    char nume_user[10];
    int nota1; //nota2, nota3;
    float medie;
}fl;

int citire(FILE* p, fl v[])
{
    //char nume_f[10], nume_u[10];
    int i=0;
    p = fopen("vsc.txt", "r");
    if (p == NULL)
    {
        printf("mogus");
        return -1;
    }
    while (!feof(p))
    {
        fscanf(p, "%s; %s; %u", v[i].nume_film, v[i].nume_user, &v[i].nota1);
        i++;
    }
    fclose(p);
    return i;
}

void afisare(FILE* p, fl v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %s %u\n", v[i].nume_film, v[i].nume_user, v[i].nota1);
    }
}

int main()
{
    FILE* p=0 ;
    fl f[100];
    int n;
    n = citire(p, f);
    afisare(p, f, n);
    return 0;

}