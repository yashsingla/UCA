//count only substrings
//time complexity:O(n^2)
//space complexity:O(n^2);
#include<iostream>
#include<string>
#include<cstring>

using namespace std;


int check(string str)
{
    int n=str.size();
    int i,j;
    int dp[n][n];
    bool p[n][n];

   memset(dp,0,sizeof(dp));
   memset(p,false,sizeof(p));

   for(i=0;i<=n-1;i++)
         p[i][i]=true;

   for(i=0;i<=n-1;i++){

         if(str[i]==str[i+1])
         {
             p[i][i+1]=true;
             dp[i][i+1]=1;
         }

   }

    for(i=2;i<=n;i++)
    {
        for(j=0;j<=(n-i);j++)
        {
            int e=j+i;// end point of string
            if(str[j]==str[e]&&p[j+1][e-1])
                p[j][e]=true;

            if(p[j][e])
              dp[j][e]=dp[j+1][e]+dp[j][e-1]+1-dp[j+1][e-1];
            else
               dp[j][e]=dp[j+1][e]+dp[j][e-1]-dp[j+1][e-1];
        }
    }
   return dp[0][n-1];
}

int main()
{
    string str="abba";

    cout<<"count:"<<check(str);
}
