#include<iostream>
using namespace std;

class one;
class two
{
    int a[5];
    int sum;
public:
    two()
    {
        int i;
        for(i=0;i<5;i++)
            a[i]=i;
    }
    friend two operator +(one,two);
     void show()
    {
        int i;
        for(i=0;i<5;i++)
            cout<<a[i]<<" ";
            cout<<endl;
    }
    void display()
    {
        cout<<"sum:"<<sum;
    }
};

class one
{
    int b[5];
    int sum1;
public:
    one()
    {
        int i;
        for(i=0;i<5;i++)
            b[i]=i;
    }
    friend two operator +(one,two);

    void show()
    {
        int i;
        for(i=0;i<5;i++)
            cout<<b[i]<<" ";
            cout<<endl;
    }
    void display()
    {
        cout<<"sum1:"<<sum1;
    }
};

two operator+(one o,two t)
{
    two temp;
    int i;
    for(i=0;i<5;i++)
        temp.a[i]=o.b[i]+t.a[i];

    return temp;
}

int main()
{
one obj1;
two obj2,obj3;
obj1.show();
obj2.show();
obj3=obj1+obj2;
obj3.show();
}
