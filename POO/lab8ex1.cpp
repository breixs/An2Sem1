#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f;
    string linie;
    f.open("fisier1.txt");
    if(f.is_open())
    {
        while(getline(f,linie))
        {
            cout<<linie<<endl;
        }
        f.close();
    }
    else
    {
        cout<<"Nu s-a putut deschide";
    }
    return 0;

}