#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ordonare(char** v, int n)
{
    char x[25], aux;
    int i, j, nr, nr2;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (strlen(v[i]) > strlen(v[j]))
            {
                strcpy(x, v[i]);
                strcpy(v[i], v[j]);
                strcpy(v[j], x);
            }
    }
    for (i = 0; i < n; i++)
        printf("%s ", v[i]);
    printf("\n");
}
void copiere(char** v, int n)
{
    int i, j, k = 1;
    char* x;
    x = (char*)malloc(n * sizeof(char));
    for (i = 0; i < n; i++) {
        for (j = 0; v[i][j] != '\0'; j++)
            if ((v[i][j] == 'a' || v[i][j] == 'e' || v[i][j] == 'i' || v[i][j] == 'o' || v[i][j] == 'u') && k == 1)
            {
                x[i] = v[i][j];
                k = 0;
            }
        k = 1;
    }
    for (i = 0; i < n; i++)
        printf("%c ", x[i]);
    printf("\n");
    free(x);
}
void binar(char** v, int n)
{
    int i, j, l, k = 1, x, y;
    for (i = 0; i < n; i++)
    {
        for (j = 0; k == 1 && (v[i][j] != ' ' || v[i][j] != '\0'); j++)
            if (v[i][j] == 'a')
            {
                k = 0;
                x = strlen(v[i]);
                for (l = 31; l >= 0; l--)
                {
                    y = x >> l;
                    if (y & 1)
                        printf("1");
                    else printf("0");
                    j++;
                }
            }
        printf(" ");
        k = 1;
    }
    printf("\n");
}

int main() {
    int i, j, n, opt;
    char** v;
    printf("n="); scanf("%d", &n);
    v = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
        v[i] = (char*)malloc(25 * sizeof(char));
    for (i = 0; i < n; i++)
        scanf("%s", v[i]);
    do {
        printf("0.Iesire\n");
        printf("1.Ordonare\n");
        printf("2.Copiere\n");
        printf("3.Binar\n");
        printf("opt="); scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            break;
        case 1:
            ordonare(v, n);
            break;
        case 2:
            copiere(v, n);
            break;
        case 3:
            binar(v, n);
            break;

        default:
            break;
        }
    } while (opt);
    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);
    return 0;
}