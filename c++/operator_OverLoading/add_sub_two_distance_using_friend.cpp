//friend function is used to call private data members of class through object of the class
#include<iostream>

using namespace std;

class distance
{
    int km,m;
public:
    distance()
    {
        km=10;
        m=900;
    }

    friend distance &  operator +(distance&,distance&);

    void display()
    {
        cout<<"km:"<<km;
        cout<<"m:"<<m;
    }
};

distance & operator+(distance &ob1,distance &ob2)
{
    class distance d;
    d.km=ob1.km + ob2.km
    d.m= ob1.m+ob2.m;

    if(d.m>=1000){
        d.km+=d.m/1000;
    d.m=d.m%1000;
    }
return d;
}

int main()
{
class distance obj1;
class distance obj2, obj3;
obj3=obj1+obj2;
obj3.display();
}
