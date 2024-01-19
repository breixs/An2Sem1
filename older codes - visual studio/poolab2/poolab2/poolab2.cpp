#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Dreptunghi {
	int latime, lungime;
public:
	Dreptunghi(int a, int b)
	{
		latime = a;
		lungime = b;
	}
	int calcul_arie()
	{
		return latime * lungime;
	}
};

int main()
{
	Dreptunghi dr(2, 4);
	Dreptunghi dr2(3, 5);
	cout<<"dr1: "<<dr.calcul_arie()<<endl;
	cout<<"dr2: "<<dr2.calcul_arie()<<endl;
	//getch();
	return 0;
}