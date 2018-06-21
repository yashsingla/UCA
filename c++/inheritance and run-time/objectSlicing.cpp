//when we assign the object of derived class to the object of the base class it is called object slicing. If base class has less
//data members then derived class then extra members of derived class is chopped of
#include<iostream>

using namespace std;

class  base
{
    int x;
public:

     base(int a)
    {
        x=a;
    }

    void print()
    {
        cout<<"x:"<<x<<endl<<endl;
    }
};

class  derived:public base
{
    int a;
    int b;

public:

     derived(int x,int y,int z):base(z)
    {
        a=x;
        b=y;
    }
    void print()
    {
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl<<endl;
    }
};

int main()
{
    class base b(5);
    b.print();

   class derived d(1,2,3);
   d.print();

   b=d;
   b.print();
}
