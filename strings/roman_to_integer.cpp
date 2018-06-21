#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

int mini(int a,int b)
{
    return a<b?a:b;
}

void min_insertion_dp(char s[],int n)
{
  int dp[n][n];
  memset(dp,0,sizeof(dp) );
  int gap,i,j;

   for(gap=1 ;gap<n; gap++)
   {
      for(i=0,j=gap;j<n;i++,j++)
      {
          if(s[i]==s[j])
            dp[i][j]=dp[i+1][j-1];
          else
            dp[i][j]=1+mini( dp[i+1][j],dp[i][j-1] );
      }
   }
cout<<"No. of insertions required are:"<<dp[0][n-1];
}

int min_insertion_recursive(char s[],int l,int r)
{
    if(l>r)
    return INT_MAX;

    if(l==r)
    return 0;

    if(l+1==r)
    {
        if(s[l]==s[r])
            return 0;
        return 1;
    }

    if(s[l]==s[r])
        return min_insertion_recursive(s,l+1,r-1);
    else
        return mini( min_insertion_recursive(s,l+1,r) ,
                    min_insertion_recursive(s,l,r-1)
                )+1;

}

int main()
{
    char s1[]="geeks";
    int n=sizeof(s1)/sizeof(s1[0]);

   //min_insertion_dp(s1,n1);
   cout<<"minimum insertion: "<<min_insertion_recursive(s1,0,n-1);
}


