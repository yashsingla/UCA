//time complexity: O(x); x=max(m,n);
#include<iostream>
#include<tr1/unordered_map>

using namespace std::tr1;
using namespace std;

int fun(int set1[],int set2[],int m,int n)
{
    int c=0,x;
    unordered_map<int,int>mp;
    if(m>=n)
        x=m;
    else
        x=n;
    int i;

    for(i=0;i<x;i++)
    {
        if(i<m)
        {if(mp.find(set1[i])==mp.end())
         mp[set1[i]]++;
        else
            c++;
        }

       if(i<n)
        {if(mp.find(set2[i])==mp.end())
         mp[set2[i]]++;
        else
            c++;
        }
}
return c;
}

int main()
{
    //int set1[]={20,21,22};
    //int set2[]={22,23,24,25,20};
    int set1[]={6,7};
    int set2[]={12,13,14,15};
    int m=sizeof(set1)/sizeof(set1[0]);
    int n=sizeof(set2)/sizeof(set2[0]);

    cout<<"count:"<<fun(set1,set2,m,n);
}
