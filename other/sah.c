#include <stdio.h>
#include <string.h>

void citire(char v[30], int n)
{
    fgets(v,30,stdin);  
}

void afisare(char v[10], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        printf("%c ", v[i]);
        printf("\n");
    }
        
}

void protejat(char v[30], int n)
{
    int i=0, j, k=0;
    /*b4 d4 f4 c3 e3 g5 d2*/
   for(i=0;i<strlen(v);i=i+3)
   {
        for(j=0;j<strlen(v);j=j+3)
        {
            if(((i!=j)&&(v[i]-1==v[j])&&(v[i+1]-1==v[j+1]))||((i!=j)&&(v[i]+1==v[j])&&(v[i+1]+1==v[j+1])))
            {
                k++;
                break;
            }
        }
    }
    printf("%d\n", k);
}
int main()
{
    int n=7;
    char v[30];
    citire(v,n);
    //afisare(v,n);
    protejat(v,n);
    return 0;
}