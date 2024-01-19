#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void showlist(list <int> g)
{
    list <int>::iterator it;
    for(it=g.begin(); it !=g.end(); ++it)
        cout<< " "<<*it<<endl;
}

int main()
{
    list <int> list1, list2;

    for(int i=0;i<10;i++)
    {
        list1.push_back(i*2);
        list2.push_back(i*3);
    }

    cout<<"\nlist1: ";
    showlist(list1);
    cout<<"\nlist2: ";
    showlist(list2);

    list1.front();
    list1.back();
    list1.pop_front();
    showlist(list1);
    list1.reverse();
    showlist(list1);


    return 0;
}