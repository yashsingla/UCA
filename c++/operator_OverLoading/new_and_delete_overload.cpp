#include<iostream>
#include<stdlib.h>

using namespace std;

class student
{
    string name;
    int age;

public:

    student()
    {cout<<"constructor called";}

    student(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    /*
    void enter()
    {
        cin>>name;
        cin>>age;
    }*/

    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
    }


    void *operator new(size_t size)
    {
        cout<<"overloading new operator with size:"<<size<<endl;
        void *p=malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        cout<<"overloading delete operator"<<endl;
          free(p);
    }
};

int main()
{
student *p= new student("anil",24);
//p->enter();
p->display();
delete p;
}
/*
In the above new overloaded function ,we can also allocate dynamic memory through new operator,but it should be global new
operator otherwise it will go in recursion
void *p= new student()..this will go in recursion
void *p= ::new student(); this is correct

>>void* operator new (size_t n)
{
//allocate memory and return the address (a void pointer)
}

size_t is a numerical data type defined by the system to specify memory size in bytes. For instance if you
use ‘new’ to create a character, the value of n (i.e. the argument passed to ‘n’) will be 1. If you pass a
‘double’ quantity then the value of ‘n’ will be 8.

*/
