#include<iostream>
using namespace std;
class base
{
    int x,y;

    public:

    base(int a,int b)
    {
        x=a;
        y=b;
    }

    base(base &b)
    {
        x=b.x;
        y=b.y;
    }

    void display()
    {
        cout<<"x:"<<x<<endl;
        cout<<"y:"<<y<<endl;
    }
};

int main()
{
    base b(1,2);
    base b1(b);
    b1.display();
}
/*
In copy constructor,object is passed by reference not by value because if we pass by value like base(base b) then
copy constructor will call itself to copy actual parameters to formal parameters and then that parameters will call copy
constructors to again make a copy of formal parameters so making an endless chain but by passing is by refrence ,the recieving
variable becomes alias(duplicate) of supplied object.hence no need to call copy constructor to copy actual arguments to formal
arguments,if we pass by value compiler shows error
*/
