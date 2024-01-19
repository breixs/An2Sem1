#include <iostream>
#include <cstring>

using namespace std;

class student{
    string nume;
    string prenume;
    int varsta;
public:
    student(string n, string p, int v)
    {
        nume=n;
        prenume=p;
        varsta=v;
    }
friend ostream &operator<<(ostream&iesire, student s);

};

ostream &operator<<(ostream &iesire, student s)
{
    // iesire<<s.nume<<" "<<s.prenume;
    // iesire<<" are "<<s.varsta<<" de ani"<<"\n";
    iesire<<s.nume<<"\n";
    return iesire;
}

int main()
{
    student s1("Brei", "Paul", 20);
    student s2("Caca", "Maca", 69);
    cout<<s1<<s2;
    return 0;
}
