#include<iostream>
#include<cstdlib>
#include<map>
#include<string>

using namespace std;

string fun(string s)
{
    int n=s.length();
    char a[n];
    int i,j,k=0;
    map<char,int>m;

    for(i=0;i<n;i++)
    {
      if(m.find(s[i])==m.end())
           a[k++]=s[i];

      m[s[i]]++;
    }

    s="";

    for(i=0;i<k;i++)
    {
        s=s+a[i];

        s=s+char('0'+m[a[i]]);
    }
    return s;
}

int main()
{
    string s="wwwwaaadexxxx";

    cout<<"result:"<<fun(s);
}
