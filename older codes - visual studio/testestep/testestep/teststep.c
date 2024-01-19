#include <stdio.h>

/*int main() {
    int a, b, c, d, i = 0, sum = 0;
    double avg = 0.00;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (a > 0)
    {
        sum += a;
        i++;
    }
    if (b > 0)
    {
        sum += b;
        i++;
    }
    if (c > 0)
    {
        sum += c;
        i++;
    }
    if (d > 0)
    {
        sum += d;
        i++;
    }
    printf("%d%d%d%d", a, b, c, d);

    if (i > 0)
        avg = (double)sum / i;
    else
        avg = 0.00;

    printf("%2f", avg);
    return 0;
}*/


int main()
{
    int n, inv = 0, aux, temp;
    scanf("%d", &n);
    temp = n;
    while (n != 0)
    {
        aux = n % 10;
        inv = inv * 10 + aux;
        n = n / 10;
    }

    if (temp == inv)
        printf("true");
    else
        printf("false");

    return 0;
}

