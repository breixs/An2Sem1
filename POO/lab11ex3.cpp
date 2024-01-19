#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

class student{
    string nume, rol, adresa, cod_postal;
    public: 
    string Nume()
    {
        return nume;
    }
    student(){};
    student(string n, string r, string a, string c)
    {
        nume=n;
        rol=r;
        adresa=a;
        cod_postal=c;
    }
    ~student();
    void afisare()
    {
        cout<<nume<<endl;
        cout<<rol<<endl;
        cout<<adresa<<endl;
        cout<<cod_postal<<endl;
    }
};

void citire(string nume, string rol, string adresa, string cod)
{
    cout<<"introduce date: ";
    cin>>nume;
    cin>>rol;
    cin>>adresa;
    cin>>cod;
}

int main()
{
 list <student*> lista;
 int i=0;
 student* s;
 int opt;
 string nume, rol, adresa, cod;
 do{
    cout<<"1. adaugare stud"<<endl;
    cout<<"2.afisare stud"<<endl;
    cout<<"0.iesire"<<endl;
    cout<<"opt:";
    cin>>opt;
    switch(opt)
    {
        case 1: //citire(nume, rol, adresa, cod);
            cout<<"introduce date: ";
    cin>>nume;
    cin>>rol;
    cin>>adresa;
    cin>>cod;
            s=new student(nume, rol, adresa, cod);
            lista.push_back(s);
            break;
        case 2:
            for(auto p : lista)
                p->afisare();
            break;
        case 0:
            break;
    }
 }while(opt!=0);
 return 0;
}