#include <iostream>

using namespace std;

template <class tipVector> class vector
{
    tipVector v[20];
    int index;
    public:
    vector() {index=0;};
    void intorducere(tipVector ob)
    {
        v[index]=ob;
        index++;
    }
    void afisare()
    {
        if(index==0)
        cout<<"sugi pula!"<<endl;
        else
        {
            for(int i=0;i<index;i++)
            {
                cout<<v[i]<<" ";
            }
        }
    }
};

int main()
{
    vector<char>v1,v2;
    v1.intorducere('a');
    v2.intorducere('@');
    v1.intorducere('b');
    v2.intorducere('&');
    v1.intorducere('c');
    v2.intorducere('%');

    cout<<"afisare vect char: "<<endl;
    v1.afisare();
    cout<<endl;
    v2.afisare();
    cout<<endl;

    vector<double> x1, x2;
    x1.intorducere(1);
    x2.intorducere(20);
    x1.intorducere(3);
    x2.intorducere(40);
    x1.intorducere(5);
    x2.intorducere(60);

    cout << "Vectorii cu elemente de tip int:\n";
    x1.afisare();
    cout << "\n";
    x2.afisare();
    cout << "\n";
    return 0;

}