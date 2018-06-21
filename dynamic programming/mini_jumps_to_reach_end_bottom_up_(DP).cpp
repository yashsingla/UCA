#include<iostream>
#include<limits.h>
using namespace std;

int mini_steps(int arr[],int n)
{

    int jumps[n];
    jumps[n-1]=0;
    int i,j;

    for(i=n-2;i>=0;i--)
    {
        if(arr[i]==0)
            jumps[i]=INT_MAX;
        else
            if(n-1<=arr[i]+i)
            jumps[i]=1;
        else
        {
            int mini=INT_MAX;
            int j;
            for(j=i+2;j<n&&j<=arr[i]+i;j++)
            {
                if(mini>jumps[j])
                    mini=jumps[j];
            }
            if(mini!=INT_MAX)
            jumps[i]=mini;
            else
            jumps[i]=INT_MAX;
        }
    }
    return jumps[0];
}


int main()
{
    //int arr[]={1,3,6,1,0,9}; // case-1;
    int arr[]={1,0,6,1,0,9};// case-2
    int n=sizeof(arr)/sizeof(arr[0]);
     int x=mini_steps(arr,n);
     if(x!=INT_MAX)
    cout<<"mini number of steps to reach end: "<<x;
    else
        cout<<"cannot reach end of array";
}

