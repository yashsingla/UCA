//Time complexities of enqueue() and dequeue() is O(1).

#include<iostream>
#include<string.h>
using namespace std;
class kqueue
{
    int *arr;
    int *next;
    int *f;
    int *r;
    int n,k,free;

public:
    kqueue(int num,int s);
    void enqueue(int qn,int key);
    void dequeue(int qn);
};

kqueue::kqueue(int num,int s)
{
    n=num;
    k=s;
       arr=new int[n];
       next=new int[n];
       f=new int[k];
       r=new int[k];

       free=0;

       memset(f,-1,k);

       int i;
       for(i=0;i<n-1;i++)
         next[i]=i+1;
       next[n-1]=-1;
}

void kqueue::enqueue(int qn,int key)
{
    if(free==-1)
    {
        cout<<"queue is full";
        return;
    }
    int i=free;
    free=next[i];

   if(f[qn]==-1)
    f[qn]=i;
   else
    next[r[qn]]=i;

   next[i]=-1;
   r[qn]=i;

   arr[i]=key;
}

void kqueue::dequeue(int qn)
{


   if(f[qn]==-1)
    {
        cout<<"queue is empty";
        return;
    }

   int item=arr[f[qn]];
   int i=f[qn];
   f[qn]=next[i];
   next[i]=free;
   free=i;
cout<<"element popped:"<<item;
}

int main()
{
    int p=3,n=10;
    kqueue k(n,p);

    k.enqueue(15, 2);
    k.enqueue(45, 2);

    // Let us put some items in queue number 1
    k.enqueue(17, 1);
    k.enqueue(49, 1);
    k.enqueue(39, 1);

    // Let us put some items in queue number 0
    k.enqueue(11, 0);
    k.enqueue(9, 0);
    k.enqueue(7, 0);

    k.dequeue(2);
    k.dequeue(1);
    k.dequeue(0);
}
