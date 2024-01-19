#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>


using namespace std;

class Monitoare
{
protected:
    char* Producator;
    float Diagonala;
    float Pret;
public:
    //Monitoare();
    Monitoare(const char* P, float d, float pr)
    {
        Producator = new char[20];
        strcpy(Producator, P);
        Diagonala = d;
        Pret = pr;
    }
    virtual void afisare() {};
};

class LCD : public Monitoare
{
    char* TipEcran;
    char* Conectori;
    int TimpRasp;
    LCD* head;
    LCD* next;
public:
    LCD();
    LCD(const char* P, float d, float pr, const char* Te, const char* C, int tr) :Monitoare(P, d, pr)
    {
        TipEcran = new char[20];
        Conectori = new char[20];
        strcpy(TipEcran, Te);
        strcpy(Conectori, C);
        TimpRasp = tr;
    }

    void adaugareLCD()
    {
        char* TipEcran = new char[20];
        char* Conectori = new char[20];
        int TimpRasp;
        cout << "Tip Ecran:";
        cin >> TipEcran;
        cout << "Conectori:";
        cin >> Conectori;
        cout << "Timp Raspundere: ";
        cin >> TimpRasp;
        LCD* p = new LCD(Producator, Diagonala, Pret, TipEcran, Conectori, TimpRasp);
        p->next = head;
        head = p;
    }

    void afisareLCD()
    {
        LCD* p = head;
        while (p != NULL)
        {
            cout << "Prdoucator: " << p->Producator << endl;
            cout << "Diagonala: " << p->Diagonala << endl;
            cout << "Pret: " << p->Pret << endl;
            cout << "Tip Ecran: " << p->TipEcran << endl;
            cout << "Conectori: " << p->Conectori << endl;
            cout << "Timp Raspunedere: " << p->TimpRasp << endl;
            p = p->next;
        }
    }
};

class LED : public Monitoare
{
protected:
    char* FormatEcran;
    char* Iluminare;
    int BoxeIntegrale;
    LED* head;
    LED* next;
public:
    //LED();
    LED(const char* P, float d, float pr, const char* Fe, const char* I, int bi) :Monitoare(P, d, pr)
    {
        char* FormatEcran = new char[20];
        char* Iluminare = new char[20];
        int BoxeIntegrale;
        cout << "Tip Ecran:";
        cin >> FormatEcran;
        cout << "Conectori:";
        cin >> Iluminare;
        cout << "Timp Raspundere: ";
        cin >> BoxeIntegrale;
        LED* p = new LED(Producator, Diagonala, Pret, FormatEcran, Iluminare, BoxeIntegrale);
        p->next = head;
        head = p;
    }

    void adaugareLED()
    {
        char* FormatEcran = new char[20];
        char* Iluminare = new char[20];
        int BoxeIntegrale;
        cout << "Tip Ecran:";
        cin >> FormatEcran;
        cout << "Conectori:";
        cin >> Iluminare;
        cout << "Timp Raspundere: ";
        cin >> BoxeIntegrale;
        LED* p = new LED(Producator, Diagonala, Pret, FormatEcran, Iluminare, BoxeIntegrale);
        p->next = head;
        head = p;
    }

    void afisareLED()
    {
        LED* p = head;
        while (p != NULL)
        {
            cout << "Prdoucator: " << p->Producator << endl;
            cout << "Diagonala: " << p->Diagonala << endl;
            cout << "Pret: " << p->Pret << endl;
            cout << "Tip Ecran: " << p->FormatEcran << endl;
            cout << "Conectori: " << p->Iluminare << endl;
            cout << "Timp Raspunedere: " << p->BoxeIntegrale << endl;
            p = p->next;
        }
    }
};

int main()
{
    int opt;
    char producator[20];
    LCD* lcd = new LCD(" ", 0, 0, " ", " ", 0);
    LED* led = new LED(" ", 0, 0, " ", " ", 0);
    do
    {
        cout << "1. Adaugare LCD" << endl;
        cout << "2. Adaugare LED" << endl;
        cout << "3. Afisare LCD" << endl;
        cout << "4. Afisare LCD" << endl;
        cout << "Optiune: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            lcd->adaugareLCD();
            break;
        case 2:
            led->afisareLED();
            break;
        case 3:
            lcd->afisareLCD();
            break;
        case 4:
            led->afisareLED();
            break;
        }

    } while (opt != 0);
    return 0;
}