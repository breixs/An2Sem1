#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

class baza
{
protected:
    string denumire;
    int numar, tip;
public:
    baza(string denumire, int numar, int tip)
    {
        this->denumire=denumire;
        this->numar=numar;
        this->tip=tip;
    }
    virtual void afisare()
    {
        cout<<"-------------------------------------"<<endl;
        cout<<"tip: "<<tip<<endl;
        cout<<"denumire: "<<denumire<<endl;
        cout<<"numar: "<<numar<<endl;
    }
    string getDenumire()
    {
        return denumire;
    }
    int getTip()
    {
        return tip;
    }
    int getNumar()
    {
        return numar;
    }
    virtual string getCuloare(){};
    virtual int getLuceala(){};
    virtual string getCoada(){};
    virtual int getNotaGust(){};
    virtual string getTuica(){};
    virtual int getCoapte(){};
};

class mere:public baza
{
    string culoare;
    int luceala;
    public:
    mere(string denumire, int numar, string culoare, int luceala, int tip):baza(denumire, numar, tip)
    {
        this->culoare=culoare;
        this->luceala=luceala;
    }
    void afisare()
    {
        baza::afisare();
        cout<<"culoare: "<<culoare<<endl;
        cout<<"luceala(%): "<<luceala<<endl;
    }
    string getCuloare()
    {
        return culoare;
    }
    int getLuceala()
    {
        return luceala;
    }

};

class pere:public baza
{
    string coada;
    int notaGust;
    public:
    pere(string denumire, int numar, string coada, int notaGust, int tip):baza(denumire, numar, tip)
    {
        this->coada=coada;
        this->notaGust=notaGust;
    }
    void afisare()
    {
        baza::afisare();
        cout<<"coada: "<<coada<<endl;
        cout<<"nota gust: "<<notaGust<<endl;
    }
    string getCoada()
    {
        return coada;
    }
    int getNotaGust()
    {
        return notaGust;
    }
};

class prune:public baza
{
    string tuica;
    int coapte;
    public:
    prune(string denumire, int numar, string tuica, int coapte, int tip):baza(denumire, numar, tip)
    {
        this->tuica=tuica;
        this->coapte=coapte;
    }
    void afisare()
    {
        baza::afisare();
        cout<<"tuica: "<<tuica<<endl;
        cout<<"coapte: "<<coapte<<endl;
    }
    string getTuica()
    {
        return tuica;
    }
    int getCoapte()
    {
        return coapte;
    }
};

void adaugare(list<baza*> &obj_list)
{
    baza* b;
    string denumire, culoare, tuica, coada;
    int tip, numar, luceala, coapte, opt, notaGust;
    cout<<"opt adaugare(1-mere, 2-pere, 3-prune): ";
    cin>>opt;
    cout<<"denumire: ";
    cin>>denumire;
    cout<<"numar: ";
    cin>>numar;
    if(opt==1)
    {
        cout<<"culoare: ";
        cin>>culoare;
        cout<<"luceala: ";
        cin>>luceala;
        mere* m=new mere(denumire, numar, culoare, luceala, 1);
        b=m;
    }
    else if(opt==2)
    {
        cout<<"coada: ";
        cin>>coada;
        cout<<"nota gust: ";
        cin>>notaGust;
        pere* p=new pere(denumire, numar, coada, notaGust, 2);
        b=p;
    }
    else if(opt==3)
    {
        cout<<"tuica: ";
        cin>>tuica;
        cout<<"coapte(1-da, 2-nu): ";
        cin>>coapte;
        prune* pr=new prune(denumire, numar, tuica, coapte, 3);
        b=pr;
    }
    obj_list.push_back(b);

}

void getData(list <baza*> &obj_list)
{
    string denumire, culoare, coada, tuica;
    int numar, luceala, notaGust, coapte, tip;
    baza* b;
    ifstream fis("fructe.txt");
        while(fis>>tip)
        {
            fis>>denumire;
            fis>>numar;
            if(tip==1)
            {
                fis>>culoare;
                fis>>luceala;
                mere* m=new mere(denumire, numar, culoare, luceala, 1);
                b=m;
            }
            else if(tip==2)
            {
                fis>>coada;
                fis>>notaGust;
                pere* p=new pere(denumire, numar, coada, notaGust, 2);
                b=p;
            }
            else if(tip==3)
            {
                fis>>tuica;
                fis>>coapte;
                prune* pr=new prune(denumire, numar, tuica, coapte, 3);
                b=pr;
            }
            obj_list.push_back(b);
        }
    fis.close();
}

void saveData(list<baza*> &obj_list)
{
    ofstream fis("fructe.txt");

    if(obj_list.empty())
        cout<<"ce faci ba"<<endl;
    else
    {
        for(auto b: obj_list)
        {
            fis<<b->getTip()<<endl;
            fis<<b->getDenumire()<<endl;
            fis<<b->getNumar()<<endl;
            if(b->getTip()==1)
            {
                fis<<b->getCuloare()<<endl;
                fis<<b->getLuceala()<<endl;
                //fis<<"-------------------------------------"<<endl;
            }
            else if(b->getTip()==2)
            {
                fis<<b->getCoada()<<endl;
                fis<<b->getNotaGust()<<endl;
                //fis<<"-------------------------------------"<<endl;
            }
            else if(b->getTip()==3)
            {
                fis<<b->getTuica()<<endl;
                fis<<b->getCoapte()<<endl;
                //fis<<"-------------------------------------"<<endl;
            }
        }
    }
    fis.close();
}

void cautare(list <baza*> &obj_list)
{
    string cautat;
    cout<<"introdu numele cautat: ";
    cin>>cautat;
    list<baza*>::iterator iter;
    for(iter=obj_list.begin(); iter!=obj_list.end();)
    {
        if(cautat==(*iter)->getDenumire())
        {
            cout<<"element gasit!"<<endl;
            (*iter)->afisare();
        }
        iter++;
    }
}

void stergere(list <baza*> &obj_list)
{
    string sters;
    cout<<"introdu numele pe care il doresti sters:";
    cin>>sters;
    list<baza*>::iterator iter;
    for(iter=obj_list.begin();iter!=obj_list.end();)
    {
        if(sters==(*iter)->getDenumire())
        {
            delete *iter;
            iter=obj_list.erase(iter);
            cout<<"sters";
        }
        else
        iter++;
    }
}

int main()
{
    list <baza*> bazalist;
    list<baza*>::iterator iter;
    int opt;
    do{
        cout<<"opt: ";
        cin>>opt;
        switch(opt)
        {
            case 0:
            break;
            case 1:
            adaugare(bazalist);
            break;
            case 2:
            for(iter=bazalist.begin(); iter!=bazalist.end();)
            {
                (*iter)->afisare();
                iter++;
            }
            break;
            case 3:
            bazalist.sort([](baza* b1, baza* b2)
            {
                return b1->getDenumire()<b2->getDenumire();
            });
            for(iter=bazalist.begin(); iter!=bazalist.end();)
            {
                (*iter)->afisare();
                iter++;
            }
            break;
            case 4:
            getData(bazalist);
            break;
            case 5:
            saveData(bazalist);
            break;
            case 6:
            cautare(bazalist);
            break;
            case 7:
            stergere(bazalist);
            break;
            default:
            break;
        }
    }while(opt!=0);

    return 0;
}

