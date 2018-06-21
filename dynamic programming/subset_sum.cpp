// arr is set of non-negative numbers
#include<iostream>
#include<limits.h>

using namespace std;

int subset_sum_recursive(int arr[],int n,int sum)
{
    if(sum==0)
    return 1;

    if(n==0&&sum!=0)
        return 0;

   if(arr[n-1]>sum)
    return subset_sum_recursive(arr,n-1,sum);
else

    return subset_sum_recursive(arr,n-1,sum-arr[n-1])|| subset_sum_recursive(arr,n-1,sum) ;
}

int subset_sum_dynamic(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    int i,j;

    for(i=0;i<=n;i++)
     dp[i][0]=1;

   for(i=1;i<=sum;i++)
     dp[0][i]=0;

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=sum;j++)
       {
           if(j<arr[i-1])
            dp[i][j]=dp[i-1][j];
           else
            dp[i][j] = (dp[i-1][j]) || (dp[i-1][j-arr[i-1] ]);
       }
   }
   return dp[n][sum];
}


int main()
{
    int arr[] = {3,34,4,12,5,2};
    int  sum = 18;
    int n = sizeof(arr)/sizeof(arr[0]);

    /*if(subset_sum_recursive(arr,n,sum))
        cout<<"yes";
    else
        cout<<"no";
*/
    if(subset_sum_dynamic(arr,n,sum))
        cout<<"yes";
    else
        cout<<"no";
}
