#include <iostream>
#include <string>

using namespace std;

class Nuj{
    int a;
    string b;
    public:
    Nuj();
    Nuj(int, string);
    void afiseazaNuj();
};
Nuj::Nuj()
{
    cin>>a;
    cin.ignore();
    getline(cin,b);
}
Nuj::Nuj(int a, string b)
{
this->a=a;
this->b=b;
}
void Nuj::afiseazaNuj()
{
    cout<<a<<endl;
    cout<<b<<endl<<endl;
}

int main()
{
Nuj n1=Nuj();
Nuj n2=Nuj(3,"caca");
n1.afiseazaNuj();
n2.afiseazaNuj();
return 0;

}