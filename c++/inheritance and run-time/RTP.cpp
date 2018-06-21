//diamond problem or ambiguity in multi-path inheritence
#include<iostream>
using namespace std;

class base1
{
public:
    virtual void display()
    {
        cout<<"display1"<<endl;
    }
};

class base2: public base1
{
public:
    void display()
    {
        cout<<"display2"<<endl;
    }
};

class base3: public base2
{
public:
    void display()
    {
        cout<<"display3"<<endl;
    }
};

// what we are doing with display function is function overriding

int main()
{
    class base1 b1,*bptr;
    class base2 b2;
    class base3 b3;

    bptr=&b2;
    bptr->display(); // this is run time polymorphism as we are selecting the function to be called at run time
                      // depending upon the address of type of object ,base class pointer is having
     bptr=&b3;
     bptr->display();

                      // we use virtual function to achieve  run time polymorphism
}
