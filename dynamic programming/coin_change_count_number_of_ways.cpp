#include<iostream>
#include<stdlib.h>
using namespace std;

int fun(int v[],int m,int n)
{
    int **dp=(int **)malloc(n*sizeof(int *));
    int i,j;

    for(i=0;i<n;i++)
    dp[i]=(int *)malloc((m+1)*sizeof(int));

    for(i=0;i<n;i++)
        dp[i][0]=1;

   for(i=0;i<n;i++)
   {
       for(j=1;j<=m;j++)
       {
           int x = j>=v[i]?dp[i][j-v[i]]:0;
           int y=  i>=1?dp[i-1][j]:0;

           dp[i][j]=x+y;
       }
   }

   return dp[n][m];

}

int main()
{
    int v[]={4,1,2,3};
    int m=7;
    int n=sizeof(v)/sizeof(v[0]);
     cout<<"Number of ways: "<<fun(v,m,n);
}
