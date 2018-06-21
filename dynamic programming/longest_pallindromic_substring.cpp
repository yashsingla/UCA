// time and space complexity: O(n^3)
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void longest_pallindrome_substring(string s,int n)
{
    bool dp[n+1][n+1];
    memset(dp,false,sizeof(dp) );

   int i;
   for(i=0;i<n;i++)
   dp[i][i]=true;

   int max_len;
string max_string="";


   for(i=0;i<n;i++){
  if(s[i]==s[i+1]){

  dp[i][i+1] = true;
   max_len = 2;
   max_string=s.substr(i,2);
   }
}

   int j,len;

   for(i=2;i<=n;i++)
   { //---3
       for(j=0;j<n-i;j++)
       {//---2
           int len=i-j+1;
           int k=i;
          if(s[j]==s[k]&&dp[j+1][k-1])
          { //--1
              dp[j][k]=true;
              if(len>max_len)
              {
                  max_len=len;
                  max_string=s.substr(j,len);

              }
          }//--1
       }//--2
   }//--3
   cout<<"maximum length: "<<max_len<<endl;
   cout<<"maximum length string: "<<max_string;
}// function ends

int main()
{
    string s="forgeekskeegfor";
    int n=s.length();
    longest_pallindrome_substring(s,n);
}
