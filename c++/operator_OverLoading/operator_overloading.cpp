//overloading + operator
#include<iostream>
using namespace std;
class complex
{
    int a;
    int b;
public:
    complex()
    {

    }
    complex(int x,int y)
    {
        a=x;
        b=y;
    }
    complex operator +=(complex c)
    {
        complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
    void display()
    {
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
    }
};

int main()
{
complex c1(1,2),c2(3,4),c3;
c1+=c2;
c1.display();
}
