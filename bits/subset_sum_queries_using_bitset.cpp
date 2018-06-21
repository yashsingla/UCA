#include<iostream>
#include<bitset>
#define maxi 1000

using namespace std;

void fun1(int a[],int n,bitset<maxi>&bit)
{
    bit.reset();
    bit[0]=1;

  int i;
    for(i=0;i<n;i++)
    {
        bit=bit|(bit<<a[i]);
    }

}

void fun2(int query[],int nq,bitset<maxi>&bit)
{

int i;
    for(i=0;i<nq;i++)
    {
        if(query[i]>=maxi)
        {
            cout<<"NO";
            continue;
        }
        bit[query[i]]?cout<<"YES ":cout<<"NO";
    }

}

int main()
{
    int a[]={3,1,5};
    int query[]={8,7};

    int n=sizeof(a)/sizeof(a[0]);
    int nq=sizeof(query)/sizeof(query[0]);

   bitset<maxi>bit;

   fun1(a,n,bit);
   fun2(query,nq,bit);
}
