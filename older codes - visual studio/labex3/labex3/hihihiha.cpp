#include <iostream>

using namespace std;

int suma(int nr1, int nr2)
{
	return nr1 + nr2;
}
float sumafloat(int nr1, int nr2)
{
	return nr1 + nr2;
}

int main()
{
	int a, b;
	cout << "val nr a= ";
	cin >> a;
	cout << "val nr b= ";
	cin >> b;
	float x, y;
	cout << "val nr x= ";
	cin >> x;
	cout << "val nr y= ";
	cin >> y;

	cout << "suma nr intreg: " << suma(a, b) << endl;
	cout << "suma nr float: " << sumafloat(x, y) << endl;
	getchar();
	return 0;
}