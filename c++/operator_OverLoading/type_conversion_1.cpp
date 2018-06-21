/*
1. converting primitive to class type is just like calling a constructor with single argument
2. converting class to primitive type is  through casting operator

*/
#include<iostream>
using namespace std;

class div
{
    int h,m;
public:

     div(){}
    div(int k)
    {
        h=k/60;
        m=k%60;    // conversion of primitive type to class type;
    }

    void enter()
    {
        cout<<"enter hours:";
        cin>>h;
        cout<<endl;
        cout<<"enter minutes:";
        cin>>m;
        cout<<endl;
    }

    void display()
    {
        cout<<"h:"<<h<<endl;
        cout<<"m:"<<m<<endl;
    }

    operator int()   // conversion of class type to primitive type
    {
        int temp=h*60+m;
        return temp;
    }

};

int main()
{
div ob1;
int x=500;
ob1=x; // div ob1(x);
cout<<"conversion of primitive type to class type:"<<endl;
ob1.display();
cout<<endl<<"conversion of class type to primitive type :"<<endl;

ob1.enter();
int minutes=int(ob1); // int minutes=ob1;
cout<<"minutes:"<<minutes;
}
