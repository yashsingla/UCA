#include<iostream>
using namespace std;
class base
{
    int x,y;
    public:

      /* base()
        {
            x=1;   // default constructor with default argument
            y=2;
        }          //const-1
*/
     base(){cout<<"hello"<<endl;}   //default constructor with no default argument  const-2

/* we can have only one user defined default constructor either const-1 or const-2,if we define both const-1 and const-2
 compiler will give error */

        base(int a,int b)
        {
            x=a;              // this is parameterized constructor
            y=b;
        }                    //const-3

            base(int a)
        {
            x=a;               //parameterized constructor
        }                       //const-4

        void display()
        {
            cout<<"x:"<<x<<endl;
            cout<<"y:"<<y<<endl;
        }
};

int main()
{
    base b(11) ;//or base b=11
    b.display();

    cout<<endl;
    base b1(3,4);// or base b1=base(3,4)
    b1.display();

    cout<<endl<<"copy constructor called implicitly:"<<endl;
    base b2(b1); // see to it that till now no explicit copy constructor has been created by the user,so compiler creates
                 // its implicit copy constructor
    b2.display();

    cout<<endl<<"b3:";
    base b3;
}
/*
all of the above constructors are being overloaded..this is constructor overloading
*/
