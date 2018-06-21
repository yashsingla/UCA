#include<iostream>
#include<tr1/unordered_set>

using namespace std;
using namespace std::tr1;

bool fun(int a1[],int a2[],int a3[],int n1,int n2,int n3,int sum)
{
    unordered_set<int>s;

    int i,j;

    for(i=0;i<n1;i++)
     s.insert(a1[i]);

   for(i=0;i<n2;i++)
   {
       for(j=0;j<n3;j++)
       {
           if(s.find(sum-a2[i]-a3[j])!=s.end())
            return true;

       }
   }
   return false;
}

int main()
{
    int a1[]={1,2,3,4,5};
    int a2[]={2,3,6,1,2};
    int a3[]={3,2,4,5,6};

    int n1=sizeof(a1)/sizeof(a1[0]);
    int n2=sizeof(a2)/sizeof(a2[0]);
    int n3=sizeof(a3)/sizeof(a3[0]);
    int sum=9;

    if(fun(a1,a2,a3,n1,n2,n3,sum))
        cout<<"Yes";
    else
        cout<<"No";
}
