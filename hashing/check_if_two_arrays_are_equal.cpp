//time complexity:O(N)..
//space complexity:O(N).. see the usage of map
#include<iostream>
#include<tr1/unordered_map> //not supported in codeblocks but see the usage of map

using namespace std::tr1;
using namespace std;
bool fun(int a[],int b[],int x,int y)
{
    if(x!=y)
    return false;

    unordered_map<int,int>m;
    int i;

    for(i=0;i<x;i++)
        m[a[i]]++;

    for(i=0;i<y;i++)
    {
        if(m.find(b[i])==m.end())
            return false;

        if(m[b[i]]==0)
            return false;

        m[b[i]]--;
    }
    return true;
}
int main()
{
    int a[]={1,2,5,4,0,2,1};
    int b[]={2,4,5,0,1,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);

    if(fun(a,b,n,m))
        cout<<"Equal";
    else
        cout<<"Not Equal";
}
