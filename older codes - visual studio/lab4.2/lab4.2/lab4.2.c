#include <stdio.h>

int main()
{
    int n, i, k, a;
    printf("n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        k = 1;
        a = i;
        while (a <= n)
        {
            printf("%d ", k);
            k++;
            a++;
        }
        printf("\n");
    }
    printf("\n");
    for (i = n; i >= 1 ; i--)
    {
        k = 1;
        a = i;
        while (a <= n)
        {
            printf("%d ", k);
            k++;
            a++;
        }
        printf("\n");
    }
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        k = n;
        a = i;
        while (a <= n)
        {
            printf("%d ", k);
            k--;
            a++;
        }
        printf("\n");
    }
    printf("\n");
    for (i = n; i >= 1; i--)
    {
        k = n;
        a = i;
        while (a <= n)
        {
            printf("%d ", k);
            k--;
            a++;
        }
        printf("\n");
    }
    
    return 0;
}