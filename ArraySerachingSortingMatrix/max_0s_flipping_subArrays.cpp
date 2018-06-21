#include<iostream>
using namespace std;

int fun(int arr[],int n)
{
    int i,count_zero=0;

    for(i=0;i<n;i++)
      if(arr[i]==0)
      count_zero++;

    int p,j,max_zero;
   i=0;
    while(i<n)
    {
        if(arr[i]==1)
        {
            j=i;
            p=0;
            while(j<n&&arr[j]==1)
            {  cout<<"hello"<<endl;
                p++;
                j++;
            }
            if(count_zero+p>count_zero)
                max_zero=p;

                i=j+1;
        }
        else
            i++;
    }
    return count_zero+max_zero;
}

int main()
{
    int arr[]={0,1,0,0,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Max number of 0s:"<<fun(arr,n);
}
