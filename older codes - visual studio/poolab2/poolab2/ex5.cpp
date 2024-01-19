#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Student {
	string nume, rol, adresa, codpostal;
public:
	Student()
	{
		cout << "nume: ";
		getline(cin, nume);
		cout << "rol: ";
		getline(cin, rol);
		cout << "adresa: ";
		getline(cin, adresa);
		cout << "cod postal: ";
		getline(cin, codpostal);
	}
	~Student()
	{
		cout << "s-o dat ggu" << endl;
	}
	void afisare()
	{
		cout << nume << endl;
		cout << rol << endl;
		cout << adresa << endl;
		cout << codpostal << endl;
	}
};

int main()
{
	Student s1=Student();
	s1.afisare();
	s1.~Student();
	return 0;

}