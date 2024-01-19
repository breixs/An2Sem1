#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

class site
{
protected:
    string denumire;
public:
    site(string denumire)
    {
        this->denumire = denumire;
    }
    // ~site();
};

class film :protected site {
    string actori;
public:
    film(string denumire, string actori) :site(denumire)
    {
        //this->denumire=denumire;
        this->actori = actori;
    }
    // ~film();
    void afisare()
    {
        cout << "denumire= " << denumire << endl;
        cout << "actori= " << actori << endl;
    }
};

class serial :protected site
{
    int nrSezoane;
public:
    serial(string denumire, int nrSezoane) :site(denumire)
    {
        this->nrSezoane = nrSezoane;
    }
    void afisare()
    {
        cout << "denumire= " << denumire << endl;
        cout << "nr sezoane= " << nrSezoane << endl;
    }
};

void addSite(list<site*>& obj_list)
{
    site* site;
    string denumire, actori;
    int nrSezoane;
    int opt;

    cout << "opt adaugare: "; cin >> opt;
    cout << "denumire= ";
    cin >> denumire;

    if (opt == 0)
    {
        cout << "actori= ";
        cin >> actori;
        film* fl = new film(denumire, actori);
        site = fl;
    }
    else {
        cout << "nr sezoane= ";
        cin >> nrSezoane;
        serial* sl = new serial(denumire, nrSezoane);
    }

}


int main()
{
    list <site*> listast;
    list <film*> listafl;
    list <serial*> listas;
    film* fl;
    serial* s;
    int opt, nrSezoane;
    string denumire, actori;
    do {
        cout << "opt= ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "denumire= ";
            cin >> denumire;
            cout << "actori= ";
            cin >> actori;
            //fl=new film(denumire, actori);
            listafl.push_back(fl);
            break;
        case 2:
            cout << "denumire= ";
            cin >> denumire;
            cout << "numar sezoane= ";
            cin >> nrSezoane;
            s = new serial(denumire, nrSezoane);
            listas.push_back(s);
            break;
        case 3:
            listafl.sort();
            for (auto p : listafl)
                p->afisare();
            break;
        case 4:
            listas.sort();
            for (auto p : listas)
                p->afisare();
            break;
        case 0:
            break;
        default:
            break;
        }

    } while (opt != 0);

    return 0;
}