//longest common substring.
/* The only difference between longest common substring and longest common subsequence in Dynamic programming is that while filling up the table, in
>>In LC substring we store zero at current index in table if current characters dont match in string but if they match we store 1+dp[i-1][j-1] and
keep track of maximum value.

>> In LC subsequence, if curraent characters in string dont match then in dp[i][j] we store max(dp[i-1][j] , dp[i][j-1] ) else we store 1+ dp[i-1][j-1]
*/
#include<iostream>
#include<limits.h>
using namespace std;

int maximum(int a,int b)
{
    return a>b?a:b;
}

void longest_common_substring(char s1[],int n1,char s2[],int n2)
{
  int dp[n1+1][n2+1];
  int i,j,maxi=INT_MIN;

   for(i=0;i<=n1;i++)
   {
      for(j=0;j<=n2;j++)
      {
          if(i==0||j==0)
            dp[i][j]=0;
          else
            if(s1[i-1]==s2[j-1])
          {
              dp[i][j]=1+dp[i-1][j-1];

              if(dp[i][j]>maxi)
                maxi=dp[i][j];
          }
          else
            dp[i][j]=0;
      }
   }
cout<<"maxi:"<<maxi;
}

int main()
{
    char s1[]="geeksforgeeks";
    int n1=sizeof(s1)/sizeof(s1[0]);
    char s2[]="geeksquiz";
    int n2=sizeof(s2)/sizeof(s2[0]);

   longest_common_substring(s1,n1,s2,n2);
}
