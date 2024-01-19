#include <stdio.h>

void citire(int v[][100], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &v[i][j]);
        }
    }
}

void afisare(int v[][100], int n)
{
     int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d", v[i][j]);
        }
        printf("\n");
    }
}

void inversare(int v[][100], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(v[i][j]==0)
            v[i][j]=1;
            else
            v[i][j]=0;
        }
    }
    printf("\n");
    afisare(v, n);
}

void schimba(int *x, int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

void rotire(int v[][100], int n)
{
    int i, j;
    /*for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            int temp = v[i][j];
            v[i][j] = v[n - 1 - j][i];
            v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
            v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
            v[j][n - 1 - i] = temp;
        }
    }*/
    //matrice transpusa
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            schimba(&v[i][j], &v[j][i]);
        }
    }
    //schimbare coloane
    for(i=0;i<n;i++)
    {
        for(j=0;j<n/2;j++)
        {
            schimba(&v[i][j], &v[i][n-j-1]);
        }
    }
    printf("\n");
    afisare(v,n);
}

void alegere(int v[][100], char s[10], int n, int m)
{
    int i, j, k;
    for(k=0;k<m;k++)
    {
            if(s[k]=='i')
            {
                printf("matrice inversata:");
                inversare(v,n);
            }
            else if (s[k]=='r')
            {
            printf("matrice rotita:");
                rotire(v,n);
            }
            else
                printf("caracter gresit");
    }
}

void pula(int v[][100], int n)
{
    int a[100][100];
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=v[n-j-1][i];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            v[i][j]=a[i][j];
        }
    }
    afisare(v,n);
}

void zoom(int v[][100], int n)
{
    int i, j, q, p, m;
    int a[100][100];
    m=2*n;
    for(q=0;q<m;q++)
    {
        for(p=0;p<m;p++)
        {
            a[q][p]=0;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(q=0;q<2;q++)
                for(p=0;p<2;p++)
                {
                    a[i*2+q][j*2+p]=v[i][j];
                }
     for(q=0;q<m;q++)
    {
        for(p=0;p<m;p++)
        {
            printf("%d", a[q][p]);
        }
        printf("\n");
    }

}

int main()
{
    int n, i, m;
    int v[100][100];
    char s[10];
    printf("n=");
    scanf("%d", &n);
    /*printf("m=");
    scanf("%d", &m);
    for(i=0;i<m;i++)
        {
            printf("s[%d] = ", i);
            scanf(" %c", &s[i]);
        }
    for(i=0;i<m;i++)
        printf(" %c", s[i]);
    printf("\n");*/
    citire(v, n);
    afisare(v,n);
    //pula(v,n);
    zoom(v,n);
    //alegere(v,s,n,m);
    
    return 0;
}