#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int maxi(int a,int b)
{
    return a>b?a:b;
}

int longest_pallindrome_subsequence(char arr[],int l,int r) //recursive approach
{
    if(l==r)
        return 1;

    if(l+1==r)
  if(arr[l]==arr[r])
     return 2;


    if(arr[l]==arr[r])
        return 2+longest_pallindrome_subsequence(arr,l+1,r-1);
    else
        return maxi( longest_pallindrome_subsequence(arr,l+1,r),
                     longest_pallindrome_subsequence(arr,l,r-1)
                    );
}

int longest_pallindrome_dp(char arr[],int n) //recursive approach
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));

    int i;
    for(i=0;i<n;i++)
        dp[i][i]=1;

int j,k;

    for(j=1;j<=n;j++)
    {
        for(k=0;k<(n-j);k++)
        {
            int i=j;
            int len=j-k+1;

                 if(arr[k]==arr[j]&&len==2)
                    dp[k][j]=2;
            else
            if(arr[k]==arr[j])
                dp[k][j]=2+dp[k+1][j-1];
            else
                dp[k][j]=maxi(dp[k][j-1],dp[k+1][j]);
        }
    }
return dp[0][n-1];
}


int wrapper(char arr[],int n)
{
//return longest_pallindrome_subsequence(arr,0,n-1);
return longest_pallindrome_dp(arr,n);
}

int main()
{
    char arr[]="AGBDBA";
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"longest pallindromic subsequence: "<<wrapper(arr,n);
}
