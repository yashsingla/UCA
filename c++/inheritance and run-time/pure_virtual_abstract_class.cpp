#include<iostream>
using namespace std;

class base
{
public:
    void print()
    {
        cout<<"print base"<<endl;
    }
    virtual void display()=0;
};

class derived: public base
{
public:

    void print()
    {
        cout<<"print derived"<<endl;
    }

   void display()
    {
        cout<<"pure virtual display"<<endl;
    }
};

int main()
{
    class base *b;
    class derived d;
  b=&d;
  b->display();
  b->print();
  //((derived*)b)->print();
}
