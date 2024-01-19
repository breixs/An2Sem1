#include <iostream>

using namespace std;

class Complexnumber{
    int real;
    float imagin;
    public:
    Complexnumber(){
    }
    Complexnumber(int r, int i){
        real=r;
        imagin=i;
    }
    void display()
    {
        cout<<"complex nr = "<<real<<"+"<<imagin<<"i"<<endl<<endl;
    }
    int getreal()
    {
        return real;
    }
    float getimg()
    {
        return imagin;
    }
};

Complexnumber add2(Complexnumber n1, Complexnumber n2)
{
    int r;
    float i;
    r=n1.getreal()+n2.getreal();
    i=n1.getimg()+n2.getimg();
    Complexnumber temp(r,i);
    return temp;
}

int main(){
    Complexnumber c1(9, 4);
    Complexnumber c2(2,3);
    Complexnumber c3;
    c1.display();
    c2.display();
    cout<<"c1+c2"<<endl;
    c3=add2(c1,c2);
    //c3.display();

    cout<<"pointer obiect"<<endl;
    Complexnumber *ptr1;
    ptr1=&c3;
    ptr1->display();
    ptr1=&c2;
    ptr1->display();
    //cout<<ptr1;
    return 0;
}