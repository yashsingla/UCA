#include<iostream>

using namespace std;

class  base
{
    int x;
    int y;
public:

     base()
    {
        x=1;
        y=2;
    }
    void print()
    {
        cout<<"x:"<<x<<endl<<"y:"<<y<<endl;
    }
};

class  derived:public base
{
    int a;
    int b;

public:
     derived()
    {
        a=3;
        b=4;
    }

    void display()
    {
        cout<<"hello";
    }

    void print()
    {
        cout<<"a:"<<a<<endl<<"b:"<<b<<endl;
    }
};

int main()
{
    class base b,*bptr;
    class derived d,*dptr;

    bptr=&d; //upcasting in java,  //base class pointer can either point to pointer of base or to the pointer of derived class
             // if i write   dptr=&b .. it is illegal
    dptr=&d;
    bptr->print(); // if base and derived class contains the memeber with same name and base pointer contains the address of
                   // derived class then the memeber of base class will be printed (x=1,y=2)
    cout<<endl;
    dptr->print();// print funtion of derived class will be called
    // if i try accessing the unique members (i.e. the members not inherited from base class) of derived class
    //throuh pointer of base class having derived class address then..it is illegal like bptr->display() is illegal

    // to access all the members of the derived class, you must use a pointer to the derived class

   // now since base class pointer contains the address of derived class pointer, to call the member with same name of derived
   // class what we can do is
   cout<<endl;
   ((derived*)bptr)->print(); //downcasting in java
}
