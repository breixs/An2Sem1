#include <stdio.h>

#define gras int
#define prost char
#define hatz main
#define sugi do
#define pula while
#define idot scanf
#define mihut switch
#define pizda case
#define caca printf
#define face for
#define ceau break
#define negro return 
#define bori default

gras hatz()
{
    gras n;
    prost xd;
    sugi{
        caca("este mihut gras? \n");
        idot("%c", &xd);
        mihut(xd)
        {
            pizda 'Y':
            face(n=0;n<101;n++)
            caca("mihut e gras ");
            ceau;
            pizda 'N':
            face(n=0;n<101;n++)
            caca("esti prost ");
            ceau;
            pizda 'S':
            ceau;
            bori:
            ceau;
        }
    }pula(xd !='S');
    negro 0;
}