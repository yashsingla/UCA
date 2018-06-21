#include<iostream>
#include<string>
using namespace std;
string fun(string str)
{
    int n=str.length();
    int i;
    for(i=n;i>=0;i--)
        if(str[i]=='1')
        break;

    if(i==0)
    return '1'+str;

    int k;
   for(k=i-1;k>=0;k--)
   {
       if(str[k]=='0')
        str[k]='1';
       else
        str[k]='0';
   }
   return str;
}

int main()
{
    string s="10010";
    cout<<"Original String:"<<s<<endl;

    cout<<"2s-Compliment:"<<fun(s);
}
