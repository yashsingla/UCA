#include<iostream>

using namespace std;

class base
{
    int n;
    int *a;

    public:

    base(int p)
    {
      n=p;
      a=new int[n];
      int i;

      for(i=0;i<n;i++)
        a[i]=i;

    cout<<"constructor called"<<endl;
    }

    ~base()
    {
        delete []a;
        cout<<"destructor called"<<endl;
    }

    void display()
    {
        cout<<"n:"<<n<<endl;
          int i;
      for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    }
};

int main()
{
    base b(5);
    b.display();
}

/*
constructor above is dynamic constructor and proper use of destructor is shown above when memory is allocated dynamically
*/
