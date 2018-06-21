/* given array in form a1a2a3a4a5..an b1b2b3b4..bn of size 2n
rearrange it in form a1b1a2b2a3b3a4b4a5b5..an bn
time complexity: O(n2)
*/
#include<iostream>

using namespace std;
void wrapper(int arr[],int n)
{
   int n1=n/2,i;
    int j=n1,k,temp;

   for(i=0;i<n;i=i+2)
   {
        temp=arr[j++];

     for(k=j-1;k>(i+1);k--)
        arr[k]=arr[k-1];

      arr[i+1]=temp;
   }

   for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={1,2,3,4,5,11,12,13,14,15};
    int n=sizeof(arr)/sizeof(arr[0]);
///cout<<n;
    wrapper(arr,n);
}
