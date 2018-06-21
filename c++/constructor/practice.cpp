#include<iostream>
using namespace std;

class dog
{
    public:

   dog() {cout<< "dog born" <<endl;
          bark() ;
         }
    ~dog(){ bark() ;}

 virtual void bark() { cout<< "I am just a dog" <<endl; }

    void seeCat() { bark(); }
};

class Yellowdog : public dog
{
    public:
   Yellowdog() {cout<< "yellow dog born" <<endl; }
   void bark() { cout<< "I am a yellow dog" <<endl; }
};

int main()
{

    Yellowdog d;
    //d.seeCat();
}
/*
Explanation: The binding of methods called from within other methods is basically just like other bindings. bark() method
called from within of seeCat method is binded at runtime whereas breed method called from within of findBreed method is binded
at compile time. Both function calls bark() and breed() works in same way as they would have worked if they were called
directly, instead from within of methods.Also, It makes no difference whether the seeCat and findBreed methods itself are
declared virtual in deciding how to bind calls to other methods made within seeCat and findBreed methods.
*/
