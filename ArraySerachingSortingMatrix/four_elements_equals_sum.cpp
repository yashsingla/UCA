#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int first;
    int second;
    int sum;
};

int noCommon(struct node a,struct node b)
{
    if(a.first==b.first||a.first==b.second||a.second==b.first||a.second==b.second)
        return 0;
return 1;
}

int cmp(const void *p,const void *q)
{
    return (*(struct node*)p).sum - (*(struct node*)q).sum ;
}

void fun(int arr[],int n,int x)
{
    int s=(n*(n-1))/2;

    struct node temp[s];

    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp[k].first=i;
            temp[k].second=j;
            temp[k].sum=arr[i]+arr[j];
            k++;
        }
    }
qsort(temp,s,sizeof(temp[0]),cmp);
    i=0,j=k-1;

    while(i<s&&j>=0)
    {
       if((temp[i].sum+temp[j].sum==x)&&noCommon(temp[i],temp[j]) )
       {
           cout<<"( "<<temp[i].first<<", "<<temp[i].second<<", "<<temp[j].first<<", "<<temp[i].second<<" )";
           i++;
           k--;
       }
       else
        if(temp[i].sum+temp[j].sum>x)
           k--;
       else
        i++;
    }
}

int main()
{

int arr[]={10,20,30,40,1,2};
int n=sizeof(arr)/sizeof(arr[0]);
int sum=91;
fun(arr,n,sum);

}
