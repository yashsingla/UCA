//overloading unary minus operator (-),++, -- , ! (only prefix increment and decrement)
// by returning object
#include<iostream>
using namespace std;
class complex
{
    int x;

public:
    complex()
    {}

    complex(int a)
    {  x=a; }

    complex operator !()
    {   complex temp;
        temp.x = !x;
        return temp;
    }

    complex operator --()
    {   complex temp;
        temp.x = --x;
        return temp;
    }

    complex operator ++()
    {   complex temp;
        temp.x = ++x;
        return temp;
    }

    complex operator -()
    {   complex temp;
        temp.x = -x;
        return temp;
    }

    void display()
    { cout<<"x:"<<x<<endl; }
};

int main()
{
complex c1(-6),c2;
cout<<"initial value:-6"<<endl;
cout<<"overloading ! operator:"<<endl;
c2= !c1;
c2.display();

cout<<endl<<"overloading -- prefix operator:"<<endl;
c2= --c1;
c2.display();

cout<<endl<<"overloading ++ prefix operator:"<<endl;

c2= ++c1;
c2.display();

cout<<endl<<"overloading - operator:"<<endl;

c2= -c1;
c2.display();

}
