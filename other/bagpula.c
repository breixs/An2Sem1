#include <stdio.h>

void citire(char v[][100], int m, int n)
{
    int i, j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf(" %c", &v[i][j]);
        }
}

void afisare(char v[][100], int m, int n)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %c ", v[i][j]);
        }
        printf("\n");
    }
}

void max(char v[][100], int m, int n)
{
    int i, j, k=0;
    char max1, max2='\0';
    char c;
    char f[256]={0};
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c=v[i][j];
            f[c]++;
            if(f[c]>k)
            {
                max1=c;
                k=f[c];
            }
        }
    }
    for(i=0;i<256;i++)
    {
        if(f[i]==k && (char)i<max1)
        {
            max1=(char)i;
            if(max1>='a'&& max1<='z')
            {
                if(f[i-32]==k)
                max2=(char)i-32;
            }
            else if(f[i+32]==k)
            max2=(char)i+32;
            
        }
    }
    if(max2!='\0')
    printf("\n%c%c", max1,max2);
    else
    printf("\n%c",max1);
}

int main()
{
    int m ,n;
    char v[100][100];
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    citire(v,m,n);
    afisare(v,m,n);
    max(v,m,n);
    return 0;
}