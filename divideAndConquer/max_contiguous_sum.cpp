//max contiguous sum using divide and conquer
/*
T(1)=1
T(n)=2T(n/2)+O(n)
complexity is nlogn
*/
#include<iostream>
#include<limits.h>

using namespace std;

int maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int wrapper(int arr[],int l,int r)
{
    int Leftborder=INT_MIN,Rightborder=INT_MIN,maxLeftborder=INT_MIN,maxRightborder=INT_MIN;

    int mid=l+(r-l)/2;

    if(l==r)
        return arr[l];

    int maxLeft=wrapper(arr,l,mid);
    int maxRight=wrapper(arr,mid+1,r);

int i;

     for(i=mid;i>=l;i--)
     {
         Leftborder+=arr[i];
         if(Leftborder>maxLeftborder)
            maxLeftborder=Leftborder;
     }

     for(i=mid+1;i<=r;i++)
     {
         Rightborder+=arr[i];
         if(Rightborder>maxRightborder)
            maxRightborder=Rightborder;
     }

    return maxi(maxi(maxLeft,maxRight),maxLeftborder+maxRightborder);
}

int main()
{
   // int arr[]={-2,11,-4,13,-5,2};
    int arr[]={-1,-2,-3,-4,-5,-6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"max contiguous sum:"<<wrapper(arr,0,n-1);
}
