#include<iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Persoana
{
protected:
string firma,CEO;

public:
Persoana(string x, string y){ 
    firma=x;
    CEO=y;
}  

virtual void afiseazaPers()=0; 
};

class Manager: protected Persoana
{
    string nume;
    int salar;
    public:
    Manager():Persoana("PLT", "Brei")
    {
        cout<<"Introduceti Nume Manager: ";
        getline(cin, nume);
         do{
        cout<<"Introduceti Salar Manager: ";
        cin>>salar;
        try{
            if(salar<0)
            throw salar;
        }
        catch(int i){
            cout<<"Salarul trebuie sa fie pozitiv"<<endl;
        }
        }while(salar<0);

    }
    void afiseazaPers()
    {
        cout<<endl<<" Detalii Firma: "<<endl;
        cout<<"Firma: "<<firma<<endl;
        cout<<"CEO: "<<CEO<<endl<<endl;
        cout<<"Detalii Manager: "<<endl;
        cout<<"Nume Manager= "<<nume<<endl;
        cout<<"Salar Manager= "<<salar<<endl<<endl;
    }
};

class HR: protected Persoana{
    string Rec;
    int nrAngajati;
    int ok=0;
    public:
    HR():Persoana("PLT", "Brei")
    {
        cout<<"Introduceti Nume Recruiter HR: ";
        cin.ignore();
        getline(cin, Rec);
         do{
            nrAngajati=nrAngajati;
            cout<<"Introduceti Numar Angajati HR: ";
            cin>>nrAngajati;
            try{
                if(nrAngajati<0)
                throw nrAngajati;
            }
            catch(int i){
                cout<<"Numarul de angajati trebuie sa fie pozitiv"<<endl;
            }
            // try{
            //     //if(nrAngajati>='A' || nrAngajati<='z');
            //     if(!nrAngajati)
            //     {
            //         ok=1;
            //         throw 1;
            //     }
                
            // }
            // catch(int i)
            // {
            //     cout<<"Numarul de angajati trebuie sa fie cifra"<<endl;
            // }
            try{
                if(isdigit(nrAngajati)==0);
                throw 1;
            }
            catch(int i)
            {
                cout<<"pl";
            }
    
        }while(nrAngajati<0 || isdigit(nrAngajati)!=0);
    }
    void afiseazaPers()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        cout<<"Firma: "<<firma<<endl;
        cout<<"CEO: "<<CEO<<endl<<endl;
        cout<<"Detalii HR: "<<endl;
        cout<<"Nume Recruiter= "<<Rec<<endl;
        cout<<"Numar angajati= "<<nrAngajati<<endl<<endl;
    }
};

class IT: protected Persoana{
    string limbaj;
    int salar;
    public: 
    IT():Persoana("PLT", "Brei")
    {
        cout<<"Introduceti Limbajul de programare folosit: ";
        cin.ignore();
        getline(cin, limbaj);
        cout<<"Introduceti Salar IT: ";
        cin>>salar;
    }
    void afiseazaPers()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        cout<<"Firma: "<<firma<<endl;
        cout<<"CEO: "<<CEO<<endl<<endl;
        cout<<"Detalii IT: "<<endl;
        cout<<"Limbaj= "<<limbaj<<endl;
        cout<<"Salar IT= "<<salar<<endl<<endl;
    }
};

class Design: protected Persoana{
    string UI;
    int nrAngajati;
    public: 
    Design():Persoana("PLT", "Brei")
    {
        cout<<"Introduceti Tehnica UI Folosita: ";
        cin.ignore();
        getline(cin, UI);
        cout<<"Introduceti numarul de Angajati: ";
        cin>>nrAngajati;
    }
    void afiseazaPers()
    {
        cout<<endl<<"Detalii Firma: "<<endl;
        cout<<"Firma: "<<firma<<endl;
        cout<<"CEO: "<<CEO<<endl<<endl;
        cout<<"Detalii UI: ";
        cout<<"Tehnica UI= "<<UI<<endl;
        cout<<"Numar Angajati= "<<nrAngajati<<endl<<endl;
    }
};

int main()
{
Manager m1=Manager();
m1.afiseazaPers();
HR h1=HR();
h1.afiseazaPers();
IT i1=IT();
i1.afiseazaPers();
Design d1=Design();
d1.afiseazaPers();
return 0;
}