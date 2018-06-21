#include<iostream>
#include<limits.h>

using namespace std;

int subset_sum_recursive(int arr[],int n,int sum,int start)
{
    if(sum==0)
    return 1;

    int i;
    for(i=start;i<n;i++){
       if(arr[i]<=sum)
     if(subset_sum_recursive(arr ,n ,sum-arr[i] ,i+1))
        return 1;
   }
   return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int  sum = ;
    int n = sizeof(arr)/sizeof(arr[0]);

    if(subset_sum_recursive(arr,n,sum,0))
        cout<<"yes";
    else
        cout<<"no";
}

