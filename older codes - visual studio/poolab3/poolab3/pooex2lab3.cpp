#include <iostream>
#include <string>

using namespace std;
//clasa baza
class Persoana {
protected:
	string nume;
	int varsta;
public:
	Persoana() {}
	Persoana(string n, int v)
	{
		nume = n;
		varsta = v;
	}
	void afisarePers()
	{
		cout <<"numele persoanei: "<< nume << endl;
		cout <<"varsta persoanei: "<< varsta << endl;
	}
};
//clasa derivata student
class Student :public Persoana {
	int an;
	string faculta;
public:
	Student(){}
	Student(string n, int v, string fac, int a) :Persoana(n, v)
	{
		an = a;
		faculta = fac;
	}
	void afisareStud()
	{
		afisarePers();
		cout << "anul studentului: " << an << endl;
		cout << "faculta studentului: " << faculta << endl;
	}
	string returnNume()
	{
		return Persoana::nume;
	}

};

//clasa derivata angajat
class Angajat :public Persoana {
protected:
	int salar;
	string locMunca;
public:
	Angajat() {}
	Angajat(string n, int v, int s, string loc) :Persoana(n, v)
	{
		salar = s;
		locMunca = loc;
	}
	void afisareAngajat()
	{
		afisarePers();
		cout << "Salar angajat " << salar << endl;
		cout << "Loc munca angajat : " << locMunca << endl;
	}

};

//clasa derivataX2 stud licena
class StudentLicenta :public Student, public Persoana {
protected:
	int restante;
	string FC;
public:
	StudentLicenta() {}
	StudentLicenta(string n, int v,string fac, int a, string fc, int r) :Student(n,v,fac,a),Persoana(n,v)
	{
		restante = r;
		FC = fc;
	}
	void afisareStudL()
	{
		afisareStud();
		cout << "Anul studLicenta: " << restante << endl;
		cout << "Faculta studLicenta: " << FC << endl;
	}
};


//clasa derivataX2 stud master
class StudentMaster :public Student, public Persoana {
protected:
	int pisare;
	string master;
public:
	StudentMaster() {}
	StudentMaster(string n, int v, string fac, int a, string mas, int p) :Student(n, v, fac, a),Persoana(n,v)
	{
		pisare = p;
		master = mas;
	}
	void afisareStudM()
	{
		afisareStud();
		cout << "Nivel jet student Master: " << pisare << endl;
		cout << "Domeniu Master: " <<master<<endl;
	}
};


//clasa derivataX2 stud doctorat
class StudentDoctorat :public Student, public Persoana {
protected:
	int notaDoc;
	string domeniu;
public:
	StudentDoctorat() {}
	StudentDoctorat(string n, int v, string fac, int a, string dom, int nD) :Student(n, v, fac, a),Persoana(n,v)
	{
		notaDoc = nD;
		domeniu = dom;
	}
	void afisareStudD()
	{
		afisareStud();
		cout << "Nota la Doctorat: " << notaDoc << endl;
		cout << "Domeniu Doctorat: " << domeniu << endl;
	}
};

//clasa derivata X2 prof
class Profesor :public Angajat, public Persoana {
protected:
	int aniPredare;
	string materie;
public:
	Profesor() {}
	Profesor(string n, int v, int s, string loc, string mat, int anP ) :Angajat(n, v, s, loc), Persoana(n, v)
	{
		aniPredare = anP;
		materie = mat;
	}
	void afisareStud()
	{
		afisareAngajat();
		cout << "Ani Predare: " << aniPredare << endl;
		cout << "Materie Predata: " << materie << endl;
	}
};

//clasa derivataX2 inginer
class Inginer :public Angajat, public Persoana {
protected:
	int aniInginerie;
	string domeniu;
public:
	Inginer() {}
	Inginer(string n, int v, int s, string loc, string dom, int anI) :Angajat(n, v, s, loc), Persoana(n, v)
	{
		aniInginerie = anI;
		domeniu = dom;
	}
	void afisareStud()
	{
		afisareAngajat();
		cout << "Ani de practica: " << aniInginerie << endl;
		cout << "Domeniu Inginer: " << domeniu << endl;
	}
};

int main()
{
	string n, fac, loc, fc, mas, dom, mat, domen, nCautat;
	int v, a, s, r, p, nD, anP, anI;

	StudentLicenta licentiati[20];
	StudentMaster masterati[20];
	StudentDoctorat doctorati[20];

	Profesor profesor[20];
	Inginer ingineri[20];

	int opt, nrL=0, nrD=0, nrM=0, nrP=0, nrI=0, ok=0;

	do{
		cout << "opt= ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "numaru de licentiati: ";
			cin >> nrL;
			for (int i = 0; i < nrL; i++)
			{
				cout << "nume: ";
				cin.ignore();
				getline(cin, n);
				cout << "varsta: ";
				cin >> v;
				cout << "faculta: ";
				cin.ignore();
				getline(cin, fac);
				cout << "an: ";
				cin >> a;
				cout << "fc: ";
				cin.ignore();
				getline(cin, fc);
				cout << "restante: ";
				cin >> r;
				licentiati[i] = StudentLicenta(n, v, fac, a, fc, r);
			}
			break;
		case 2:
			cout << "numaru de masterati: ";
			cin >> nrM;
			for (int i = 0; i < nrM; i++)
			{
				cout << "nume: ";
				cin.ignore();
				getline(cin, n);
				cout << "varsta: ";
				cin >> v;
				cout << "faculta: ";
				cin.ignore();
				getline(cin, fac);
				cout << "an: ";
				cin >> a;
				cout << "master: : ";
				cin.ignore();
				getline(cin, mas);
				cout << "jet: ";
				cin >> p;
				masterati[i] = StudentMaster(n, v, fac, a, mas, p);
			}
			break;
		case 3:
			cout << "numaru de doctori: ";
			cin >> nrD;
			for (int i = 0; i < nrD; i++)
			{
				cout << "nume: ";
				cin.ignore();
				getline(cin, n);
				cout << "varsta: ";
				cin >> v;
				cout << "faculta: ";
				cin.ignore();
				getline(cin, fac);
				cout << "an: ";
				cin >> a;
				cout << "domeniu doctorat: ";
				cin.ignore();
				getline(cin, dom);
				cout << "nota doctorat ";
				cin >> nD;
				doctorati[i] = StudentDoctorat(n, v, fac, a, dom, nD);
			}
			break;
		case 4:
			// citire prof
			break;
		case 5:
			// citire inginer
			break;
		case 6:
			if (nrL > 0)
			{
				for (int i = 0; i < nrL; i++)
					licentiati[i].afisareStudL();
				cout << endl;
			}
			if (nrM > 0)
			{
				for (int i = 0; i < nrM; i++)
					masterati[i].afisareStudM();
				cout << endl;
			}
			if (nrD > 0)
			{
				for (int i = 0; i < nrD; i++)
					doctorati[i].afisareStudD();
				cout << endl;
			}
		case 7: 
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrL; i++)
			{
				if(nCautat==licentiati[i].returnNume())
				{
					cout << "student gasit: " << licentiati[i].returnNume() << " pe indexul " << i << endl;
					ok = 1;
				}
			}
			if(ok==0)
				cout << "studentul nu a fost gasit!"<<endl;
			break;
		case 8:
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrM; i++)
			{
				if (nCautat == masterati[i].returnNume())
				{
					cout << "student gasit: " << masterati[i].returnNume() << " pe indexul " << i << endl;
					ok = 1;
				}
			}
			if (ok == 0)
				cout << "studentul nu a fost gasit!" << endl;
			break;
		case 9:
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrL; i++)
			{
				if (nCautat == doctorati[i].returnNume())
				{
					cout << "student gasit: " << doctorati[i].returnNume() << " pe indexul " << i << endl;
					ok = 1;
				}
			}
			if (ok == 0)
				cout << "studentul nu a fost gasit!" << endl;
			break;
		case 10:
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrL; i++)
			{
				if (nCautat == licentiati[i].returnNume())
				{
					for (int j = i; j < nrL; j++)
						licentiati[j] = licentiati[j + 1];
					nrL--;
					ok = 1;
				}
			}
			if (ok == 0)
			{
				cout << "numele nu o fost gasit" << endl;
			}
			break;
		case 11:
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrM; i++)
			{
				if (nCautat == masterati[i].returnNume())
				{
					for (int j = i; j < nrL; j++)
						masterati[j] = masterati[j + 1];
					nrM--;
					ok = 1;
				}
			}
			if (ok == 0)
			{
				cout << "numele nu o fost gasit" << endl;
			}
			break;
		case 12:
			ok = 0;
			cout << "numele cautat: ";
			cin.ignore();
			getline(cin, nCautat);
			for (int i = 0; i < nrD; i++)
			{
				if (nCautat == doctorati[i].returnNume())
				{
					for (int j = i; j < nrL; j++)
						doctorati[j] = doctorati[j + 1];
					nrD--;
					ok = 1;
				}
			}
			if (ok == 0)
			{
				cout << "numele nu o fost gasit" << endl;
			}
			break;
		case 0:
			break;
		}
	} while (opt != 0);

	return 0;

}