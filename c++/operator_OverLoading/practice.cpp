#include<iostream>
using namespace std;

class posh;

class item
{
    int m,n;
public:

   item(){}
    item(int x,int y)
    {
        m=x;
        n=y;
    }

   /* operator posh()
    {
        posh p(m,n);
        return p;
    }*/

    void enter()
    {
        cout<<"m:";
        cin>>m;
        cout<<endl;
        cout<<"n:";
        cin>>n;
        cout<<endl;
    }

    int v1()
    {return m;
    }

    int v2()
    {return n;
    }

    void display()
    {
        cout<<"m:"<<m<<endl;
        cout<<"n:"<<n<<endl;
    }

};

class posh
{
    int a,b;
public:

    posh(){}
    posh(int x,int y)
    {
        a=x;
        b=y;
    }

    posh(item i)
    {
        a=i.v1();
        b=i.v2();
    }

    void enter()
    {
        cout<<"a:";
        cin>>a;
        cout<<endl;
        cout<<"b:";
        cin>>b;
        cout<<endl;
    }

    void display()
    {
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
    }

};

int main()
{
    item i1;
    i1.enter();
    posh p1;
    p1=i1;
    p1.display();
}
