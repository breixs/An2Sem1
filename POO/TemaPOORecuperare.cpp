#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

class site{
protected:
    string denumire;
    int tip;
public:
    site(string denumire, int tip)
    {
        this->denumire=denumire;
        this->tip=tip;
    }
    virtual void afisare()
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"denumire: "<<denumire<<endl;
    }
    string getDenumire()
    {
        return denumire;
    }
    virtual int getActori()
    {
        return 0;
    }
    virtual int getNrSez()
    {
        return 0;
    }
    int getTip()
    {
        return tip;
    }
};

class film:public site
{
    int actori;
public:
    film(string denumire, int actori, int tip):site(denumire, tip)
    {
        this->actori=actori;
    }
    void afisare()
    {
        site::afisare();
        cout<<"Numar Actori: "<<actori<<endl;
    }
    int getActori()
    {
        return actori;
    }
};

class serial:public site{
    int nrSezoane;
public:
    serial(string denumire, int nrSezoane, int tip):site(denumire, tip)
    {
        this->nrSezoane=nrSezoane;
    }
    void afisare()
    {
        site::afisare();
        cout<<"Numar Sezoane: "<<nrSezoane<<endl;
    }
    int getNrSez()
    {
        return nrSezoane;
    }
};

void adaugare(list <site*> &obj_list)
{
    string denumire;
    int actori, nrSezoane, tip, opt;
    bool ok=false;
    site* s;
    do{
        try{
            cout<<"opt adaugare(1-film, 2-serial): ";
            cin>>opt;
            if(opt<1||opt>2||cin.fail())
            {
                ok=false;
                cin.clear();
                cin.ignore();
                throw(100);
            }
            else
            ok=true;
        }
        catch(int x)
        {
            cout<<"eroare: "<<x<<endl;
        }
    }while(opt<1||opt>2||ok==false);
    cout<<"denumire: ";
    cin>>denumire;
    if(opt==1)
    {
        cout<<"actori: ";
        cin>>actori;
        film* fl;
        fl=new film(denumire, actori, 1);
        s=fl;
    }
    else
    {
        cout<<"numar sezoane: ";
        cin>>nrSezoane;
        serial* sl;
        sl=new serial(denumire, nrSezoane, 2);
        s=sl;
    }
    obj_list.push_back(s);
}

void getData(list <site*> &obj_list)
{
    site* s;
    string denumire;
    int actori, nrSezoane, tip;

    ifstream fis("sites.txt");

    while(fis>>tip)
    {
        fis>>denumire;
        if(tip==1)
        {
            fis>>actori;
            film* fl=new film(denumire, actori, tip);
            s=fl;
        }
        else
        {
            fis>>nrSezoane;
            serial* sl=new serial(denumire, nrSezoane, tip);
            s=sl;
        }
        obj_list.push_back(s);
    }
    fis.close();
}

void saveData(list <site*> &obj_list)
{
    ofstream fis("sites2.txt");
    if(obj_list.empty()==true)
    cout<<"pula"<<endl;
    else
    {
        for(auto s : obj_list)
        {
            fis<<"tip: "<<s->getTip()<<endl;
            cout<<s->getTip()<<endl;
            fis<<"denumire: "<<s->getDenumire()<<endl;
            if(s->getTip()==1)
                fis<<"actori: "<<s->getActori()<<endl;
            else
                fis<<"numar sezoane: "<<s->getNrSez()<<endl;
            fis<<"----------------------------------------"<<endl;
        }
    }
    fis.close();
}

void cautare(list <site*> &obj_list)
{
    int opt, actoriCautati, nrSezCautat;
    string denumireCautata;
    list <site*>::iterator iter;
    cout<<"introduceti categoria in care doriti sa cautati(1-denumire, 2-actori, 3-nr sezoane): ";
    cin>>opt;
    switch(opt)
    {
        case 1:
        cout<<"denumirea cautata: ";
        cin>>denumireCautata;
        for(iter=obj_list.begin();iter!=obj_list.end();)
        {
            if(denumireCautata==(*iter)->getDenumire())
            {
                cout<<"element gasit!"<<endl;
                (*iter)->afisare();
            }
            iter++;
        }
        break;
        case 2:
        cout<<"actorii cautati: ";
        cin>>actoriCautati;
        for(iter=obj_list.begin();iter!=obj_list.end();)
        {
            if(actoriCautati==(*iter)->getActori())
            {
                cout<<"element gasit"<<endl;
                (*iter)->afisare();
            }
            iter++;
        }
        break;
        case 3:
        int minInterval, maxInterval;
        cout<<"nr sez cautate interval minim: ";
        cin>>minInterval;
        cout<<"nr sez cautate interval maxim: ";
        cin>>maxInterval;
        for(iter=obj_list.begin(); iter!=obj_list.end();)
        {
            if((*iter)->getNrSez()>=minInterval && (*iter)->getNrSez()<=maxInterval)
            {
                cout<<"element gasit"<<endl;
                (*iter)->afisare();
            }
            iter++;
        }
        break;
        default:
        cout<<"nemtudom"<<endl;
        break;
    }

}

class Supraincarcare
{
    public:
    string sters;
    public:
    friend ostream &operator<<(ostream &out, Supraincarcare &a)
    {
        out<<"denumirea obiectului care este dorit sa fie sters: "<<endl;
        return out;
    }
    friend istream &operator>>(istream &in, Supraincarcare &a)
    {
        cout<<"obiectul: ";
        in>>a.sters;
        return in;
    }
};

void stergere(list <site*> &obj_list)
{
    ofstream fis("sters.txt");
    site* s;
    list <site*>::iterator iter;
    Supraincarcare supra;
    cout<<supra;
    cin>>supra;
    string sters=supra.sters;
    for(iter=obj_list.begin();iter!=obj_list.end();)
    {
        if(sters==(*iter)->getDenumire())
        {
             fis<<"tip: "<<(*iter)->getTip()<<endl;
            cout<<(*iter)->getTip()<<endl;
            fis<<"denumire: "<<(*iter)->getDenumire()<<endl;
            if((*iter)->getTip()==1)
                fis<<"actori: "<<(*iter)->getActori()<<endl;
            else
                fis<<"numar sezoane: "<<(*iter)->getNrSez()<<endl;
            fis<<"----------------------------------------"<<endl;
            delete *iter;
            iter=obj_list.erase(iter);
            cout<<"obiectul a fost sters!"<<endl;
        }
        else
        iter++;
    }
}

int main()
{
    list <site*> sitelist;
    list <site*>::iterator iter;
    int opt;
    do{
        cout<<"1. Adaugare din fisier"<<endl;
        cout<<"2. Adaugare de la tastatura"<<endl;
        cout<<"3. Afisare si ordonare pe categorii"<<endl;
        cout<<"4. Salvare date intr-un fisier"<<endl;
        cout<<"5. Cautare pe domenii. In cazul selectarii Nr Sezoane, se va cauta intr-un interval"<<endl;
        cout<<"6. Stergearea unui obiect si salvarea acestuia intr-un fisier sters.txt"<<endl;
        cout<<"Optiunea aleasa: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            getData(sitelist);
            break;
            break;
            case 2:
            adaugare(sitelist);
            break;
            case 3:
            int opt;
            cout<<"introduceti domeniul dupa care doriti sa se creeze sortarea(1-denumire, 2-actori, 3-nrSez): ";
            cin>>opt;
            if(opt==1)
            {
                sitelist.sort([](site* s1, site* s2)
                {return s1->getDenumire()<s2->getDenumire();});
                for(iter=sitelist.begin();iter!=sitelist.end();)
                {
                    (*iter)->afisare();
                    iter++;
                }
            }
            else if(opt==2)
            {
                sitelist.sort([](site* s1, site* s2)
                {return s1->getActori()<s2->getActori();});
                for(iter=sitelist.begin();iter!=sitelist.end();)
                {
                    (*iter)->afisare();
                    iter++;
                }
            }
            else if(opt==3)
            {
                sitelist.sort([](site* s1, site* s2)
                {return s1->getNrSez()<s2->getNrSez();});
                for(iter=sitelist.begin();iter!=sitelist.end();)
                {
                    (*iter)->afisare();
                    iter++;
                }
            }
            else
            cout<<"optiune invalida! "<<endl;
            break;
            case 4:
            saveData(sitelist);
            case 5:
            cautare(sitelist);
            break;
            case 6:
            stergere(sitelist);
            break;
            case 0:
            break;
        }
    }while(opt!=0);
    return 0;
}