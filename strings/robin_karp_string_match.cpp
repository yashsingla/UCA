//worst case time complexity:O(m*n);
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;

bool check(string s1,string s2,int m )
{  int i=0;
    while(i<m){
    if(s1[i]!=s2[i])
    return false;
    i++;
    }
    return true;
}

bool fun(string s,string p,int m,int n)
{
    int c=0;
    int prime=5;
    int x=0,y=0;
    int i;

    for(i=0;i<m;i++)
    {
       x=x+(int(s[i])*pow(prime,i));
      y=y+(int(p[i])*pow(prime,i));
    }
cout<<x<<" "<<y;

    if(y==x)
if(check(s,p.substr(i,m),m))
        c++;

                char ch=p[0];

    for(i=1;i<=(n-m);i++)
    {
        y=y-int(ch);
        y=y/prime;

        y=y+(int(p[i+m-1])*pow(prime,m-1));
       //cout<<"y:"<<y<<endl;
            if(y==x)
        if(check(s,p.substr(i,m),m))
                c++;
       ch=p[i];
    }

    if(c!=0)
    {
        cout<<"c:"<<c<<endl;
        return true;
    }
    else
        return false;

}

int main()
{
    string s="abc";
    string p="abedabc";

    int s1=s.size();
    int p1=p.size();

    if(fun(s,p,s1,p1))
        cout<<"Yes";
    else
        cout<<"No";
}
