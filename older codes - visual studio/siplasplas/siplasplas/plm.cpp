#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int nr;
	cout << "valoarea intreaga a nr: ";
	cin >> nr;
	int suma = 0, produs = 1;
	while (nr != 0)
	{
		if (nr % 2 == 0)
			suma = suma + nr;
		else
			produs = produs * nr;
		cout << " val nr intreg :";
		cin >> nr;
	}
	cout << "suma: " << suma << endl;
	cout << "prod: " << produs;

	return 0;
}



