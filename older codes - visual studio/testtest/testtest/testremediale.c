#include <stdio.h>
#include <stdlib.h> // pentru malloc, free
#define esteMajuscula(c) (c >= 'A' && c <= 'Z')

void afisare(char** m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void afisareDiag(char** m, int n)
{
    int i, sortat, aux;
    char* v;

    // alocare dinamica vector
    v = (char*)malloc(n * sizeof(char));

    // salvare diagonala principala in vector
    for (i = 0; i < n; i++)
    {
        v[i] = m[i][i];
    }

    // ordonare vector - bubblesort
    sortat = 0;
    while (!sortat)
    {
        sortat = 1;
        for (i = 0; i < n - 1; i++) // v[i] si v[i+1] 
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = 0;
            }
        }
    }

    // afisare vector
    for (i = 0; i < n; i++)
    {
        printf("%c ", v[i]);
    }
    printf("\n");

    free(v);
}

void modificareColturi(char** m, int n)
{
    char c;
    printf("Introduceti un caracter: ");
    scanf("%c", &c);
    getchar();

    m[0][0] = m[0][n - 1] = m[n - 1][0] = m[n - 1][n - 1] = c;
}

int main()
{
    int n, i, j;
    char** mat;
    int opt, valid;
    int meniu = 1;

    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);
    getchar();

    // alocare dinamica matrice
    mat = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
        mat[i] = (char*)malloc(n * sizeof(char));

    // citire matrice
    for (i = 0; i < n; i++)
    {
        mat[i][0] = 'A'; // elementul de pe prima coloana este 'A'
        for (j = 1; j < n; j++) {
            // validare la citire
            do {
                valid = 1;
                printf("mat[%d][%d] = ", i, j);
                scanf("%c", &mat[i][j]);
                getchar();
                if (!esteMajuscula(mat[i][j])) // macroinstructiune
                    valid = 0;
            } while (!valid);
        }
    }

    // meniu
    while (meniu)
    {
        printf("0. Iesire\n");
        printf("1. Afisarea matricei\n");
        printf("2. Afisare diagonala principala ordonata\n");
        printf("3. Modificarea colturilor matricei\n");
        printf("Introduceti optiunea: ");
        scanf("%d", &opt);
        getchar();

        switch (opt)
        {
        case 0:
            meniu = 0;
            break;
        case 1:
            afisare(mat, n);
            break;
        case 2:
            afisareDiag(mat, n);
            break;
        case 3:
            modificareColturi(mat, n);
            break;
        default:
            printf("Optiune gresita!\n");
            break;
        }

    }

    // eliberarea memoriei
    for (i = 0; i < n; i++)
        free(mat[i]);

    free(mat);

    return 0;
}