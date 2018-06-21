#include<iostream>

using namespace std;

int max_sum(int arr[],int n)
{
    int excl=0;
    int incl=arr[0];
    int i;

    for(i=1;i<n;i++)
    {
        int excl_new= incl>excl?incl:excl;
        int incl_new=excl+arr[i];
        excl=excl_new;
        incl=incl_new;
    }
    return incl>excl?incl:excl;
}

int main()
{
    int arr[]={5,5,10,40,50,35};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"max sum: "<<max_sum(arr,n);
}
