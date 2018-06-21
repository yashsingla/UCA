#include<iostream>

using namespace std;

class  base
{
    int x;
public:

    base()
    {
    cout<<"base constructor"<<endl;
    }

    ~base()
    {
    cout<<"base destructor"<<endl;
    }

};

class  derived:public base
{
    int y;
public:

    derived()
    {
    cout<<"derived constructor"<<endl;
    }

    ~derived()
    {
    cout<<"derived destructor"<<endl;
    }

};

int main()
{
    base *p=new derived();

   delete p; //if i comment this line delete p..then only constructors will be called
}
