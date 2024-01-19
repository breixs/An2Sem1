#include <iostream>

using namespace std;

class sofer {
	char nume_sofer[30], cnp[30];
	int varsta;
	char adresa[30];
public:
	void citire(char nume[30], char cnp1[30], int vrs, char adr[30]);
	void afisare(void);
};

class masina {
	char producator[30], model[30];
	int an;
	char sofer[30];
public:
	void citire(char prod[30], char mod[30], int a, char sof[30]);
	void afisare(void);
};

void sofer::citire(char nume[30], char cnp1[30], int vrs, char adr[30])
{
	strcpy(nume_sofer, nume);
	strcpy(cnp, cnp1);
	varsta = vrs;
	strcpy(adresa, adr);
}

void sofer::afisare(void)
{
	cout << nume_sofer<<endl;
	cout << cnp<<endl;
	cout << varsta<<endl;
	cout << adresa<<endl;
}

void masina::citire(char prod[30], char mod[30], int a, char sof[30])
{
	strcpy(producator, prod);
	strcpy(model, mod);
	an = a;
	strcpy(sofer, sof);
}

void masina::afisare()
{
	cout << producator<< endl;
	cout << model<<endl;
	cout << an<<endl;
	cout << sofer<<endl;
}

int main()
{
	sofer sof;
	masina mas;
	char nume[30]="gica", cnp[30]="5030605350050", adresa[30]="visinului, 1";
	int varsta=20;

	//cout << "varsta= "; cin >> varsta;
	sof.citire(nume, cnp, varsta, adresa);
	sof.afisare();

	char marca[30] = "renault", model[30] = "megane";
	int an = 2007;

	mas.citire(marca, model, an, nume);
	mas.afisare();
	return 0;

}