#include <iostream>
#include <string>

using namespace std;

template <class tipVector>class vector
{
    tipVector v[20];
    int index;
    public:
    vector()
    {
        index=0;
    }
    void introducere(tipVector ob)
    {
        v[index]=ob;
        index++;
    }
    void afisare()
    {
        if(index==0)
        cout<<"gol"<<endl;
        else
            for(int i=0;i<index;i++)
            {
                cout<<v[i]<<" ";
            }   
    }
};

int main()
{
    vector<char>v1,v2;
    v1.introducere('a');
    v2.introducere('e');
    v1.introducere('@');
    v2.introducere('%');

    v1.afisare();
    cout<<endl;
    v2.afisare();
    cout<<endl;

    vector<double>x1,x2;
    x1.introducere(1.25);
    x2.introducere(20);
    x1.introducere(3.45);
    x2.introducere(40);
    
    cout<<"----------------------"<<endl;
    x1.afisare();
    cout<<endl;
    x2.afisare();
    cout<<endl;
    return 0;

}