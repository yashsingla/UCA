// find function:Searches the container for an element with k as key and returns an iterator to it if found, otherwise
//it returns an iterator to unordered_map::end (the element past the end of the container).

#include<iostream>
#include<algorithm>
#include<tr1/unordered_map>
using namespace std::tr1;
using namespace std;

int maxi(int a,int b)
{
    int x=a>=b?a:b;
return x;
}

int mini(int a,int b)
{
    int x=a<=b?a:b;
return x;
}

/*
//time complexity:O(N^2)
int max_diff(int a[],int n)
{
    unordered_map<int,int>f;
    int i,j,ans=0;

    for(i=0;i<n;i++)
        f[a[i]]++;

   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if((f[a[j]]>f[a[i]])&&(a[j]>a[i]))
            ans=maxi(ans,f[a[j]]-f[a[i]]);
           else

           if((f[a[i]]>f[a[j]])&&(a[i]>a[j]))
            ans=maxi(ans,f[a[i]]-f[a[j]]);
      }
   }
return ans;
}
*/
//time complexity:O(logN)
int max_diff(int a[],int n)
{
    unordered_map<int,int>f;
    int i,j=0,ans=0;
int dist[n];

    for(i=0;i<n;i++)
        {
            if(f.find(a[i])==f.end())
                dist[j++]=a[i];

            f[a[i]]++;
        }

   sort(dist,dist+j);

   int k=n+1;

   for(i=0;i<j;i++)
   {
       int x=dist[i];
        ans=maxi(ans,x-k);
       k=mini(x,k);

   }

return ans;
}

int main()
{
    int a[]={3,1,3,2,3,2};
    int n=sizeof(a)/sizeof(a[0]);

    int result=max_diff(a,n);
    cout<<"Max Difference:"<<result;
}

#include <iostream>
#include<unordered_map>

using namespace std;

int main() {

	int t,n,i;
	unordered_map<int,int>m;
	cin>>t;

	while(t--)
	{
	    cin>>n;

	    for(i=0;i<n;i++)
	     {
	         cin>>k;
	         cout<<" "
	         m[k]++;
	     }

	    for(i=0;i<n;i++)
	     {
	         if(m.find(i)==f.end())
	           cout<<i;
	     }


	}
}
