//diamond problem or ambiguity in multi-path inheritence
#include<iostream>
using namespace std;

class base
{
public:
    void print()
    {
        cout<<"print";
    }
};

class parent1:virtual public base
{
public:
    void display1()
    {
        cout<<"display1";
    }
};

class parent2:virtual public base
{
public:
    void display2()
    {
        cout<<"display2";
    }
};

class child:public parent1,public parent2
{
public:
    void display3()
    {
        cout<<"child";
    }
};

int main()
{
    class child obj;
    obj.print(); // try executing,by removing virtual keyword from parent1 and parent 2...ambiguity will be shown
}
