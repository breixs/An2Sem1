#include <stdio.h>

int main()
{
    unsigned int a, b, c;
    unsigned int result;
    a = 4000000000;
    b = 4000000000;
    c = 1000000000;
    printf("a = %u, b = %u, c = %u\n", a, b, c);  // %d considera ca numarul este in C2, pe cand %u afiseaza valoarea numarului natural. Puteti incerca sa vedeti ce va afiseaza %d si sa incercati sa explicati
    result = (a + b) / c; // Rezultatul ar trebui sa fie 8
    printf("result = %u\n", result);
    return 0;
}
