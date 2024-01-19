#include <iostream>
#include <string>

using namespace std;

class employee{
int age;
string name, company;
public:
void introduce()
{
    cout << "nume: "<< name << endl;
    cout << "companie: "<< company << endl;
    cout << "age "<< age << endl;
}
void getData(string n, string c, int a)
{
    name=n;
    company=c;
    age=a;
}
void getDataByHand()
{
    getline(cin, name);
    getline(cin, company);
    cin >> age;
}
};

int main()
{
    int number;
    employee employee1, employee2;
   employee1.getData("hatz", "nuj", 69);
   employee1.introduce();
   employee1.getDataByHand();
   employee1.introduce();
    employee2.getData("ion", "amazon", 35);
    employee2.introduce();
    return 0;
}