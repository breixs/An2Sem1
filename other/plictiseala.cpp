#include <iostream>
#include <string>

using namespace std;

class obj{
int pula;
public:
obj(){
    cin>>pula;
}
void afisare()
{
    cout<<pula<<endl;
}
};

int main()
{
obj o1=obj();
obj o2=obj();
//o1.afisare();
obj *ptr;
ptr=&o1;
ptr->afisare();
ptr=&o2;
ptr->afisare();
return 0;

}