//can also be done in O(n2)
//time complexity: O(N)
#include<iostream>
#include<algorithm>
using namespace std;

int arr[]={700,80,100,150,120,500,90};
//int arr[]={100,180,260,310,40,535,695};

struct stock
{
    int buy;
    int sell;
};

void wrapper(int n)
{

int i=0;
int cnt=0;

struct stock s[n/2+1];

while(i<n-1)
{
    while( (arr[i+1]<=arr[i] )&& (i<n-1) )
        i++;

    if(i == n-1)
        break;

    s[cnt].buy=i++;

    while( (arr[i]>=arr[i-1] )&& (i<n) )
        i++;

     s[cnt].sell=i-1;
cnt++;
}

if(cnt==0)
cout<<"not possible";
else
{
    for(i=0;i<cnt;i++)
    {
        cout<<"buy on day:"<<s[i].buy<<"  ";
        cout<<"sell on day:"<<s[i].sell<<endl;
    }
}

}// wrapper function ends


int main()
{
    int n=sizeof(arr)/sizeof(arr[0]);

    wrapper(n);
}
