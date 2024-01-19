#include<iostream>
#include<string.h>
#include<conio.h>
#include <fstream>
#include <string>
using namespace std;
class Lista; //prototipul clasei Lista
class agentie //clasa de baza agentie
{
private:
    int tip;
    char *nume;
    int pret;
    int tenis;
    agentie *urm; //adresa urm element din lista
    ofstream f_in;
    ifstream f_out;
    string linie;
public:
    agentie(int tp, char *n, int p, int t) //constructor clasa de baza
    {
        nume = new char[strlen(n) + 1]; //alocare memorie pentru variabila nume
        tip = tp;
        strcpy(nume, n);
        pret = p;
        tenis = t;
        urm = NULL; //adresa noului nod este initial NULL
        f_in.open("fisier2.txt");
        if(f_in.is_open())
        {
            f_in<<"Nume in fisier: "<<nume<<endl;
            f_in<<"Tip in fisier: "<<tip<<endl;
            f_in<<"Pret in fisier: "<<pret<<endl;
            f_in<<"Tenis in fisier: "<<tenis<<endl;
        }
        f_in.close();
    }
    virtual void afisare() //functia de afisare elemente clasa de baza
    {
        cout << "-----------------------------------------\n";
        cout << "Nume: " << nume << endl;
        cout << "Pret: " << pret << endl;
        cout << "Teren tenis: " << tenis << endl;
        f_out.open("fisier2.txt");
        if(f_out.is_open())
        {
            while (getline(f_out, linie))
            {
                cout<<linie;
                cout<<endl;
            }
            f_out.close();
        }
    }
     void scrieFisier()
    {
        //f_in.open("fisier2.txt");
        if(f_in.is_open())
        {
            f_in<<"Nume in fisier: "<<nume<<endl;
            f_in<<"Tip in fisier: "<<tip<<endl;
            f_in<<"Pret in fisier: "<<pret<<endl;
            f_in<<"Tenis in fisier: "<<tenis<<endl;
        }
        //f_in.close();
    }

    void afisareFisier()
    {
        f_out.open("fisier2.txt");
        if(f_out.is_open())
        {
            while (getline(f_out, linie))
            {
                cout<<linie;
                cout<<endl;
            }
            f_out.close();
        }
    }
    friend class Lista; //declararea clasei Lista friend la clasa agentie, pentru a se avea acces la campurile acesteia
};
class hotel :public agentie //prima clasa derivata
{
private:
    int nr_stele;
    int piscina;
    int sauna;
    ofstream f_in;
    ifstream f_out;
    string linie;
public:
    hotel(int tp, char *n, int p, int t, int s, int ps, int sn) :agentie(tp, n, p, t) //constructor clasa derivata
    {
        nr_stele = s;
        piscina = ps;
        sauna = sn;
         f_in.open("fisier2.txt");
        if(f_in.is_open())
        {
            agentie::scrieFisier();
            f_in<<"Numar in fisier:"<<nr_stele<<endl;
            f_in<<"Piscina in fisier: "<<piscina<<endl;
            f_in<<"Sauna in fisier: "<<sauna<<endl;
        }
    }
    void afisare() //afisare elemente din clasa hotel
    {
        agentie::afisare(); //apelare afisare elemente din clasa de baza
        cout << "Nr stele: " << nr_stele << endl;
        cout << "Piscina: " << piscina << endl;
        cout << "Sauna: " << sauna << endl;
         f_out.open("fisier2.txt");
        if(f_out.is_open())
        {
            agentie::afisareFisier();
            while (getline(f_out, linie))
            {
                cout<<linie;
                cout<<endl;
            }
            f_out.close();
        }
    }

    void scrieFisier()
    {
        f_in.open("fisier2.txt");
        if(f_in.is_open())
        {
            agentie::scrieFisier();
            f_in<<nr_stele<<endl;
            f_in<<piscina<<endl;
            f_in<<sauna<<endl;
        }
    }

    void afisareFisier()
    {
        f_out.open("fisier2.txt");
        if(f_out.is_open())
        {
            agentie::afisareFisier();
            while (getline(f_out, linie))
            {
                cout<<linie;
            }
            f_out.close();
        }
    }
    friend class Lista;
};
class pensiune :public agentie // a doua clasa derivata
{
private:
    int nr_margarete;
    int gradina;
public:
    pensiune(int tp, char *n, int p, int t, int m, int g) :agentie(tp, n, p, t) //constructor
    {
        nr_margarete = m;
        gradina = g;
    }
    void afisare() //functie afisare    
    {
        agentie::afisare();
        cout << "Nr margarete: " << nr_margarete << endl;
        cout << "Gradina: " << gradina << endl;
    }
friend class Lista;
};
class Lista //clasa Lista
{
public:
    agentie *head; //capul listei
    void adaugare(agentie *a); //adaugare in lista
    void afisare_lista(); //afisarea listei
};
class MyException {
public:
    char str_what[80];
    int what;
    MyException() { *str_what = 0; what = 0; }
    MyException(char *s, int e) {
        strcpy(str_what, s);
        what = e;
        }
};
//adaugare in lista ordonata
void Lista::adaugare(agentie *a)
{
    agentie *p; //var p este declarata de tip agentie
    p = head; //se initializeaza cu capul listei
    if (p) //daca lista nu este vida
    {
if (strcmp(a->nume, p->nume)<0) //daca nodul care se adauga este mai mic decat primul nod din lista
{
a->urm = head; //noul nod se leaga de primul nod
head = a; //capul listei devine noul nod
}
else
{
while (p->urm && strcmp((p->urm)->nume, a->nume)<0)
p = p->urm;
a->urm = p->urm; //se fac legaturile intre noul nod si cele din lista
p->urm = a;
}
}
else
head = a; //daca lista este vida, capul este nodul adaugat
}
void Lista::afisare_lista() //afisarea listei
{
agentie *a;
a = head; //se initializeaza cu capul listei
if (!a) //daca lista este vida
cout << "Lista este vida!";
else
while (a) //cat timp sunt noduri in lista
{
a->afisare(); //se apeleaza afisarea corespunzatoare nodului curent
a = a->urm; //se trece la urm nod in lista
getch();
}
}
void introducere(Lista &l, int x) //introducere info in noduri
{
char nume[20];
int pret;
int tenis;
int nr_stele;
int piscina;
int sauna;
int nr_margarete;
int gradina;
agentie *a;
cout << "Dati numele: ";
cin >> nume;
try{
cout << "Dati pretul camerei: ";
cin >> pret;
if (pret<0)
throw MyException("Pretul nu este pozitiv", pret);
}
catch (MyException e) { // Prinde eroarea
cout << e.str_what << ": ";
cout << e.what << "\n";
}
cout << "Dati daca are teren de tenis[0/1]: ";
cin >> tenis;
if (x == 0) // daca s-a ales adaugarea unui nou hotel
{
hotel *h;
cout << "Dati numarul de stele: ";
cin >> nr_stele;
cout << "Dati daca are piscina[0/1]: ";
cin >> piscina;
cout << "Dati daca are sauna[0/1]: ";
cin >> sauna;
h = new hotel(1, nume, pret, tenis, nr_stele, piscina, sauna); //apelare constructor cu info citite
a = h; //cast pentru clasa de baza
l.adaugare(a); //se adauga nodul
}
else if (x == 1) //daca s-a ales adaugarea unei pensiuni
{
pensiune *p;
cout << "Dati numarul de margarete: ";
cin >> nr_margarete;
cout << "Dati daca are gradina: ";
cin >> gradina;
p = new pensiune(2, nume, pret, tenis, nr_margarete, gradina);//apelare constructor cu info citite
a = p;//cast pentru clasa de baza
l.adaugare(a);//se adauga nodul
}
}
int main() //programul principal
{
    int opt;
    Lista l;
    l.head = NULL;
    do
    {
        system("CLS");
        //meniu
        cout << "1.Adaugare oferta hotel.\n";
        cout << "2.Adaugare oferta pensiune.\n";
        cout << "3.Afisare oferte.\n";
        cout << "0.Iesire.\n";
        cout << "Dati optiunea dvs: ";
        cin >> opt;
        //apelare functii in functie de optiunea aleasa
        switch (opt)
            {
            case 1: introducere(l, 0);
            break;
            case 2: introducere(l, 1);
            break;
            case 3: l.afisare_lista();
            break;
            case 4: 
            case 0: break;
        default:cout << "Comanda gresita!";
}
} while (opt != 0);
}