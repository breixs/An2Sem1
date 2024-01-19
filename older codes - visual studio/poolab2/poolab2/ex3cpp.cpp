#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Carte {
	string titlu, autor, editura;
	unsigned int anP;
public:
	Carte(string t, string a, string e, unsigned int an)
	{
		titlu = t;
		autor = a;
		editura = e;
		anP = an;
	}
	void afisare()
	{
		cout << titlu << endl;
		cout << autor << endl;
		cout << editura << endl;
		cout << anP << endl;
	}
};

int main()
{
	string t, a, e;
	unsigned int an;

	cout << "titlu= ";
	getline(cin, t);
	cout << "autor= ";
	getline(cin, a);
	cout << "editura= ";
	getline(cin, e);
	cout << "an= ";
	cin >> an;
	Carte c1(t, a, e, an);
	c1.afisare();
	return 0;
}