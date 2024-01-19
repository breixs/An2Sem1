#include<iostream>
#include <string>

using namespace std;

class employee{
    private:
        int age;
        string name, company;
    public:
    string getName(){
        return name;
    }
    string getCompany()
    {
        return company;
    }
    int getAge(){
        return age;
    }
    employee(){
        getline(cin, name);
        getline(cin, company);
        do{
            cin>>age;
            if(age<18)
                cout<<"prea mic, incearca din nou"<<endl;
        }while(age<18);
    }

    void introduce(){
        cout<< name<<endl;
        cout<<company<<endl;
        cout<< age<<endl;
    }
};

int main()
{
    employee e1=employee();
    e1.introduce();
    cout<<e1.getName()<< "'s age is "<<e1.getAge()<< " and he is working for "<<e1.getCompany()<<endl;
    return 0;
}