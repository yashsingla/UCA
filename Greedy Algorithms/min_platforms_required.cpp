#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

// my solution;
void fun(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    //sort(dep,dep+n);

    int time=dep[0];
    int cnt=1,p=0;
    int maxi=INT_MIN;
    int i;

    for(i=1;i<n;i++)
    {
        if(arr[i]<time)
            cnt++;

        if(time<dep[i])
        {
            if(cnt>maxi)
              maxi=cnt;

            cnt=cnt-p;
            p=0;
            time=dep[i];
        }
        else
            p++;
    }
cout<<"Minimum number of platforms:"<<maxi;
}

//time complexity: O(NlogN)
void fun1(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int cnt=0;
    int maxi=INT_MIN;
    int i=0,j=0;

    while(i<n && j<n)
    {
        if(arr[i]<dep[j])
        {
            cnt++;
            i++;
            if(cnt>maxi)
                maxi=cnt;
        }
        else
        {
            cnt--;
            j++;
        }
    }

cout<<"Minimum number of platforms:"<<maxi;
}// fun1 function ends

int main()
{
    int arr[]={900,940,950,1100,1500,1800};
    int dep[]={910,1200,1120,1130,1900,2000};
    int n=sizeof(arr)/sizeof(arr[0]);
    fun(arr,dep,n);
}
