
#include<iostream>
using namespace std;

class base
{
    public:

    int x;

     virtual void display()
    {
        cout<<"display1";
    }
};

class child: public base
{
public:
     void display()
    {
        cout<<"display child";
    }

};


int main()
{
    class base b;
    class child c;
cout<<sizeof(c);
}
