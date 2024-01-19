#include <iostream>
#include <string>

using namespace std;

class Profesor {
	string nume, departament, grad;
	int vechime;
	public:
		Profesor()
		{
			cout << "nume= ";
			getline(cin, nume);
			cout << "departament= ";
			getline(cin, departament);
			cout << "grad= ";
			getline(cin, grad);
			cout << "vechime: ";
			cin >> vechime;
		}
		Profesor(string n, string d, string g, int v)
		{
			nume = n;
			departament = d;
			grad = g;
			vechime = v;
		}
		void afisare()
		{
			cout << nume << endl;
			cout << departament << endl;
			cout << grad << endl;
			cout << vechime << endl;
		}
};

int main()
{
	Profesor p1;
	Profesor p2("lupa", "nuj", "igen", 60);
	p1.afisare();
	p2.afisare();
	return 0;

}