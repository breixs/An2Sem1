#include <stdio.h>
#include <stdlib.h>

typedef struct filme{
    char nume_film[32], nume_user[32];
    int nota;
}fl;

int citire(FILE *f, fl a[100][100])
{
    int i=0, j=0;
    f=fopen("vsc.txt", "r");
    if(f==NULL)
    {
        printf("mogus");
        return -1;
    }
    while(!feof(f))
    {
        fscanf(f,"%[^;];", a[i][j].nume_film);
        j++;
        fscanf(f,"%[^;];", a[i][j].nume_user);
        j++;
        fscanf(f, "%u;", &a[i][j].nota);
        i++;
        j=0;
    }
    return i;
}

void alocare_dinamica(int** v, fl a[100][100], int n)
{
    int i, j;
    fl** aux=(int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        aux[i] = (int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            aux[i][j]=a[i][j];
        }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
        free(aux[i]);
    free(aux);
}

int main()
{
    FILE* f;
    fl a[100][100];
    int i, j, k, n;
    int** v = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        v[i] = (int*)malloc(n * sizeof(int));

    n=citire(f, a);
    alocare_dinamica(v, a, n);
    
    for(int i=0;i<n;i++)
        free(v[i]);
    free(v);
    return 0;
}