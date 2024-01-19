#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    ifstream fin;
    fout.open("fistest2.txt");
    fin.open("fistest2.txt");
    if(fout.is_open())
    {
        fout<<"prima linie: pula"<<endl;
        fout<<"a doua linie: pisda"<<endl;
        fout.close();
    }
    else{
        cout<<"nu-i bine"<<endl;
    }

    string linie;
    if(fin.is_open())
    {
        while(getline(fin, linie))
        {
            cout<<linie<<endl;
        }
        fin.close();
    }
    else
    {
        cout<<"nu-i bine"<<endl;
    }

    return 0;
}