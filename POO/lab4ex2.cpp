#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>

using namespace std;

class Monitoare
{
    public:
    char *Producator;
    float Diagonala;
    float Pret;
    Monitoare(const char* P, float d, float pr)
    {
        Producator=new char[20];
        strcpy(Producator, P);
        Diagonala=d;
        Pret=pr;
    }
    virtual void afisare(){};
};

class LCD: public Monitoare
{
    public:
    char *TipEcran;
    char *Conectori;
    int TimpRasp;
    LCD *head;
    LCD *next;
    LCD(const char *P, float d, float pr, const char* Te, const char* C, int tr):Monitoare(P, d, pr)
    {
        head=NULL;
       TipEcran=new char[20];
       Conectori=new char[20];
       strcpy(TipEcran, Te);
       strcpy(Conectori, C);
       TimpRasp=tr;
    }

    void adaugareLCD()
    {
        char* Producator=new char[20];
        char* TipEcran=new char[20];
        char* Conectori=new char[20];
        int TimpRasp;
        cout<<"Producator: ";
        cin>>Producator;
        cout<<"Diagonala: ";
        cin>>Diagonala;
        cout<<"Pret: ";
        cin>>Pret;
        cout<<"Tip Ecran: ";
        cin>>TipEcran;
        cout<<"Conectori: ";
        cin>>Conectori;
        cout<<"Timp Raspundere: ";
        cin>>TimpRasp;
        LCD* p=new LCD(Producator, Diagonala, Pret, TipEcran, Conectori, TimpRasp);
        p->next=head;
        head=p;
    }

    void afisareLCD()
    {
        LCD *p=head;
        while(p!=NULL)
        {
            cout<<"Prdoucator: "<<p->Producator<<endl;
            cout<<"Diagonala: "<<p->Diagonala<<endl;
            cout<<"Pret: "<<p->Pret<<endl;
            cout<<"Tip Ecran: "<<p->TipEcran<<endl;
            cout<<"Conectori: "<<p->Conectori<<endl;
            cout<<"Timp Raspunedere: "<<p->TimpRasp<<endl;
            p=p->next;
        }
    }

    LCD* cautareLCD(LCD* head, const char* producatorCautat)
    {
         LCD* p = head;
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

    void stergereLCD(const char* producatorCautat)
    {
    LCD* p = head;
    LCD* prev = NULL;
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

    void sortareLCD()
    {
        LCD* p=head;
        while (p!=NULL)
        {
            LCD* q=p->next;
            while(q!=NULL)
            {
                if(p->Pret>q->Pret)
                {
                swap(p->Producator, q->Producator);
                swap(p->Diagonala, q->Diagonala);
                swap(p->Pret, q->Pret);
                swap(p->TipEcran, q->TipEcran);
                swap(p->Conectori, q->Conectori);
                swap(p->TimpRasp, q->TimpRasp); 
                }
                q=q->next;
            }
            p=p->next;
        }  
    }
};

class LED: public Monitoare
{
    public:
    char *FormatEcran;
    char *Iluminare;
    int BoxeIntegrale;
    LED *head;
    LED *next;
    LED(const char *P, float d, float pr, const char* Fe, const char* I, int bi):Monitoare(P, d, pr)
    {
        head=NULL;
         FormatEcran=new char[20];
       Iluminare=new char[20];
       strcpy(FormatEcran, Fe);
       strcpy(Iluminare, I);
       BoxeIntegrale=bi;
    }

    void adaugareLED()
    {
        char* FormatEcran=new char[20];
        char* Iluminare=new char[20];
        char* Producator=new char[20];
        int BoxeIntegrale;
        cout<<"Producator: ";
        cin>>Producator;
        cout<<"Diagonala: ";
        cin>>Diagonala;
        cout<<"Pret: ";
        cin>>Pret;
        cout<<"Format Ecran: ";
        cin>>FormatEcran;
        cout<<"Iluminare: ";
        cin>>Iluminare;
        cout<<"Boxe Integrale: ";
        cin>>BoxeIntegrale;
        LED *p=new LED(Producator, Diagonala, Pret, FormatEcran, Iluminare, BoxeIntegrale);
        p->next=head;
        head=p;
    }

    void afisareLED()
    {
        LED *p=head;
        while(p!=NULL)
        {
            cout<<"Prdoucator: "<<p->Producator<<endl;
            cout<<"Diagonala: "<<p->Diagonala<<endl;
            cout<<"Pret: "<<p->Pret<<endl;
            cout<<"Format Ecran: "<<p->FormatEcran<<endl;
            cout<<"Iluminare: "<<p->Iluminare<<endl;
            cout<<"Boxe Integrale: "<<p->BoxeIntegrale<<endl;
            p=p->next;
        }
    }

    LED* cautareLED(LED* head, const char* producatorCautat)
    {
         LED* p = head;
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

    void stergereLED(const char* producatorCautat)
    {
    LED* p = head;
    LED* prev = NULL;
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

    void sortareLED()
    {
        LED* p=head;
        while (p!=NULL)
        {
            LED* q=p->next;
            while(q!=NULL)
            {
                if(p->Pret>q->Pret)
                {
                swap(p->Producator, q->Producator);
                swap(p->Diagonala, q->Diagonala);
                swap(p->Pret, q->Pret);
                swap(p->FormatEcran, q->FormatEcran);
                swap(p->Iluminare, q->Iluminare);
                swap(p->BoxeIntegrale, q->BoxeIntegrale); 
                }
                q=q->next;
            }
            p=p->next;
        }  
    }

};

int main()
{
    int opt;
    char producator[20];
    LCD *lcd=new LCD(" ", 0, 0, " ", " ", 0);
    LCD* producatorGasit;
    LED *led=new LED(" ", 0, 0, " ", " ", 0);
    LED* producatorGasitLED;
    do
    {
        cout<<endl;
        cout<<"1. Adaugare LCD"<<endl;
        cout<<"2. Adaugare LED"<<endl;
        cout<<"3. Afisare LCD"<<endl;
        cout<<"4. Afisare LED"<<endl;
        cout<<"5. Cautare LCD"<<endl;
        cout<<"6. Cautare LED"<<endl;
        cout<<"7. Stergere LCD"<<endl;
        cout<<"8. Stergere LED"<<endl;
        cout<<"9. Sortare LCD"<<endl;
        cout<<"10. Sortare LED"<<endl;
        cout<<endl;
        cout<<"Optiune: ";
        cin>>opt;
        switch(opt)
        {
            case 0:
            break;
            case 1:
            lcd->adaugareLCD();
            break;
            case 2: 
            led->adaugareLED();
            break;
            case 3:
            lcd->afisareLCD();
            break;
            case 4:
            led->afisareLED();
            break;
            case 5:
            char producatorCautat[20];
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautat, 20);
            producatorGasit = lcd->cautareLCD(lcd->head, producatorCautat);
            if (producatorGasit)
            {
                cout << "Producatorul a fost gasit!" << endl;
                cout << "Producator: " << producatorGasit->Producator << endl;
                cout << "Diagonala: " << producatorGasit->Diagonala << endl;
                cout << "Pret: " << producatorGasit->Pret << endl;
                cout << "Tip Ecran: " << producatorGasit->TipEcran << endl;
                cout << "Conectori: " << producatorGasit->Conectori << endl;
                cout << "Timp Raspundere: " << producatorGasit->TimpRasp << endl;
            }
            else
            {
                cout << "Producatorul " << producatorCautat << " nu a fost gasit." << endl;
            }
            break;
            case 6:
            char producatorCautatLED[20];
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautatLED, 20);
            producatorGasitLED = led->cautareLED(led->head, producatorCautatLED);
            if (producatorGasitLED)
            {
                cout << "Producatorul a fost gasit!" << endl;
                cout << "Producator: " << producatorGasitLED->Producator << endl;
                cout << "Diagonala: " << producatorGasitLED->Diagonala << endl;
                cout << "Pret: " << producatorGasitLED->Pret << endl;
                cout << "Format Ecran: " << producatorGasitLED->FormatEcran << endl;
                cout << "Iluminare: " << producatorGasitLED->Iluminare << endl;
                cout << "Boxe Integrale: " << producatorGasitLED->BoxeIntegrale << endl;
            }
            else
            {
                cout << "Producatorul " << producatorCautatLED << " nu a fost gasit." << endl;
            }
            break;
            case 7:
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautat, 20);
            lcd->stergereLCD(producatorCautat);
            break;
            case 8:
            cout << "Dati producatorul cautat: ";
            cin.ignore();
            cin.getline(producatorCautatLED, 20);
            lcd->stergereLCD(producatorCautatLED);
            break;
            case 9:
            lcd->sortareLCD();
            break;
            case 10:
            led->sortareLED();
            break;
        }
    } while (opt != 0);
    return 0;
}