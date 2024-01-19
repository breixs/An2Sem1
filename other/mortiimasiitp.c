#include <stdio.h>

void citire(char v[][100], int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("[%d][%d] = ", i,j);
            scanf(" %c", &v[i][j]);
        }
}

void afisare(char v[][100], int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %c", v[i][j]);
        }
        printf("\n");
    }
}

void max(char v[][100], int m, int n)
{
    int i, j, k=0, kmax=0, q, p, l=65, t, ok=0;
    char charmax;
    char c[3];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
             k=0;
            for(p=0;p<m;p++)
            {
                for(q=0;q<n;q++)
                {
                    if(v[i][j]==v[p][q])
                    {
                        k++;
                    }
                }
            
            }
            //printf("%d\n", k);
            if(kmax<k)
            {
                kmax=k;
                charmax=v[i][j];
            }
        }
    }
    do{
        if(charmax==l)
            ok=1;
        else
            ok=0;
        l++;
    }while(l<=90);

    if(ok=1)
    {
        c[0]=charmax+32;
        c[1]=charmax;
        for(t=0;t<2;t++)
            printf("%c", c[t]);
    }
    else
        printf("%c", charmax);
}

int main()
{
    char v[100][100];
    //char rez[2];
    int m,n;
    printf("nr coloane= ");
    scanf("%d", &m);
    printf("nr linii= ");
    scanf("%d", &n);
    citire(v,m,n);
    afisare(v,m,n);
    max(v,m,n);
    //printf("%s", rez);
    return 0;
}