#include<iostream>
#include<math.h>
using namespace std;

void wrapper(int arr[],int n)
{
    int x=pow(2,n);
    int counter,j;

    for(counter=1 ;counter < x; counter++)
    {
        for(j=0;j<n;j++)
        {
            if(counter&(1<<j))
                cout<<arr[j];
        }
        cout<<endl;
    }
}

int main()
{
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    wrapper(arr,n);
}
