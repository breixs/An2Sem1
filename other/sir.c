#include <stdio.h>

void generare(unsigned int k, unsigned int n)
{
    FILE *f;
    f=fopen("mata.txt", "w");
    if(f==NULL)
    printf("mogus");
    unsigned int i = 0, nr = 1, temp = k;
    while (i < n) 
    {
        temp = k;
        while (temp > 0 && i < n) 
        {
            fprintf(f, "%d", nr);
            i++;
            temp--;
        }
        nr++;
    }
    fclose(f);
}

int main()
{
    unsigned int k, n;
    printf("k=");
    scanf("%d", &k);
    printf("n=");
    scanf("%d", &n);
    generare(k,n);
    return 0;

}