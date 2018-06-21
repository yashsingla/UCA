#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int fun(string str, int k)
{
    int n= str.length();
    int cnt[26],len=0;
    int i,j;

    memset(cnt,0,sizeof(cnt));

    for(i=0;i<n;i++)
    {
        //memset(cnt,0,sizeof(cnt));
        int x=0,p;
        for(j=i;j<n;j++)
        {
            if(cnt[str[j]-'a']==0)
                   x++;

            cnt[str[j]-'a']++;

           if(x==k)
             len++;

            if(x>k)
              break;
        }

         for(p=i;p<=j;p++)  // this is optimization, rather than initializing "cnt" array everytime with zero, we can reduce the count of character
          cnt[str[p]-'a']--; // at the end of each iteration

    }
    return len;
}

int main()
{
    string str="geeks";
    int k=2;
   cout<<"number of substrings: "<<fun(str,k);
}
