#include<iostream>
#include<map>

using namespace std;

void fun(int a[],int k,int n)
{
    map<int,int>h;

    int i;
    int c=0;
    for(i=0;i<k;i++)
    {
        if(h[a[i]]==0)
        {
            c=c+1;
        }
        h[a[i]]+=1;
    }

    cout<<c<<endl;

    for(i=k;i<n;i++)
    {
        if(h[a[i-k]]==1)
        {
            c=c-1;
        }
        h[a[i-k]]-=1;

      if(h[a[i]]==0)
      {
          c=c+1;
      }
   h[a[i]]+=1;

cout<<c<<endl;

    }
}


int main()
{
int arr[]={1,2,1,3,4,2,3};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);

    fun(arr,k,n);

}
