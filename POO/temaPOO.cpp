#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>

using namespace std;

class Calculatoare //clasa de baza
{
    public:
    char *Producator;
    float DiagonalaMonitor;
    float Pret;
    Calculatoare(const char* P, float d, float pr) //constructor clasa de baza
    {
        Producator=new char[20];
        strcpy(Producator, P);
        DiagonalaMonitor=d;
        Pret=pr;
    }
    virtual void afisare(){};
};

class Desktop: public Calculatoare //clasa derivata 1
{
    public:
    char *TipEcran;
    char *Conectori;
    int TimpRasp;
    Desktop *head;
    Desktop *next;
    Desktop(const char *P, float d, float pr, const char* Te, const char* C, int tr):Calculatoare(P, d, pr) //constructor
    {
        //alocare dinamica
        head=NULL; //pointerul head ca pointer NULL(valoare 0)
       TipEcran=new char[20];
       Conectori=new char[20];
       strcpy(TipEcran, Te);
       strcpy(Conectori, C);
       TimpRasp=tr;
    }

    void adaugareDesktop() //functie de adaugare
    {
        //alocare dinamica
        char* Producator=new char[20];
        char* TipEcran=new char[20];
        char* Conectori=new char[20];
        int TimpRasp;
        cout<<"Producator: ";
        cin>>Producator;
        cout<<"Diagonala Monitorului: ";
        cin>>DiagonalaMonitor;
        cout<<"Pret: ";
        cin>>Pret;
        cout<<"Tip Ecran: ";
        cin>>TipEcran;
        cout<<"Conectori: ";
        cin>>Conectori;
        cout<<"Timp Raspundere Monitor: ";
        cin>>TimpRasp;
        Desktop* p=new Desktop(Producator, DiagonalaMonitor, Pret, TipEcran, Conectori, TimpRasp);
        p->next=head;
        head=p;
    }

    void afisareDesktop() //functie de afisare
    {
        Desktop *p=head;
        while(p!=NULL)
        {
            cout<<"Prdoucator: "<<p->Producator<<endl;
            cout<<"Diagonala Monitorului: "<<p->DiagonalaMonitor<<endl;
            cout<<"Pret: "<<p->Pret<<endl;
            cout<<"Tip Ecran: "<<p->TipEcran<<endl;
            cout<<"Conectori: "<<p->Conectori<<endl;
            cout<<"Timp Raspunedere Monitor: "<<p->TimpRasp<<endl;
            p=p->next;
        }
    }

    Desktop* cautareDesktop(Desktop* head, const char* producatorCautat) //functie de cautare
    {
        Desktop* p = head;
        while (p != NULL)
        {
            if (strcmp(p->Producator, producatorCautat) == 0)
            {
                return p;
            }
        p = p->next;
        }
    return NULL;
    }

    void stergereDesktop(const char* producatorCautat) //functie de stergere
    {
    Desktop* p = head;
    Desktop* prev = NULL;
    if (p != NULL && strcmp(p->Producator, producatorCautat) == 0)
    {
        head = p->next;
        delete p;
        return;
    }
    while (p != NULL && strcmp(p->Producator, producatorCautat) != 0)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
        return;

    prev->next = p->next;
    delete p;
    }
};

class Laptop: public Calculatoare //clasa derivata 2
{
    public:
    char *FormatEcran;
    char *Iluminare;
    int BoxeIntegrale;
    Laptop *head;
    Laptop *next;
    Laptop(const char *P, float d, float pr, const char* Fe, const char* I, int bi):Calculatoare(P, d, pr) //Constructor
    {
        //alocare dinamica
        head=NULL; //pointerul head ca pointer NULL(valoare 0)
         FormatEcran=new char[20];
       Iluminare=new char[20];
       strcpy(FormatEcran, Fe);
       strcpy(Iluminare, I);
       BoxeIntegrale=bi;
    }

    void adaugareLaptop() //functie de adaugare
    {
        //alocare dinamica
        char* FormatEcran=new char[20];
        char* Iluminare=new char[20];
        char* Producator=new char[20];
        int BoxeIntegrale;
        cout<<"Producator: ";
        cin>>Producator;
        cout<<"Diagonala Monitorului: ";
        cin>>DiagonalaMonitor;
        cout<<"Pret: ";
        cin>>Pret;
        cout<<"Format Ecran: ";
        cin>>FormatEcran;
        cout<<"Iluminare: ";
        cin>>Iluminare;
        cout<<"Boxe Integrale: ";
        cin>>BoxeIntegrale;
        Laptop *p=new Laptop(Producator, DiagonalaMonitor, Pret, FormatEcran, Iluminare, BoxeIntegrale);
        p->next=head;
        head=p;
    }

    void afisareLaptop() //functie de afisare
    {
        Laptop *p=head;
        while(p!=NULL)
        {
            cout<<"Prdoucator: "<<p->Producator<<endl;
            cout<<"Diagonala Monitorului: "<<p->DiagonalaMonitor<<endl;
            cout<<"Pret: "<<p->Pret<<endl;
            cout<<"Format Ecran: "<<p->FormatEcran<<endl;
            cout<<"Iluminare: "<<p->Iluminare<<endl;
            cout<<"Numar de boxe integrale: "<<p->BoxeIntegrale<<endl;
            p=p->next;
        }
    }

    Laptop* cautareLaptop(Laptop* head, const char* producatorCautat) //functie de cautare
    {
        Laptop* p = head;
        while (p != NULL)
        {
            if (strcmp(p->Producator, producatorCautat) == 0)
            {
                return p;
            }
        p = p->next;
        }
    return NULL;
    }

    void stergereLaptop(const char* producatorCautat) //functie de stergere
    {
    Laptop* p = head;
    Laptop* prev = NULL;
    if (p != NULL && strcmp(p->Producator, producatorCautat) == 0)
    {
        head = p->next;
        delete p;
        return;
    }
    while (p != NULL && strcmp(p->Producator, producatorCautat) != 0)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
        return;

    prev->next = p->next;
    delete p;
    }
};

int main()
{
    int opt;
    //char producator[20];
    Desktop *d=new Desktop(" ", 0, 0, " ", " ", 0); //creare obiect gol
    Desktop* producatorGasit; //variabila relevanta pentru functiile de cautare si stergere
    Laptop *l=new Laptop(" ", 0, 0, " ", " ", 0); //creare obiect gol
    Laptop* producatorGasitL; //variabila relevanta pentru functiile de cautare si stergere
    do 
    {
        //meniu
        cout<<endl;
        cout<<"1. Adaugare Desktop PC"<<endl;
        cout<<"2. Adaugare Laptop"<<endl;
        cout<<"3. Afisare Desktop PC"<<endl;
        cout<<"4. Afisare Laptop"<<endl;
        cout<<"5. Cautare Desktop PC dupa producator"<<endl;
        cout<<"6. Cautare Laptop dupa producator"<<endl;
        cout<<"7. Stergere Desktop PC"<<endl;
        cout<<"8. Stergere Laptop"<<endl;
        cout<<endl;
        cout<<"Optiune: ";
        cin>>opt;
        switch(opt)
        {
            case 0:
            break;
            case 1:
            d->adaugareDesktop();
            break;
            case 2: 
            l->adaugareLaptop();
            break;
            case 3:
            d->afisareDesktop();
            break;
            case 4:
            l->afisareLaptop();
            break;
            case 5:
            char producatorCautat[20];
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautat, 20); //citire producatorul care se doreste gasit
            producatorGasit = d->cautareDesktop(d->head, producatorCautat); //functia va returna idexul obiectului cautat
            if (producatorGasit) //daca producatorul a fost gasit (adica indexul returnat de functia de mai sus nu e 0)
            {
                cout << "Producatorul a fost gasit!" << endl;
                cout << "Producator: " << producatorGasit->Producator << endl;
                cout << "Diagonala Monitorului: " << producatorGasit->DiagonalaMonitor << endl;
                cout << "Pret: " << producatorGasit->Pret << endl;
                cout << "Tip Ecran: " << producatorGasit->TipEcran << endl;
                cout << "Conectori: " << producatorGasit->Conectori << endl;
                cout << "Timp Raspundere Monitor: " << producatorGasit->TimpRasp << endl;
            }
            else //daca producatorul nu a fost gasit
            {
                cout << "Producatorul " << producatorCautat << " nu a fost gasit." << endl;
            }
            break;
            case 6:
            char producatorCautatL[20];
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautatL, 20); //citire producatorul care se doreste gasit
            producatorGasitL = l->cautareLaptop(l->head, producatorCautatL); //functia va returna idexul obiectului cautat
            if (producatorGasitL) //daca producatorul a fost gasit (adica indexul returnat de functia de mai sus nu e 0)
            {
                cout << "Producatorul a fost gasit!" << endl;
                cout << "Producator: " << producatorGasitL->Producator << endl;
                cout << "Diagonala Monitorului: " << producatorGasitL->DiagonalaMonitor << endl;
                cout << "Pret: " << producatorGasitL->Pret << endl;
                cout << "Format Ecran: " << producatorGasitL->FormatEcran << endl;
                cout << "Iluminare: " << producatorGasitL->Iluminare << endl;
                cout << "Boxe Integrale: " << producatorGasitL->BoxeIntegrale << endl;
            }
            else //daca producatorul nu a fost gasit
            {
                cout << "Producatorul " << producatorCautatL << " nu a fost gasit." << endl;
            }
            break;
            case 7:
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautat, 20);
            d->stergereDesktop(producatorCautat);
            break;
            case 8:
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautatL, 20);
            l->stergereLaptop(producatorCautatL);
            break;
        }
    } while (opt != 0);
    return 0;
}