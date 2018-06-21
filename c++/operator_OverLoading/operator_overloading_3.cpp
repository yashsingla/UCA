#include<iostream>

using namespace std;

class fun
{
    int x;
public:

    fun(int y)
    {
        x=y;
    }
/*friend int operator <(fun ob1,fun ob2)
    {
        if(ob1.x<ob2.x)
            return 1;
        return 0;
    }*/
  int operator <(fun ob1)
    {
        if(x<ob1.x)
            return 1;
        return 0;
    }
};

int main()
{
fun ob1(1),ob2(2);
if(ob1<ob2)
    cout<<"ob1 is smaller than ob2";
else
    cout<<"ob2 is smaller than ob1";
}
