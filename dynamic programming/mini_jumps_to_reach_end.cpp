//perfect code..my solution ..time complexity is exponential..not efficient
#include<iostream>
#include<limits.h>
using namespace std;

int fun(int arr[],int n,int index,int step,int *mini)
{
    if(arr[index]==0)
        return INT_MAX;

    if(index==n-1)
        return step;

    int i;

    for(i=1;i<=arr[index]&&i+index<n;i++)
    {
        int val= fun(arr,n,i+index,step+1,mini);
        if(val<(*mini))
            (*mini)=val;
    }
    return (*mini);
}

int main()
{
    int arr[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int step=0;
   int mini=INT_MAX;
   cout<<"minimum no. of steps: "<<fun(arr,n,0,step,&mini);
}
