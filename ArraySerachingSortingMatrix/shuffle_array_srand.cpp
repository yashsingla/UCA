#include<iostream>
#include<time.h>  // for time()
#include<stdlib.h> //for srand()

using namespace std;

void swapp(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}
void fun(int arr[],int n)
{
    int i;
    srand(time(NULL));

    for(i=0;i<n;i++)
    {
      int k=rand()%n;
        swapp(&arr[k],&arr[i]);
    }

    for(i=0;i<n;i++)
     cout<<arr[i]<<" ";

}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    fun(arr,n);
}
