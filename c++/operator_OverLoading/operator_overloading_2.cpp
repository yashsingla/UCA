//overloading ++, -- (only postfix increment and decrement) by returning object
// to indicate the compiler about postfix operator,we write, complex operator ++(int),int is just a dummy argument to
//give a signal to the compiler to create post-fix notation of the operator
// when compiler sees ++obj,it generates a call to 'operator++()' ,but when it sees obj++, it generats a call to
// 'operator ++(int)'

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

    complex operator --(int)
    {   complex temp;
        temp.x = x--;
        return temp;
    }

    complex operator ++(int)
    {   complex temp;
        temp.x = x++;
        return temp;
    }

    void display()
    { cout<<"x:"<<x<<endl; }
};

int main()
{
complex c1(1),c2,c3;
cout<<"initial value:1"<<endl;

cout<<endl<<"overloading postfix -- operator:"<<endl;
c2= c1--;
c2.display();


cout<<endl<<"overloading postfix ++ operator:"<<endl;
c2= c1++;
c2.display();
}
