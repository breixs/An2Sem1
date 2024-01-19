#include <stdio.h>
#include <string.h>
void citire(int v[][30], int n)
{
    int i ,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
                printf("[%d][%d] = ", i, j);
                scanf("%d", &v[i][j]);
            }
}

void afisare(int v[][30], int n)
{
    int i ,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                printf("%d", v[i][j]);
            }
            printf("\n");
    }
    printf("\n");
}
void inversare(int v[][30], int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(v[i][j]==0)
            v[i][j]=1;
            else
            v[i][j]=0;
        }
    afisare(v,n);
}

void rotire_dreapta(int v[][30], int n)
{
    int i, j;
    int a[30][30];
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            a[i][j]=v[n-j-1][i];
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            v[i][j]=a[i][j];
        }

    afisare(v,n);
}

void rotire_stanga(int v[][30], int n)
{
    int i, j;
    int a[30][30];
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            a[i][j]=v[j][i];
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            v[i][j]=a[i][j];
        }

    afisare(v,n);
}

void zoom(int v[][30], int n, int m)
{
   int i, j, q, p;
    int a[100][100];
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
    printf("\n");
    n=m;
    q=0;
    p=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
                v[i][j]=a[q+i][p+i];
            }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d", v[i][j]);
        printf("\n");
    }
}

void citire_sir(int v[][30], int s[5], int n)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("s[%d] = ", i);
        scanf(" %c", &s[i]);
    }
    for(i=0;i<5;i++)
        printf("%c ", s[i]);
    printf("\n");

    for(i=0;i<5;i++)
    {
        if(s[i]=='i')
        inversare(v,n);
        else if(s[i]=='r')
        rotire_dreapta(v,n);
        else if(s[i]=='z')
        {
            zoom(v,n,n*2);
        }
        else
        break;
    }
}

int main()
{
    int n;
    int v[30][30];
    int s[5];
    printf("n=");
    scanf("%d", &n);
    citire(v,n);
    afisare(v,n);
    //citire_sir(v,s,n);
    zoom(v,n,n*2);
    return 0;
}