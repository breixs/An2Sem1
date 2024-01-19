#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Persoana {
	string nume, prenume;
	unsigned int varsta;
public:
	Persoana(string n, string p, int v)
	{
		nume = n;
		prenume = p;
		varsta = v;
	}

	void afisare_date()
	{
		cout << nume << endl;
		cout << prenume << endl;
		cout << varsta << endl;
	}
};

int main()
{
	string n1;
	string pren1;
	int v1;

	cout << "nume: ";
	getline(cin, n1);
	cout << "prenume: ";
	getline(cin, pren1);
	cout << "varsta: ";
	cin >> v1;

	Persoana p(n1, pren1, v1);
	p.afisare_date();
	return 0;
}