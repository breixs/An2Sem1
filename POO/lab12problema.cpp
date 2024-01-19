#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

class site
{
protected:
    string denumire;
    int tip;
public:
    site(string denumire, int tip)
    {
        this->denumire=denumire;
        this->tip=tip;
    }
    ~site()
    {
        cout<<"datele site-ului au fost sterse"<<endl;
    }
   virtual void afisare()
   {
    cout<<"---------------------------"<<endl;;
    cout<<"denumire: "<<denumire<<endl;
   }
   string getDenumire()
   {
    return denumire;
   }
   int getTip()
   {
    return tip;
   }
   string getActori()
   {
    return NULL;
   }
   virtual int getNrSez()
   {}
};

class film:public site{
    string actori;
    public:
    film(string denumire, string actori, int tip):site(denumire, tip)
    {
        //this->denumire=denumire;
        this->actori=actori;
    }
   // ~film();
    void afisare()
    {
        site::afisare();
        cout<<"actori= "<<actori<<endl;
    }
    string getActori()
    {
        return actori;
    }
};

class serial:public site
{
    int nrSezoane;
    public:
    serial(string denumire, int nrSezoane, int tip):site(denumire, tip)
    {
        this->nrSezoane=nrSezoane;
    }
    void afisare()
    {
        site::afisare();
        cout<<"nr sezoane= "<<nrSezoane<<endl;
    }
    int getNrSez()
    {
        return nrSezoane;
    }
};

void addSite(list<site*> &obj_list)
    {
        site* site;
        string denumire, actori;
        int nrSezoane;
        int opt, ok=0;
        do{
            try{
                cout<<"opt adaugare: "; 
                cin>>opt;
                if(opt<1 || opt>2 || cin.fail())
                {
                    ok=0;
                    cin.clear();
                    cin.ignore();
                    throw(100);
                }
                else{
                    ok=1;
                }
            }
            catch(int x){
            cout<<opt<<" este o optiune invalida!"<<endl;
            }
        }while(ok=0||opt<1||opt>2);

        cout<<"denumire= ";
        cin>>denumire;
        
        if(opt==1)
        {
            cout<<"actori= ";
            cin>>actori;
            film* fl=new film(denumire, actori, 1);
            site=fl;
        }
        else{
            cout<<"nr sezoane= ";
            cin>>nrSezoane;
            serial* sl=new serial(denumire, nrSezoane, 2);
            site=sl;
        }
        obj_list.push_back(site);
    }

void getData(list <site*> &obj_list)
{
    site* site;
    string denumire, actori;
    int nrSezoane;
    int tip;

    ifstream fis("sites.txt");

    while(fis>>tip)
    {
        fis>>denumire;
        if(tip==1)
        {
            fis>>actori;
            film* fl=new film(denumire, actori, 1);
            site=fl;
        }
        else{
            fis>>nrSezoane;
            serial* sl=new serial(denumire, nrSezoane, 2);
            site=sl;
        }
        obj_list.push_back(site);
    }
    fis.close();
    
}

void saveData(list <site*> &obj_list)
{
    list <site*>::iterator iter;
    int temp=0;
    if(obj_list.size()==0)
    cout<<"ai belit pula!"<<endl;
    else
    {
        ofstream fis("sites.txt");
        for(site* s : obj_list)
        {
            fis<<s->getTip()<<endl;
            temp=s->getTip();
            cout<<temp<<endl;
            fis<<s->getDenumire() <<endl;
            if(temp==1)
                fis<<dynamic_cast<film*>(s)->getActori()<<endl;
            else
                fis<<dynamic_cast<serial*>(s)->getNrSez()<<endl;
            fis<<endl;
            temp=0;
        }
        fis.close();
    }
}

void cautare(list <site*> &obj_list)
{
    list<site*>::iterator it;
    string cautat;
    int gasit=0, temp=0;
    cout<<"introdu numele cautat: ";
    cin>>cautat;
    for(it=obj_list.begin(); it !=obj_list.end();)
    {
        if(cautat==(*it)->getDenumire())
        {
            ofstream fis("cautat.txt");
            gasit++;
            (*it)->afisare();
            fis<<(*it)->getTip()<<endl;
            temp=(*it)->getTip();
            cout<<temp<<endl;
            fis<<(*it)->getDenumire() <<endl;
            if(temp==1)
                fis<<dynamic_cast<film*>(*it)->getActori()<<endl;
            else
                fis<<dynamic_cast<serial*>(*it)->getNrSez()<<endl;
            fis<<endl;
            temp=0;
            fis.close();
        }
        it++;
    }
    cout<<cautat<<" a fost gasit de "<< gasit<<" ori"<<endl;

}

class Supraincarcare
{
public:
    string denumire, actori, cautat;
    int tip, nrSezoane;
public:
    friend ostream &operator<<(ostream &out, const Supraincarcare &a)
    {
        out<<"introdu dennumirea obiectului pe care il doresti sters: "<<endl;
        return out;
    }
    friend istream &operator>>(istream &in, Supraincarcare &a)
    {
        cout<<"obiectul cautat: ";
        in>>a.cautat;
        return in;
    }
};

void stergere(list <site*> &obj_list)
{
    list<site*>::iterator iter;
    Supraincarcare supr;
    cout<<supr;
    cin>>supr;
    string cautat=supr.cautat;
    for(auto iter=obj_list.begin();iter!=obj_list.end();)
    {
        if(cautat==(*iter)->getDenumire())
        {
             delete *iter;
            iter=obj_list.erase(iter);
        }
        else
        iter++;
    }
}

int main()
{
    list <site*> sitelist;
    list <site*>::iterator iter;
    site* s;
    int opt, nrSezoane;
    string denumire, actori;
    do{
        cout<<"opt= ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            getData(sitelist);
            break;
        case 2:
           addSite(sitelist);
           break;
        case 3:
            sitelist.sort([](site* s1, site* s2) 
            { return s1->getDenumire() < s2->getDenumire(); });
            for(iter=sitelist.begin(); iter !=sitelist.end();)
            {
                (*iter)->afisare();
                iter++;
            }
            cout<<"---------------------------"<<endl;
            break;
        case 4:
            saveData(sitelist);
            break;
        case 5:
            cautare(sitelist);
            break;
        case 6:
            stergere(sitelist);
            break;
        case 0:
            break;
        default:
            break;
        }

    }while(opt!=0);

    return 0;
}