//using recursion..here all substrings even of length-1 are counted
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool check_pallindrome(string str)
{
    int n=str.size();
    int i=0,j=n-1;

    while(i<=j)
    if(str[i++]!=str[j--])
    return false;

    return true;
}

int check(string str)
{
    int n=str.size();
    int i=0,j=n-1,x=0;
       if(n<=0)
        return x;

         if(i+1==j)
        return str[i]==str[j];
      else

        if(check_pallindrome(str.substr(i,n)))
       x=x+check(str.substr(i,n-1))+check(str.substr(i+1,n-1))+1-check(str.substr(i+1,n-2));
       else
       {
        x=x+check(str.substr(i,n-1))+check(str.substr(i+1,n-1))-check(str.substr(i+1,n-2));
       }
     return x;
}

int main()
{
    string str="abaab"; //{a,b,a,a,b,aba,aa,baab}
     int p=0;

   cout<<"count:"<<check(str);
}
