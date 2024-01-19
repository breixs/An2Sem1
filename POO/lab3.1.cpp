#include <iostream>
#include <string>

using namespace std;

class Mamifer {
protected:
    int greutate;
    string nume;
public:
    Mamifer(int x, string y)
    {
        greutate = x;
        nume = y;
    }
    void afisareMam()
    {
        cout << greutate << endl;
        cout << nume << endl << endl;
    }
};

class Cangur :protected Mamifer {
protected:
    int nrCanguri;
    string stapin;
public:
    Cangur():Mamifer(3, "pula")
    {
        cin >> nrCanguri;
        cin.ignore();
        getline(cin, stapin);
    }
    void afisareCangur()
    {
        afisareMam();
        cout << nrCanguri << endl;
        cout << stapin << endl << endl;
    }
};

class Urs :protected Mamifer {
protected:
    int nrUrsi;
    string bere;
public:
    Urs():Mamifer(3, "pula")
    {
        cin >> nrUrsi;
        cin.ignore();
        getline(cin, bere);
    }
    void afisareUrs()
    {
        afisareMam();
        cout << nrUrsi << endl;
        cout << bere << endl << endl;
    }
};

int main()
{
    Cangur c1 = Cangur();
    c1.afisareCangur();
    Urs u1 = Urs();
    u1.afisareUrs();
 
    return 0;
}