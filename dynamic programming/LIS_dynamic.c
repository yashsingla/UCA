#include<stdio.h>
#include<stdlib.h>

int fun(int a[],int n)
{
    int maxi=-1;

int dp[n],i,j;
for(i=0;i<n;i++)
    dp[i]=1;

     for(i=1;i<n;i++)
     {
         for(j=0;j<i;j++)
         {
             if(a[i]>a[j]&&(dp[i]<(dp[j]+1)))
                dp[i]=dp[j]+1;
         } //inner for
     }//outer for

     for(i=0;i<n;i++)
        if(maxi<dp[i])
        maxi=dp[i];
return maxi;
}//function ends

int main()
{
    int a[]={10,22,9,33,21,50,41,60,80};
    int n=sizeof(a)/sizeof(a[0]);
    int x=fun(a,n);
    printf("LIS:%d",x);
}
