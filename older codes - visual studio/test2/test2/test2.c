#include <stdio.h>

int main()
{
    int num, n, bitStatus;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to check */
    
    n = 0;

    /* Right shift num, n times and perform bitwise AND with 1 */
    bitStatus = (num >> n) & 1;

    if (bitStatus == 0)
        printf("par");
    else
        printf("impar");
     

    return 0;
}