#include<iostream>

using namespace std;

class  base
{

public:
   virtual void print()
    {
        cout<<"print base class"<<endl;
    }

    void show()
    {
        cout<<"show base class"<<endl;
    }

};

class  derived:public base
{
public:

    void print()
    {
        cout<<"print derived class"<<endl;
    }

     void show()
    {
        cout<<"show derived class"<<endl;
    }
};

int main()
{
    base b,*bptr;
    derived d;
    bptr=&d;
    bptr->print();
    bptr->show();

    /*
    base class pointer  contains the address of derived class pointer,so now if  i call print() function using bptr it will print
   "base class" ..since functions have same name in print as well as derived class but inorder to call function of derived class
   we can make function in base class as virtual.

   On using Virtual keyword with Base class's function, Late Binding(run time polymorphism) takes place and the derived
   version of function will be called, because base class pointer points to Derived class object.

   IMP: virtual function provides a means by which the function of base class can be overridden by functions of derived class
    */
}
