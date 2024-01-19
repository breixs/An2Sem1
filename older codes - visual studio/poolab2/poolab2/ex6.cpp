#include <iostream>

using namespace std;

class Dreptunghi {
	int lat, lung;
public:
	void setareVal(int, int);
	int aria()
	{
		return(lat * lung);
	}
};

void Dreptunghi::setareVal(int a, int b)
{
	lat = a;
	lung = b;
}

int main()
{
	Dreptunghi a, * b, * c;
	Dreptunghi* d = new Dreptunghi[2];

	a.setareVal(1, 2);
	c = &a;
	b = new Dreptunghi;
	b->setareVal(3, 4);
	d->setareVal(5, 6);
	d[1].setareVal(7, 8);

	cout << "a aria: " << a.aria() << endl;
	cout << "*b aria: " << b->aria() << endl;
	cout << "*c aria: " << c->aria() << endl;
	cout << "d[0] aria: " << d[0].aria() << endl;
	cout << "d[1] aria: " << d[1].aria() << endl;
	return 0;

}