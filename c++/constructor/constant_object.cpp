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

    void display() const
    {
        cout<<"x:"<<x<<endl;
        cout<<"y:"<<y<<endl;
    }
};

int main()
{
    base const b(1,2);
    b.display();
}
/*
1. constant object is initialize only by constructor i.e. constant object is initialized during its creation
2. we cant use function like enter() above to enter the values for the object
3. member function can only read the values of data member and not modify them
4.we need const functions to deal with const object
5. constant object behaves as read only object. data members are only read only members
*/
