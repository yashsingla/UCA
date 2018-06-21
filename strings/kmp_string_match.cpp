// also used to implement strstr function of c++
//time complexity: O(m+n) // m:size of substring ,n:size of string to be searched
//space complexity:O(m)

#include<iostream>
#include<math.h>
#include<limits.h>
#include<string.h>
using namespace std;
// table to calculate length of longest proper suffix which are also suffix
void prefixTable(int lps[],char p[],int m)
{
    int i=1,len=0;
    lps[0]=0;
    while(i<m)
    {
        if(p[i]==p[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
            if(len>0)
              len=lps[len-1];
          else{
           lps[i]=0;
           i++;
          }
    }
}

int kmp_search(char s[],int n,char p[],int m)
{
    int lps[m];
    prefixTable(lps,p,m);

   int i=0,j=0;
     while(i<n)
     {
         if(s[i]==p[j])
         {
             if(j==m-1)
                return i-j;
                else{
             i++;
             j++;
                }
         }
         else if(j>0)
            j=lps[j-1];
         else
            i++;
     }
return -1;
}

int main()
{
    char s[]="bacbabababacaca";
    int n=sizeof(s)/sizeof(s[0]);

    char p[]="ababa";
    int m=sizeof(p)/sizeof(p[0]);

     int x=kmp_search(s,n,p,m);
    if(x!=-1)
    cout<<"index of pattern in string is: "<<x;
}
