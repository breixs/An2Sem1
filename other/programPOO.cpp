#include<iostream>
#include <string>

using namespace std;

class Persoana
{
protected:
string firma,CEO;

public:
Persoana(){ 
}  

void setPers()
{
    cout<<"Introduceti Firma: ";
    cin.ignore();
   getline(cin, firma);
   cout<<"Introduceti CEO: ";
   getline(cin, CEO);
}

void afiseazaPers()
{
    cout<<"Firma: "<<firma<<endl;
    cout<<"CEO: "<<CEO<<endl;
}    
};
class Manager: protected Persoana
{
    string nume;
    int salar;
    public:
    Manager()
    {
        setPers();
        cout<<"Introduceti Nume Manager: ";
        getline(cin, nume);
        cout<<"Introduceti Salar Manager: ";
        cin>>salar;
    }
    void afiseazaManager()
    {
        cout<<endl<<" Detalii Firma: "<<endl;
        afiseazaPers();
        cout<<"Detalii Manager: "<<endl;
        cout<<"Nume Manager= "<<nume<<endl;
        cout<<"Salar Manager= "<<salar<<endl<<endl;
    }
};

class HR: protected Persoana{
    string Rec;
    int nrAngajati;
    public:
    HR()
    {
        setPers();
        cout<<"Introduceti Nume Recruiter HR: ";
        cin.ignore();
        getline(cin, Rec);
        cout<<"Introduceti Numar Angajati HR: ";
        cin>> nrAngajati;
    }
    void afiseazaHR()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        afiseazaPers();
        cout<<"Detalii HR: "<<endl;
        cout<<"Nume Recruiter= "<<Rec<<endl;
        cout<<"Numar angajati= "<<nrAngajati<<endl<<endl;
    }
};

class IT: protected Persoana{
    string limbaj;
    int salar;
    public: 
    IT()
    {
        setPers();
        cout<<"Introduceti Limbajul de programare folosit: ";
        cin.ignore();
        getline(cin, limbaj);
        cout<<"Introduceti Salar IT: ";
        cin>>salar;
    }
    void afiseazaIT()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        afiseazaPers();
        cout<<"Detalii IT: "<<endl;
        cout<<"Limbaj= "<<limbaj<<endl;
        cout<<"Salar IT= "<<salar<<endl<<endl;
    }
};

class Design: protected Persoana{
    string UI;
    int nrAngajati;
    public: 
    Design()
    {
        setPers();
        cout<<"Introduceti Tehnica UI Folosita: ";
        cin.ignore();
        getline(cin, UI);
        cout<<"Introduceti numarul de Angajati: ";
        cin>>nrAngajati;
    }
    void afiseazaUI()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        afiseazaPers();
        cout<<"Detalii UI: ";
        cout<<"Tehnica UI= "<<UI<<endl;
        cout<<"Numar Angajati= "<<nrAngajati<<endl<<endl;
    }
};

int main()
{
Manager m1=Manager();
m1.afiseazaManager();
HR h1=HR();
h1.afiseazaHR();
IT i1=IT();
i1.afiseazaIT();
Design d1=Design();
d1.afiseazaUI();
return 0;
}