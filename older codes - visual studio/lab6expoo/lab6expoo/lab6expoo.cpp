#include <iostream>
#include <string>

using namespace std;

class Magazin
{
    string Producator;
    int Pret;
    string Rezolutia;
    int tipDerivat;
    Magazin* urm;
public:
    Magazin(int t, string P, int prt, string R)
    {
        tipDerivat = t;
        Producator = P;
        Pret = prt;
        Rezolutia = R;
        urm = nullptr;
    }
    virtual void afisare()
    {
        cout << endl;
        cout << "Producator: " << Producator << endl;
        cout << "Pret: " << Pret << endl;
        cout << "Rezolutia: " << Rezolutia << endl;
    }
    friend class Lista;
};

class Rama :public Magazin
{
public:
    int Diagonala;
    string FormatAfisare;
    //public:
    Rama(int t, string P, int prt, string R, int d, string F) :Magazin(t, P, prt, R)
    {
        Diagonala = d;
        FormatAfisare = F;
    }
    void afisare()
    {
        Magazin::afisare();
        cout << "Diagonala: " << Diagonala << endl;
        cout << "Format Afisare: " << FormatAfisare << endl;
    }
    friend class Lista;
};

class Aparat :public Magazin
{
    string tipSenzor;
    string TipAparat;
public:
    Aparat(int t, string P, int prt, string R, string TA, string TS) :Magazin(t, P, prt, R)
    {
        TipAparat = TA;
        tipSenzor = TS;
    }
    void afisare()
    {
        Magazin::afisare();
        cout << "Tip Aparat: " << TipAparat << endl;
        cout << "Tip Senzor: " << tipSenzor << endl;
    }
    friend class Lista;
};

class Lista
{
public:
    Magazin* head;
    void adaugare(Magazin* prod)
    {
        Magazin* p;
        p = head;
        if (p)
        {
            if (prod->Producator == p->Producator)
            {
                prod->urm = head;
                head = prod;
            }
            else
            {
                while (p->urm && (p->urm)->Producator == prod->Producator)
                {
                    p = p->urm;
                    prod->urm = p->urm;
                    p->urm = prod;
                }
            }
        }
        else
            head = prod;
    }
    void afisareLista()
    {
        Magazin* a;
        a = head;
        if (!a)
        {
            cout << "Lista pula";
        }
        else
        {
            while (a)
            {
                a->afisare();
                a = a->urm;
            }
        }
    }
};

void introducere(Lista& l, int x)
{
    int tipDerivat;
    string Producator;
    int Pret;
    int Rezolutia;
    string Diagonala;
    string FormatAfisare;
    string tipAparat;
    string tipSenzor;
    Magazin* mag;

    cout << "intorduce producator: ";
    cin >> Producator;
    cout << "introduce pret: ";
    cin >> Pret;
    cout << "Introduceti Rezolutia: ";
    cin >> Rezolutia;

    if (x == 0)
    {
        Rama* r;
        cout << "introduce diagonala: ";
        cin >> Diagonala;
        cout << "introduce format afisare: ";
        cin >> FormatAfisare;

        r = new Rama(1, Producator, Pret, Rezolutia, Diagonala, FormatAfisare);
        mag = r;
        l.adaugare(mag);

    }
    else if (x == 1)
    {
        Aparat* a;
        cout << "Intorduceti Tip Senzor: ";
        cin >> tipSenzor;
        cout << "Introduceti tip Aparat: ";
        cin >> tipAparat;

        a = new Aparat(2, Producator, Pret, Rezolutia, tipAparat, tipSenzor);
        mag = a;
    }

}

int main()
{
    int opt;
    Lista l;
    l.head = nullptr;
    do
    {

    } while (opt != 0);
    return 0;
}
