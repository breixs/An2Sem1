#include <iostream>
#include <string>

using namespace std;

class Nod
{
    int numar;
    Nod *urm;
    public:
    void adaugare(Nod*&, int);
    void afisare(Nod*);
    friend void sterg(Nod*,int);
};
Nod *ultim, *nod;

void Nod::adaugare(Nod*&nou, int valoare)
{
    Nod *nou1;
    if(!nou)
    {
        nou=new Nod;
        nou->numar=valoare;
        nou->urm=NULL;
        ultim=nou;
    }
    else{
        nou1=new Nod;
        ultim->urm=nou1;
        nou1->numar=valoare;
        nou1->urm=NULL;
        ultim=nou1;
    }
}

void Nod::afisare(Nod*c)
{
    while(c)
    {
        cout<<c->numar<<" ";
        c=c->urm;
    }
    cout<<endl;
}

void sterg(Nod* nod, int valoare)
{
    Nod *nod1, *nod2;
    if(nod->numar==valoare)
    {
        nod2=nod;
        nod=nod->urm;
    }
    else
    {
        nod1=nod;

        while (nod1->urm->numar != valoare)
        {
            nod1=nod1->urm;
        }
        nod2=nod1->urm;
        nod1->urm=nod2->urm;
        if(nod2==ultim)
            ultim=nod1;
    }
     delete nod2;   
}

int main()
{
    int i;
    Nod lista;
    for(i=1;i<10;i++)
        lista.adaugare(nod,i);
    lista.afisare(nod);
    sterg(nod,2);
    lista.afisare(nod);
    return 0;
}