
#include<iostream>
using namespace std;

class fun
{
    int x,y;
public:
    friend ostream & operator <<(ostream & out,fun &obj)
    {
        out<<"x:"<<obj.x<<endl<<"y:"<<obj.y;
        return out;
    }

    friend istream & operator >>(istream &  in,fun &obj)
    {
        in>>obj.x>>obj.y;
        return in;
    }
};

int main()
{
fun obj;
cin>>obj;
cout<<obj;
}

