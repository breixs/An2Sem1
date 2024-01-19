#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i;

    cout<<"dimensiune vect: "<<v.size()<<endl;

    for(i=0;i<5;i++)
    {
        v.push_back(i);
    }

    cout<<"vector size nou: "<<v.size()<<endl;

    for(i=0;i<5;i++)
    {
        cout<<"val vect [ "<< i << "] = " << v[i]<<endl;
    }

    vector<int>::iterator vect=v.begin();
    while(vect != v.end())
    {
        cout<< "val lui vect = " << *vect <<endl;
        vect++;
    }

    for(i=0;i<5;i++)
    {
        cout<<v[i];
    }

    return 0;

}