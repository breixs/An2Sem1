#include <iostream>

using namespace std;

class student{
public: 
    string nume;
    string prenume;
    unsigned int varsta;
    int nrMatricol;

    student(string n, string p, unsigned int v, int nr)
    {
        nume=n;
        prenume=p;
        varsta=v;
        nrMatricol=nr;
    }
};

ostream &operator<<(ostream&iesire,student s)
{
iesire<<s.nume<<" "<<s.prenume;
iesire<<" are "<<s.varsta<<" ani";
iesire<<" numar matriclor "<<s.nrMatricol<<"\n";
}

int main()
{
student s1("Brei", "Paul", 20, 1337);
student s2("Pula", "Bleaga", 69, 8008);

cout<<s1<<s2;
return 0;
}