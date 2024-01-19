#include <iostream>

using namespace std;

	class persoana {
		char nume[30], prenume[30], telefon[30], varsta[30];
		//int varsta;
	public:
		//void setare_valori(char, char, int, char);
		//void afisare(char, char, int, char);
		void setare_valori(char num[30], char prenum[30], char varst[30], char tel[30]);
		void afisare(void);
	};

	void persoana::setare_valori(char num[30], char prenum[30], char varst[30], char tel[30])
	{
		strcpy(nume, num);
		strcpy(prenume, prenum);
		strcpy(varsta, varst);
		strcpy(telefon, tel);
	}

	void persoana::afisare(void)
	{
		cout << nume<< endl;
		cout << prenume<<endl;
		cout << varsta<<endl;
		cout << telefon<<endl;
	}

	int main()
	{
		persoana pers;
		char numele[30] = "Pula";
		char prenumele[30] = "Bleaga";
		//int varstaa = 20;
		char varstaa[30] = "20";
		char telul[30] = "0775363448";

		pers.setare_valori(numele, prenumele, varstaa, telul);
		pers.afisare();
		return 0;
	}