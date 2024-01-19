#include <stdio.h>
typedef struct cc{
    char nume_f[31],nume_p[31];
    unsigned int nota;
}cc;
int citire(FILE* f,cc v[])
{
    int i=0;
    f=fopen("vsc.txt","r");
    while (!feof(f))
    {
        fscanf(f,"%[^;]; %[^;]; %u",v[i].nume_f,v[i].nume_p,&v[i].nota);
        i++;
    }
    return i;
    fclose(f);
}
void afisare(FILE* f,cc v[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s %s %u",v[i].nume_f,v[i].nume_p,v[i].nota);
    }
}
void medie(FILE* f, cc v[], int n)
{
    int s=0, nr=0; float m=0;
    for(int i=0;i<n;i++)
    {
        s+=v[i].nota; nr++;
    }
    m=s/nr;
    printf("\nMedia:%.2f",m);
}
int main()
{
    FILE* f;
    cc v[101];
    int n;
    n=citire(f,v);
    afisare(f,v,n);
    medie(f,v,n);
    return 0;
}