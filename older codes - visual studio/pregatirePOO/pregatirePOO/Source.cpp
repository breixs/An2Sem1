#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
/*
Realizaţi un program care să gestioneze următoarele informaţii despre articolele
dintr-un
magazin:
 Telefon Fix cu următoarele variable: Producător, Culoare, Dimensiune
 Telefon Mobil cu următoarele variabile: Producător, Culoare, Sistem operare.
*/
class Phone
{
private:
	string producator, culoare;
	int type;
public:
	Phone(string producator, string culoare, int type) {
		this->producator = producator;
		this->culoare = culoare;
		this->type = type;
	}
	virtual void afisare() {
		cout << "********************" << endl;
		cout << "Producator: " << producator << endl;
		cout << "Culoare: " << culoare << endl;
	}
	string get_producator() { return producator; }
	string get_culoare() { return culoare; }
	int get_type() { return type; }
	string get_sistem_operare() { return 0; };
	int get_dimensiune() { return 0; };
};
class Fix : public Phone
{
private:
	int dimensiune;
public:
	Fix(string producator, string culoare, int dimensiune, int type) :
		Phone(producator, culoare, type) {
		this->dimensiune = dimensiune;
	}
	void afisare() {
		Phone::afisare();
		cout << "Dimensiune: " << dimensiune << " inch" << endl;
		cout << "********************" << endl;
	}
	// int get_dimensiune() { return dimensiune; }
};
class Mobile : public Phone
{
private:
	string sistem_operare;
public:
	Mobile(string producator, string culoare, string sistem_operare, int type) :
		Phone(producator, culoare, type) {
		this->sistem_operare = sistem_operare;
	}
	void afisare() {
		Phone::afisare();
		cout << "Sistem de Operare: " << sistem_operare << endl;
		cout << "********************" << endl;
	}
	string get_sistem_operare() { return sistem_operare; }
	//friend void cautare(List<Mobile>& list, string sistem_operare);
};
void add_produs(list<Phone*>& obj_list)
{
	Phone* produs;
	string producator, culoare;
	string sistem_operare;
	int dimensiune;
	int option;
	cout << "Produs spre adaugare (fix - 0; mobil - 1): "; cin >> option;
	cout << "Nume producator: "; cin >> producator;
	cout << "Culoare telefon: "; cin >> culoare;
	if (option) {
		cout << "Sistem de Operare: "; cin >> sistem_operare;
		Mobile* mobile = new Mobile(producator, culoare, sistem_operare, 1);
		produs = mobile;
	}
	else {
		cout << "Dimensiune: "; cin >> dimensiune;
		Fix* fix = new Fix(producator, culoare, dimensiune, 0);
		produs = fix;
	}
	obj_list.push_back(produs);
}
void save_data(list<Phone*>& obj_list)
{
	list<Phone*>::iterator iter;
	if (obj_list.size() == 0) cout << "Lista este vida!\n";
	else {
		ofstream file("phones.txt");
		for (iter = obj_list.begin(); iter != obj_list.end();) {
			file << (*iter)->get_type() << " ";
			file << (*iter)->get_producator() << " ";
			file << (*iter)->get_culoare() << " ";
			if ((*iter)->get_type()) file << (*iter)->get_sistem_operare();
			else file << (*iter)->get_dimensiune();
			file << endl;
			iter++;
		}
	}
}
void get_data(list<Phone*>& obj_list)
{
	Phone* produs;
	string producator, culoare;
	string sistem_operare;
	int dimensiune;
	int type;
	ifstream file("phones.txt");
	while (file >> type)
	{
		file >> producator;
		file >> culoare;
		if (type) {
			file >> sistem_operare;
			Mobile* mobile = new Mobile(producator, culoare, sistem_operare, 1);
			produs = mobile;
		}
		else {
			file >> dimensiune;
			Fix* fix = new Fix(producator, culoare, dimensiune, 0);
			produs = fix;
		}
		obj_list.push_back(produs);
	}
}
void cautare_produs(list<Phone*>& obj_list)
{
	string producator;
	list<Phone*>::iterator iter;
	cout << "Nume producator: "; cin >> producator;
	for (iter = obj_list.begin(); iter != obj_list.end();) {
		if (producator == (*iter)->get_producator())
			(*iter)->afisare();
		iter++;
	}
}
int main()
{
	list<Phone*> Produse;
	list<Phone*>::iterator iter;
	Phone* p;
	int option;
	do {
		system("cls");
		// meniu
		cout << "1.Citire date din fisier." << endl;
		cout << "2.Adaugare informatii in gestiunea magazinului." << endl;
		cout << "3.Afisare stocului." << endl;
		cout << "4.Salvarea stocului intr-un fisier." << endl;
		cout << "5.Cautare unui produs dupa producator." << endl;
		cout << "6. Sortare produse" << endl;
		cout << "0.Iesire" << endl;
		cout << "Optiune: " << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			get_data(Produse);
			system("pause");
			break;
		case 2:
			add_produs(Produse);
			system("pause");
			break;
		case 3:
			for (iter = Produse.begin(); iter != Produse.end();) {
				(*iter)->afisare();
				iter++;
			}
			system("pause");
			break;
		case 4:
			save_data(Produse);
			system("pause");
			break;
		case 5:
			cautare_produs(Produse);
			system("pause");
			break;
		case 6:
			cout << "Afisare sortata dupa nume" << endl;
			Produse.sort([](Phone* p1, Phone* p2)
				{ return p1->get_producator() < p2->get_producator(); });//Sorting 
				for (iter = Produse.begin(); iter != Produse.end();) {
					(*iter)->afisare();
					iter++;
				}
		case 0: break;
		default:
			cout << "Comanda gresita!" << endl;
			system("pause");
		}
	} while (option != 0);
	return 0;
}