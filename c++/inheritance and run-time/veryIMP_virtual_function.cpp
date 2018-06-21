/*
The program below shows two thing:
1. compiler creates a secret pointer whenever there is a virtual function in class. class base has one int(4 bytes) data member
and one virtual function , by doing sizeof of base class object we get 8,but if we make function non-virtual then do sizeof
result will be 4. so this shows a secret pointer is created by compiler

2. vptr pointer..secret pointer created by compiler is inherited by all the derived class
do the sizeof of derived class object and the result is 8 and by making function in base class
non-virtual and then doing sizeof of derived class object gives  result 4;

*/
#include<iostream>
using namespace std;

class employee
{
public:
    int x;
    virtual void display()
    { cout<<"Employee"; }
};

class student
{
public:
     int y;
     void display()
    { cout<<"Student"; }
};


int main()
{
class employee e;
class student s;

cout<< "sizeof employee class object:" << sizeof(employee) <<endl;
cout<< "sizeof employee class object:" << sizeof(e) <<endl;
cout<< "sizeof student class object:" << sizeof(s) <<endl;
}
