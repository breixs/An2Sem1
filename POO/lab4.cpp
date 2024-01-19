#include <iostream>
#include <string>

using namespace std;

class A{
    private:
    int m;
    public:
    friend class B;
    friend void g_afiseaza_m();
};

class B
{
    public: 
    void afiseaza_m()
    {
        A a;
        a.m=255;
        cout<<"clasa B e prietena cu clasa a"<<endl;
        cout<<"poate accesa membrul privat A::m"<<endl<<a.m<<endl;
    }
};

void g_afiseaza_m()
{
    A a;
    a.m=300;
    cout<<"functia nu e membru a clasei a dar e prieten"<<endl<<a.m<<endl;
}

int main()
{
 B b;
 b.afiseaza_m();
 g_afiseaza_m();
 return 0;
}