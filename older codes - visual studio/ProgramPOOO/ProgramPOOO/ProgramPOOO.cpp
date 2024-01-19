#include<iostream>
#include <string>

using namespace std;

class Persoana
{
protected:
    string firma, CEO;

public:
    Persoana() {
    }

    void setPers()
    {
        cout << "firma: ";
        getline(cin, firma);
        cout << "CEO: ";
        getline(cin, CEO);
    }

    string getFirma()
    {
        return firma;
    }

    string getCEO()
    {
        return CEO;
    }

    void afiseazaPers()
    {
        cout << "Firma: " << firma << endl;
        cout << "CEO: " << CEO << endl;
    }
};
class Manager : protected Persoana
{
    string nume;
    int salar;
public:
    Manager()
    {
        setPers();
        cout << "nume manager: ";
        getline(cin, nume);
        cout << "salar manager: ";
        cin >> salar;
    }
    void afiseazaManager()
    {
        cout << endl << " Detalii Firma: " << endl;
        afiseazaPers();
        cout << "Manager: " << endl;
        cout << "nume= " << nume << endl;
        cout << "salar= " << salar << endl << endl;
    }
};

class HR : protected Persoana {
    string Rec;
    int nrAngajati;
public:
    HR()
    {
        setPers();
        cout << "Nume Recruiter HR: ";
        getline(cin, Rec);

        cout << "numar angajati HR: ";
        cin >> nrAngajati;
    }
    void afiseazaHR()
    {
        cout << endl << "Detalii Firma: " << endl;
        afiseazaPers();
        cout << "HR: " << endl;
        cout << "recruiter= " << Rec << endl;
        cout << "numar angajati= " << nrAngajati << endl << endl;
    }
};

int main()
{
    Manager m1 = Manager();
    m1.afiseazaManager();
    HR h1 = HR();
    h1.afiseazaHR();
    return 0;
}