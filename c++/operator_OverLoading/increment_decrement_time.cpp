//increment and decrement time in seconds
// if we have friend function then we need to have pass by refrence in order to get changes reflected
#include<iostream>
using namespace std;

class time
{
    int h,m,s;
public:
    time(int x,int y,int z)
    {
        h=x;
        m=y;
        s=z;
    }

   friend time operator ++(time &t)
    {
        ++t.s;

        if(t.s>=60)
        {
            t.m=t.m+(t.s/60);
            t.s=t.s%60;
        }

        if(t.m>=60)
        {
            t.h=t.h+(t.m/60);
            t.m=t.m%60;
        }
    }

 friend   time operator --(time &t)
    {
        --t.s;

        if(t.s<0)
        {
            t.s=t.s+60;
            t.m=t.m-1;
        }

        if(t.m<0)
        {
            t.m=t.m+60;
            t.h=t.h-1;
        }
    }

    void display(){
    cout<<"h:"<<h<<endl;
    cout<<"m:"<<m<<endl;
    cout<<"s:"<<s<<endl;
    }
};

int main()
{
time t(11,59,59);
++t;
t.display();
}
