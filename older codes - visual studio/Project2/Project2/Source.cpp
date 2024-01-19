#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fis("pule.txt");
	fis << "uatafac";
	fis.close();
	ifstream fis2("pule.txt");
	string buffer;
	fis2 >> buffer;
	cout << buffer;
	return 0;
}