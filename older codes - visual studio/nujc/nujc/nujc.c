#include <stdio.h>
#include <math.h>
typedef struct {
    char tipFigura;
    union {
        float raza;
        struct {
            float raza;
            float inaltime;
        } con;
    } dimensiuni;
    float volum;
} Figura;
int main()
{
    Figura v[101], aux;
    int n, i, j;
    float pi = 3.14;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Introdu tipul figurei:\n");
        getchar();
        scanf("%c", &v[i].tipFigura);

        if (v[i].tipFigura == 'S')
        {
            printf("Introdu raza:\n");
            scanf("%f", &v[i].dimensiuni.raza);
            v[i].volum = (4 * pi * pow(v[i].dimensiuni.raza, 3)) / 3;
        }
        else {
            printf("Introdu raza:\n");
            scanf("%f", &v[i].dimensiuni.con.raza);
            printf("Introdu inaltimea:\n");
            scanf("%f", &v[i].dimensiuni.con.inaltime);
            v[i].volum = (pi * pow(v[i].dimensiuni.con.raza, 2) * v[i].dimensiuni.con.inaltime) / 3;
        }
    }
    printf("Afisare:");
    for (i = 0; i < n; i++)
    {
        if (v[i].tipFigura == 'S')
            printf("%c %f %f\n", v[i].tipFigura, v[i].dimensiuni.raza, v[i].volum);
        else
            printf("%c %f %f %f\n", v[i].tipFigura, v[i].dimensiuni.raza, v[i].dimensiuni.con.inaltime, v[i].volum);
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (v[i].volum > v[j].volum)
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    printf("Afisare Ordonate:");
    for (i = 0; i < n; i++)
    {
        if (v[i].tipFigura == 'S')
            printf("%c %f %f\n", v[i].tipFigura, v[i].dimensiuni.raza, v[i].volum);
        else
            printf("%c %f %f %f\n", v[i].tipFigura, v[i].dimensiuni.raza, v[i].dimensiuni.con.inaltime, v[i].volum);
    }
}