//time complexity:O(N)
//space compelxity:O(1)
#include<iostream>
#include<algorithm>

using namespace std;

void fun(int a[],int n)
{
    int i,j,l,r=n-1;
   sort(a,a+n);

    for(i=0;i<=n-2;i++)
    {
        l=i;
        j=i+1;
        int x=-(a[l]+a[r]);
        while(l<r&&j<=n-2)
        {
            if(x==a[j])
                cout<<"result:"<<a[l]<<" "<<a[j]<<" "<<a[r]<<endl;
           j++;
        }
    }
}

int main()
{
    int a[]={-1,0,1,2,-3,1};
    int n=sizeof(a)/sizeof(a[0]);
    fun(a,n);
}
