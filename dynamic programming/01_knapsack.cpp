#include<iostream>

using namespace std;

int maxi(int a,int b)
{
    return a>b?a:b;
}

int knapsack_recursive(int W,int val[],int wt[],int n)
{
    if(n==0||W==0)
        return 0;

    if(wt[n-1]>W)
        return knapsack_recursive(W,val,wt,n-1);
    else
        return maxi(val[n-1] + knapsack_recursive(W-wt[n-1],val,wt,n-1),knapsack_recursive(W,val,wt,n-1));
}

int knapsack_dynamic(int W,int val[],int wt[],int n)
{
    int dp[n+1][W+1];

    int i,j;


   for(i=0;i<=n;i++)
   {
       for(j=0;j<=W;j++) // j actually acts as a total weight of the knapsack
       {
           if(i==0||j==0)
            dp[i][j]=0;
           else
            if(wt[i-1]<=j)
            dp[i][j]=maxi(val[i-1]+dp[i-1][j-wt[i-1] ],dp[i-1][j] );
            else
            dp[i][j]=dp[i-1][j];
       }
   }
return dp[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 40;
    int n = sizeof(val)/sizeof(val[0]);

    //cout<<"0-1 knapsack: "<<knapsack_recursive(W,val,wt,n);

    cout<<"0-1 knapsack: "<<knapsack_dynamic(W,val,wt,n);
}
