//given an infinite array,where first 'n' cells are filled with integers in sorted form and rest ar filled with '$' sign,
//value of n is not given,we need to find the index of given integer 'k',if it exist or not..in O(logN))

/*
we can easily find it in O(N) by traversiing array
*/

#include<iostream>

using namespace std;

void wrapper(int arr[],int n,int k)
{
    int l=1,r=1;

    while(arr[r]!='$')
    {
        l=r;
        r=r*2;
    }

    int mid;
    while(r-l>1)
    {
        mid=(l+r)/2;

        if(arr[mid]!='$')
             l=mid;
        else
            r=mid;
    }

    l=0,r=r-1;
    int p=0;

    while(r-l>=0)
    {
        mid=(l+r)/2;
        if( arr[mid]==k ){
            cout<<"element found";
           p=1;
           break;
        }
        else
            if(k<arr[mid])
               r=mid-1;
        else
          l=mid+1;
   }

  if(p==0)
    cout<<"element not found";
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,'$','$','$','$','$','$','$','$'};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=7;

    wrapper(arr,n,k);
}
