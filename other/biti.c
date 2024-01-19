#include <stdio.h>
#include <math.h>

void generare(unsigned int bin[32])
{
    bin[0]=0;
    int i=1;
    int c=0, k=2;
    while(i<=31)
    {
        c=k;
        while(c>0 && i<=31)
        {
            bin[i]=1;
            i++;
            c--;
        }
        k++;
        c=k;
        while(c>0 && i<=31)
        {
            bin[i]=0;
            i++;
            c--;
        }
        k++;
    }
}

void afisare(unsigned int bin[32])
{
    int i=31;
    for(i=31;i>=0;i--)
    printf("%d", bin[i]);
}

void decimal(unsigned int bin[32])
{
    int i=0, putere;
    long long n;
    for(i=0;i<32;i++)
    {
        if(bin[i]==1)
        {
            putere=pow(i,2);
            n += putere;
        }
    }
    printf("\n%lld\n", n);
}

int main()
{
   unsigned int nr[32];
   generare(nr);
   afisare(nr);
   decimal(nr);
   return 0;

}