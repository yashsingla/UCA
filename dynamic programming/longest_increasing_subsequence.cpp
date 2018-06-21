#include<iostream>
using namespace std;

int fun(int a[],int n,int *maxi)
{
    if(n==1)
        return 1;

    int max_ref=1;
    int i;

    for(i=1;i<n;i++)
    {
        int x=fun(a,i,maxi);

        if(a[i-1]<a[n-1] && x+1>max_ref)
            max_ref=x+1;

    }

    if(max_ref>(*maxi))
        *maxi=max_ref;

    return max_ref;

}


int main()
{
    int arr[]={3,4,-1,0,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxi=1;

    cout<<"longest increasing subsequence: "<<fun(arr,n,&maxi);
}
